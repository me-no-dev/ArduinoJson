// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

#include "IsSame.hpp"

#include <stdint.h>

namespace ArduinoJson {
namespace TypeTraits {
template <typename T>
struct IsIntegral {
  static const bool value = TypeTraits::IsSame<T, signed char>::value ||
                            TypeTraits::IsSame<T, unsigned char>::value ||
                            TypeTraits::IsSame<T, signed short>::value ||
                            TypeTraits::IsSame<T, unsigned short>::value ||
                            TypeTraits::IsSame<T, signed int>::value ||
                            TypeTraits::IsSame<T, unsigned int>::value ||
                            TypeTraits::IsSame<T, signed long>::value ||
                            TypeTraits::IsSame<T, unsigned long>::value ||
#ifndef ARDUINO
                            // on a computer add support for 64 bit
                            TypeTraits::IsSame<T, int64_t>::value ||
                            TypeTraits::IsSame<T, uint64_t>::value ||
#endif
                            TypeTraits::IsSame<T, char>::value;
};
}
}
