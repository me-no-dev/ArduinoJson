// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

#include <stdlib.h>

namespace ArduinoJson {
namespace Internals {
template <typename TFloat>
TFloat parse(const char *);

template <>
inline float parse<float>(const char *s) {
  return static_cast<float>(strtod(s, NULL));
}

template <>
inline double parse<double>(const char *s) {
  return strtod(s, NULL);
}

template <>
inline long parse<long>(const char *s) {
  return strtol(s, NULL, 10);
}

template <>
inline int parse<int>(const char *s) {
  return atoi(s);
}

#ifdef ARDUINOJSON_ENABLE_LONG_LONG
template <>
inline long long parse<long long>(const char *s) {
  return strtoll(s, NULL, 10);
}
#endif
}
}
