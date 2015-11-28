// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

namespace ArduinoJson {
namespace TypeTraits {
template <typename T>
struct IsFloatingPoint {
  static const bool value = false;
};
template <>
struct IsFloatingPoint<float> {
  static const bool value = true;
};
template <>
struct IsFloatingPoint<double> {
  static const bool value = true;
};
}
}
