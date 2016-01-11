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
inline bool JsonObject::set(const char *key, const String &value) {
  return setNodeAt<const String &>(key, value);
}
inline bool JsonObject::set(const char *key, JsonArray &array) {
  return setNodeAt<JsonArray &>(key, array);
}
inline bool JsonObject::set(const char *key, JsonObject &object) {
  return setNodeAt<JsonObject &>(key, object);
}
inline bool JsonObject::set(const char *key, const JsonVariant &value) {
  return setNodeAt<const JsonVariant &>(key, value);
}
template <typename T>
inline bool JsonObject::set(const char *key, const T &value) {
  return setNodeAt<JsonVariant>(key, value);
}
inline bool JsonObject::set(const String &key, const String &value) {
  return setNodeAt<const String &>(key, value);
}
inline bool JsonObject::set(const String &key, JsonArray &array) {
  return setNodeAt<JsonArray &>(key, array);
}
inline bool JsonObject::set(const String &key, JsonObject &object) {
  return setNodeAt<JsonObject &>(key, object);
}
inline bool JsonObject::set(const String &key, const JsonVariant &value) {
  return setNodeAt<const JsonVariant &>(key, value);
}
template <typename T>
inline bool JsonObject::set(const String &key, const T &value) {
  return setNodeAt<JsonVariant>(key, value);
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

  setNodeValue<T>(node, value);
  return true;
}

template <typename TValue>
inline void JsonObject::setNodeValue(node_type *node, TValue value) {
  node->content.value = value;
}

template <>
inline void JsonObject::setNodeValue(node_type *node, const String &value) {
  node->content.value = _buffer->strdup(value);
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
