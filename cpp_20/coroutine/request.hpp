//
// request.hpp
// ~~~~~~~~~~~
//
// Copyright (c) 2003-2021 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HTTP_SERVER4_REQUEST_HPP
#define HTTP_SERVER4_REQUEST_HPP

#include "header.hpp"
#include <string>
#include <vector>

/// A request received from a client.
struct request {
  /// The request method, e.g. "GET", "POST".
  std::string method;

  /// The requested URI, such as a path to a file.
  std::string uri;

  /// Major version number, usually 1.
  int http_version_major;

  /// Minor version number, usually 0 or 1.
  int http_version_minor;

  /// The headers included with the request.
  std::vector<header> headers;

  /// The optional content sent with the request.
  std::string content;

  void clear() {
    method.clear();
    uri.clear();
    http_version_major = 0;
    http_version_minor = 0;
    headers.clear();
    content.clear();
  }
};

#endif // HTTP_SERVER4_REQUEST_HPP
