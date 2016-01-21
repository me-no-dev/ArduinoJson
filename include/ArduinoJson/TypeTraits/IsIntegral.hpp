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

#ifndef ARDUINO
// on a computer add support for 64 bit
template <>
struct IsIntegral<int64_t> {
  static const bool value = true;
};
template <>
struct IsIntegral<uint64_t> {
  static const bool value = true;
};
#endif
}
}
