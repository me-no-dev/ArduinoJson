// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

#ifndef ARDUINO

#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>  // for sprintf()

// This class reproduces Arduino's Print class
class Print {
 public:
  virtual ~Print() {}

  virtual size_t write(uint8_t) = 0;

  size_t print(const char[]);
  size_t print(double, int = 2);
  size_t print(int);
  size_t print(long);

#ifndef ARDUINO
  // on a computer, add support for 64 bit
  size_t print(int64_t value) {
    char tmp[32];
    sprintf(tmp, "%" PRId64, value);
    return print(tmp);
  }
#endif

  size_t println();
};

#else

#include <Print.h>

#endif
