// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

namespace ArduinoJson {
namespace Internals {
template <typename T>
struct EnableIfIntegral {};
template <>
struct EnableIfIntegral<char> {
  typedef char type;
};
template <>
struct EnableIfIntegral<signed char> {
  typedef signed char type;
};
template <>
struct EnableIfIntegral<signed short> {
  typedef signed short type;
};
template <>
struct EnableIfIntegral<signed int> {
  typedef signed int type;
};
template <>
struct EnableIfIntegral<signed long> {
  typedef signed long type;
};
template <>
struct EnableIfIntegral<unsigned char> {
  typedef unsigned char type;
};
template <>
struct EnableIfIntegral<unsigned short> {
  typedef unsigned short type;
};
template <>
struct EnableIfIntegral<unsigned int> {
  typedef unsigned int type;
};
template <>
struct EnableIfIntegral<unsigned long> {
  typedef unsigned long type;
};
}
}
