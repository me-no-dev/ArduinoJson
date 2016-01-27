// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#pragma once

#include "JsonVariantBase.hpp"

namespace ArduinoJson {

template <typename TImpl>
class JsonSubscriptBase : public JsonVariantBase<TImpl> {
 public:
  FORCE_INLINE TImpl& operator=(const String& value) {
    return assign<const String&>(value);
  }

  FORCE_INLINE TImpl& operator=(JsonArray& array) {
    return assign<JsonArray&>(array);
  }

  FORCE_INLINE TImpl& operator=(JsonObject& object) {
    return assign<JsonObject&>(object);
  }

  FORCE_INLINE TImpl& operator=(JsonVariant value) {
    return assign<const JsonVariant&>(value);
  }

 protected:
  template <typename TValue>
  FORCE_INLINE TImpl& assign(TValue value) {
    TImpl* that = static_cast<TImpl*>(this);
    that->template set<TValue>(value);
    return *that;
  }
};
}
