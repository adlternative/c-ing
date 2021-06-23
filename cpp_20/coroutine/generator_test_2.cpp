#include "generator_input_output2.hpp"
#include "request.hpp"
#include <boost/lexical_cast.hpp>
#include <memory>
#include <tuple>
class request_parser {

public:
  enum status {
    ok = 0,
    indeterminate = 1,
    fail = -1,
  };

  using request_ptr = std::shared_ptr<request>;

  request_parser()
      : req_(std::make_shared<request>()), running(false), content_length_(0),
        h(consume(req_)) {
    /* 从 init 恢复协程（协程马上调用 await 返回并等待值） */
    assert(h.next());
  }

  template <typename Iterator>
  std::tuple<status, Iterator> parse(Iterator begin, Iterator end) {
    running = true;
    while (begin != end) {
      // std::cout << *begin << std::endl;
      h.send(*begin++);
      /* 协程final了（尽管这里是不可能的情况） */
      if (!h.next())
        break;
      auto result = h.value();
      if ((result == ok) || (result == fail))
        return std::make_tuple(result, begin);
    }
    return std::make_tuple(indeterminate, begin);
  }
  generator<status, char> consume(request_ptr &req) {
    char c = co_await generator<status, char>::generator_input{};
    while (1) {
      // Request method.
      while (is_char(c) && !is_ctl(c) && !is_tspecial(c) && c != ' ') {
        req->method.push_back(c);
        c = co_yield indeterminate;
      }
      if (req->method.empty()) {
        c = co_yield fail;
        goto parse_end;
      }

      // Space.
      if (c != ' ') {
        c = co_yield fail;
        goto parse_end;
      }
      c = co_yield indeterminate;

      // URI.
      while (!is_ctl(c) && c != ' ') {
        req->uri.push_back(c);
        c = co_yield indeterminate;
      }
      if (req->uri.empty()) {
        c = co_yield fail;
        goto parse_end;
      }

      // Space.
      if (c != ' ') {
        c = co_yield fail;
        goto parse_end;
      }
      c = co_yield indeterminate;

      // HTTP protocol identifier.
      if (c != 'H') {
        c = co_yield fail;
        goto parse_end;
      }
      c = co_yield indeterminate;
      if (c != 'T') {
        c = co_yield fail;
        goto parse_end;
      }
      c = co_yield indeterminate;
      if (c != 'T') {
        c = co_yield fail;
        goto parse_end;
      }
      c = co_yield indeterminate;
      if (c != 'P') {
        c = co_yield fail;
        goto parse_end;
      }
      c = co_yield indeterminate;

      // Slash.
      if (c != '/') {
        c = co_yield fail;
        goto parse_end;
      }
      c = co_yield indeterminate;

      // Major version number.
      if (!is_digit(c)) {
        c = co_yield fail;
        goto parse_end;
      }
      while (is_digit(c)) {
        req->http_version_major = req->http_version_major * 10 + c - '0';
        c = co_yield indeterminate;
      }

      // Dot.
      if (c != '.') {
        c = co_yield fail;
        goto parse_end;
      }
      c = co_yield indeterminate;

      // Minor version number.
      if (!is_digit(c)) {
        c = co_yield fail;
        goto parse_end;
      }
      while (is_digit(c)) {
        req->http_version_minor = req->http_version_minor * 10 + c - '0';
        c = co_yield indeterminate;
      }

      // CRLF.
      if (c != '\r') {
        c = co_yield fail;
        goto parse_end;
      }
      c = co_yield indeterminate;
      if (c != '\n') {
        c = co_yield fail;
        goto parse_end;
      }
      c = co_yield indeterminate;

      // Headers.
      while ((is_char(c) && !is_ctl(c) && !is_tspecial(c) && c != '\r') ||
             (c == ' ' || c == '\t')) {
        if (c == ' ' || c == '\t') {
          // Leading whitespace. Must be continuation of previous header's
          // value.
          if (req->headers.empty()) {
            c = co_yield fail;
            goto parse_end;
          }
          while (c == ' ' || c == '\t')
            c = co_yield indeterminate;
        } else {
          // Start the next header.
          req->headers.push_back(header());

          // Header name.
          while (is_char(c) && !is_ctl(c) && !is_tspecial(c) && c != ':') {
            req->headers.back().name.push_back(c);
            c = co_yield indeterminate;
          }

          // Colon and space separates the header name from the header value.
          if (c != ':') {
            c = co_yield fail;
            goto parse_end;
          }
          c = co_yield indeterminate;
          if (c != ' ') {
            c = co_yield fail;
            goto parse_end;
          }
          c = co_yield indeterminate;
        }

        // Header value.
        while (is_char(c) && !is_ctl(c) && c != '\r') {
          req->headers.back().value.push_back(c);
          c = co_yield indeterminate;
        }

        // CRLF.
        if (c != '\r') {
          c = co_yield fail;
          goto parse_end;
        }
        c = co_yield indeterminate;
        if (c != '\n') {
          c = co_yield fail;
          goto parse_end;
        }
        c = co_yield indeterminate;
      }

      // CRLF.
      if (c != '\r') {
        c = co_yield fail;
        goto parse_end;
      }
      c = co_yield indeterminate;
      if (c != '\n') {
        c = co_yield fail;
        goto parse_end;
      }

      // Check for optional Content-Length header.
      for (std::size_t i = 0; i < req->headers.size(); ++i) {
        if (headers_equal(req->headers[i].name, content_length_name_)) {
          try {
            content_length_ =
                boost::lexical_cast<std::size_t>(req->headers[i].value);
          } catch (boost::bad_lexical_cast &) {
            {
              c = co_yield fail;
              goto parse_end;
            }
          }
        }
      }

      // Content.
      while (req->content.size() < content_length_) {
        c = co_yield indeterminate;
        req->content.push_back(c);
      }
      c = co_yield ok;
    parse_end:
      continue;
    }
    /* 不会到这 */
    co_return;
  }

