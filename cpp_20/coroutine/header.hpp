//
// header.hpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2021 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HTTP_SERVER4_HEADER_HPP
#define HTTP_SERVER4_HEADER_HPP

#include <string>

struct header {
  std::string name;
  std::string value;
};

#endif // HTTP_SERVER4_HEADER_HPP
