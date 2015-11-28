// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

namespace ArduinoJson {
namespace TypeTraits {
template <typename T>
struct RemoveConst {
  typedef T type;
};
template <typename T>
struct RemoveConst<const T> {
  typedef T type;
};
}
}
