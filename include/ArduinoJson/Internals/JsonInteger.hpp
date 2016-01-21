// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

#include <stdint.h>

namespace ArduinoJson {
namespace Internals {

#ifdef ARDUINO
// on an embedded system, choose what the compiler think is a long
typedef long JsonInteger;
#else
// on a computer, force 64 bit
typedef int64_t JsonInteger;
#endif
}
}
