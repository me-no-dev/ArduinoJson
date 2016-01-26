// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#pragma once

namespace ArduinoJson {
namespace TypeTraits {
template <typename T>
struct RemoveReference {
  typedef T type;
};
template <typename T>
struct RemoveReference<T&> {
  typedef T type;
};
}
}
