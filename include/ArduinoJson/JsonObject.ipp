// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

#include "JsonObject.hpp"
#include "JsonObjectSubscript.hpp"

namespace ArduinoJson {

inline JsonVariant JsonObject::get(JsonObjectKey key) const {
  node_type *node = getNodeAt(key.value);
  return node ? node->content.value : JsonVariant();
}

template <typename T>
inline T JsonObject::get(JsonObjectKey key) const {
  node_type *node = getNodeAt(key.value);
  return node ? node->content.value.as<T>() : JsonVariant::invalid<T>();
}

template <typename T>
inline bool JsonObject::is(JsonObjectKey key) const {
  node_type *node = getNodeAt(key.value);
  return node ? node->content.value.is<T>() : false;
}

inline JsonObjectSubscript<const char *> JsonObject::operator[](
    const char *key) {
  return JsonObjectSubscript<const char *>(*this, key);
}

inline JsonObjectSubscript<const String &> JsonObject::operator[](
    const String &key) {
  return JsonObjectSubscript<const String &>(*this, key);
}

inline JsonVariant JsonObject::operator[](JsonObjectKey key) const {
  return get(key);
}

inline bool JsonObject::containsKey(JsonObjectKey key) const {
  return getNodeAt(key.value) != NULL;
}

inline void JsonObject::remove(JsonObjectKey key) {
  removeNode(getNodeAt(key.value));
}

template <typename T>
inline bool JsonObject::setNodeAt(JsonObjectKey key, T value) {
  node_type *node = getNodeAt(key.value);

  if (!node) {
    node = addNewNode();
    if (!node) return false;
  }

  if (key.need_copy) {
    node->content.key = _buffer->strdup(key.value);
    if (node->content.key == NULL) return false;
  } else {
    node->content.key = key.value;
  }

  return setNodeValue<T>(node, value);
}

template <typename TValue>
inline bool JsonObject::setNodeValue(node_type *node, TValue value) {
  node->content.value = value;
  return true;
}

template <>
inline bool JsonObject::setNodeValue(node_type *node, String &value) {
  node->content.value = _buffer->strdup(value);
  return node->content.value;
}

template <>
inline bool JsonObject::setNodeValue(node_type *node, const String &value) {
  node->content.value = _buffer->strdup(value);
  return node->content.value;
}

template <typename TImplem>
inline const JsonObjectSubscript<const char *> JsonVariantBase<TImplem>::
operator[](const char *key) const {
  return asObject()[key];
}

template <typename TImplem>
inline const JsonObjectSubscript<const String &> JsonVariantBase<TImplem>::
operator[](const String &key) const {
  return asObject()[key];
}

template <>
inline JsonObject const &JsonVariant::invalid<JsonObject const &>() {
  return JsonObject::invalid();
}

template <>
inline JsonObject &JsonVariant::invalid<JsonObject &>() {
  return JsonObject::invalid();
}

inline JsonObject &JsonVariant::asObject() const {
  if (_type == Internals::JSON_OBJECT) return *_content.asObject;
  return JsonObject::invalid();
}
}
