// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

#include <stdint.h>

namespace ArduinoJson {
namespace TypeTraits {
template <typename T>
struct IsIntegral {
  static const bool value = false;
};
template <>
struct IsIntegral<char> {
  static const bool value = true;
};
template <>
struct IsIntegral<signed char> {
  static const bool value = true;
};
template <>
struct IsIntegral<signed short> {
  static const bool value = true;
};
template <>
struct IsIntegral<signed int> {
  static const bool value = true;
};
template <>
struct IsIntegral<signed long> {
  static const bool value = true;
};
template <>
struct IsIntegral<unsigned char> {
  static const bool value = true;
};
template <>
struct IsIntegral<unsigned short> {
  static const bool value = true;
};
template <>
struct IsIntegral<unsigned int> {
  static const bool value = true;
};
template <>
struct IsIntegral<unsigned long> {
  static const bool value = true;
};

#ifdef ARDUINOJSON_COMPILER_SUPPORTS_LONG_LONG
template <>
struct IsIntegral<long long> {
  static const bool value = true;
};
template <>
struct IsIntegral<unsigned long long> {
  static const bool value = true;
};
#endif
}
}
