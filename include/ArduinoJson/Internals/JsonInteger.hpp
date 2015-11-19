// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

namespace ArduinoJson {
namespace Internals {
#ifdef ARDUINO
typedef long JsonInteger;
#else
typedef long long JsonInteger;
#endif
}
}
