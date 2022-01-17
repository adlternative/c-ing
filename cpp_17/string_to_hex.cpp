#include <charconv>
#include <gtest/gtest.h>
#include <optional>
#include <string>
#include <string_view>

std::optional<int> to_int(const std::string_view &input) {
  unsigned int out;
  const std::from_chars_result result =
      std::from_chars(input.data(), input.data() + input.size(), out, 16);
  if (result.ec == std::errc::invalid_argument ||
      result.ec == std::errc::result_out_of_range) {
    return std::nullopt;
  }
  return out;
}

TEST(string_view, to_int) {
  std::string str{"2A"};
  auto ret = to_int(str);
  EXPECT_EQ(ret.value(), 42);
}