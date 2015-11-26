// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

namespace ArduinoJson {
namespace Internals {
template <typename T>
struct EnableIfFloatingPoint {};
template <>
struct EnableIfFloatingPoint<float> {
  typedef float type;
};
template <>
struct EnableIfFloatingPoint<double> {
  typedef double type;
};
}
}
