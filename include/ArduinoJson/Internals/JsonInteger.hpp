// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

#include "../Configuration.hpp"

namespace ArduinoJson {
namespace Internals {

#if ARDUINOJSON_USE_LONG_LONG
typedef long long JsonInteger;
#elif ARDUINOJSON_USE_INT64
typedef __int64 JsonInteger;
#else
typedef long JsonInteger;
#endif
}
}
