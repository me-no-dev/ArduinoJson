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

#ifndef ARDUINO
template <>
inline int64_t parse<int64_t>(const char *s) {
// Visual Studo 2012 didn't have strtoll
#if defined(_MSC_VER) && _MSC_VER <= 1700
  return _strtoi64(s, NULL, 10);
#else
  return strtoll(s, NULL, 10);
#endif
}
#endif
}
}
