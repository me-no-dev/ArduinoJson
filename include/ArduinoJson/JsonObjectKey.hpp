// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

#include "Arduino/String.hpp"

namespace ArduinoJson {

struct JsonObjectKey {
  JsonObjectKey(const char* key) : value(key), need_copy(false) {}
  JsonObjectKey(const String& key) : value(key.c_str()), need_copy(true) {}

  const char* value;
  const bool need_copy;
};
}
