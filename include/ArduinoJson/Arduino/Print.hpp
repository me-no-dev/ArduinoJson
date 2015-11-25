// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

#ifndef ARDUINO

#include <stddef.h>
#include <stdint.h>

// This class reproduces Arduino's Print class
class Print {
 public:
  virtual ~Print() {}

  virtual size_t write(uint8_t) = 0;

  size_t print(const char[]);
  size_t print(double, int = 2);
  size_t print(int16_t);
  size_t print(int32_t);
  size_t print(int64_t);
  size_t println();

 private:
  template <typename T>
  size_t printInteger(T value);
};

#else

#include <Print.h>

#endif
