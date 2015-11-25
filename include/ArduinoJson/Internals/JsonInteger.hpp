// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

// NOTE: Arduino doesn't include the C++ version <cstdint>
#include <stdint.h>

namespace ArduinoJson {
namespace Internals {
#ifdef ARDUINO
typedef int32_t JsonInteger;
#else
typedef int64_t JsonInteger;
#endif
}
}
