// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

#include "CompilerFeatures.hpp"

namespace ArduinoJson {
namespace Internals {
#ifdef ARDUINOJSON_COMPILER_SUPPORTS_LONG_LONG
typedef long long JsonInteger;
#else
typedef long JsonInteger;
#endif
}
}
