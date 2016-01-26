// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

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
