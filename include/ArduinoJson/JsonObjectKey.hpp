// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

#include "Arduino/String.hpp"

namespace ArduinoJson {

class JsonObjectKey {
 public:
  JsonObjectKey(const char* key) : _value(key), _needs_copy(false) {}
  JsonObjectKey(const String& key) : _value(key.c_str()), _needs_copy(true) {}

  const char* c_str() const { return _value; }
  bool needs_copy() const { return _needs_copy; }

 private:
  const char* _value;
  bool _needs_copy;
};
}
