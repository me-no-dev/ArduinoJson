// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#pragma once

namespace ArduinoJson {
namespace TypeTraits {
template <typename T, typename U>
struct IsSame {
  static const bool value = false;
};

template <typename T>
struct IsSame<T, T> {
  static const bool value = true;
};
}
}
