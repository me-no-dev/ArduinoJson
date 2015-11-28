// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

namespace ArduinoJson {
namespace Internals {
template <class T, class U>
struct EnableIfSame {};

template <class T>
struct EnableIfSame<const T, T> {
  typedef T type;
};

template <class T>
struct EnableIfSame<T, T> {
  typedef T type;
};
}
}