  request_ptr handle(std::string src) {
    // status sta;
    auto [sta, i] = parse(src.begin(), src.end());
    if (sta == fail) {
      std::cout << "fail" << std::endl;
      req_.reset();
      exit(1);
      return request_ptr();
    } else if (sta == ok) {
      auto temp = std::make_shared<request>();
      std::cout << "ok" << std::endl;
      req_.swap(temp);
      content_length_ = 0;
      return temp;
    } else {
      std::cout << "wait... " << std::endl;
      return request_ptr();
    }
  }

  /// Check if a byte is an HTTP character.
  static bool is_char(int c);

  /// Check if a byte is an HTTP control character.
  static bool is_ctl(int c);

  /// Check if a byte is defined as an HTTP tspecial character.
  static bool is_tspecial(int c);

  /// Check if a byte is a digit.
  static bool is_digit(int c);

  /// Check if two characters are equal, without regard to case.
  static bool tolower_compare(char a, char b);

  /// Check whether the two request header names match.
  bool headers_equal(const std::string &a, const std::string &b);

private:
  bool running;

  generator<status, char> h;

  request_ptr req_;
  static std::string content_length_name_;
  /// Content length as decoded from headers. Defaults to 0.
  std::size_t content_length_;
};
std::string request_parser::content_length_name_ = "Content-Length";

bool request_parser::is_char(int c) { return c >= 0 && c <= 127; }

bool request_parser::is_ctl(int c) { return (c >= 0 && c <= 31) || (c == 127); }

bool request_parser::is_tspecial(int c) {
  switch (c) {
  case '(':
  case ')':
  case '<':
  case '>':
  case '@':
  case ',':
  case ';':
  case ':':
  case '\\':
  case '"':
  case '/':
  case '[':
  case ']':
  case '?':
  case '=':
  case '{':
  case '}':
  case ' ':
  case '\t':
    return true;
  default:
    return false;
  }
}

bool request_parser::is_digit(int c) { return c >= '0' && c <= '9'; }

bool request_parser::tolower_compare(char a, char b) {
  return std::tolower(a) == std::tolower(b);
}

bool request_parser::headers_equal(const std::string &a, const std::string &b) {
  if (a.length() != b.length())
    return false;

  return std::equal(a.begin(), a.end(), b.begin(),
                    &request_parser::tolower_compare);
}

void handle_request(const request_parser::request_ptr &ptr) { /* do */
  std::cout << __func__ << std::endl;
}

void parse_request_and_handle_request(request_parser &rp, std::string &&s) {
  auto result = rp.handle(s);
  if (result) {
    handle_request(result);
    return;
  }
}

std::vector<std::string> get_the_input() {
  return std::vector<std::string>{
      {
          "GET / HTTP/1.0\r\n",
          "Host: Chrome\r\n",
          "KeepAlive: true\r\n",
          "\r\n",
          "POST / HTTP/1.0\r\n",
          "Host: Chrome\r\n",
          "KeepAlive: false\r\n",
          "Content-length: 3\r\n",
          "\r\n",
          "abc\r\n",
      },
  };
}

void main2() {
  request req;
  request_parser rp;
  for (auto &&s : get_the_input()) {
    auto result = rp.handle(s);
    if (result) {
      handle_request(result);
    }
  }
}

int main(int, char **) { main2(); }
