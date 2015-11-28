// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

namespace ArduinoJson {
namespace TypeTraits {
template <bool Condition, typename T>
struct EnableIf {};

template <typename T>
struct EnableIf<true, T> {
  typedef T type;
};
}
}
