// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

#include "JsonVariant.hpp"

namespace ArduinoJson {

inline JsonVariant::JsonVariant(bool value) {
  using namespace Internals;
  _type = JSON_BOOLEAN;
  _content.asInteger = static_cast<JsonInteger>(value);
}

inline JsonVariant::JsonVariant(const char *value) {
  _type = Internals::JSON_STRING;
  _content.asString = value;
}

inline JsonVariant::JsonVariant(Internals::Unparsed value) {
  _type = Internals::JSON_UNPARSED;
  _content.asString = value;
}

inline JsonVariant::JsonVariant(double value, uint8_t decimals) {
  using namespace Internals;
  _type = static_cast<JsonVariantType>(JSON_FLOAT_0_DECIMALS + decimals);
  _content.asFloat = static_cast<JsonFloat>(value);
}

inline JsonVariant::JsonVariant(float value, uint8_t decimals) {
  using namespace Internals;
  _type = static_cast<JsonVariantType>(JSON_FLOAT_0_DECIMALS + decimals);
  _content.asFloat = static_cast<JsonFloat>(value);
}

inline JsonVariant::JsonVariant(JsonArray &array) {
  _type = Internals::JSON_ARRAY;
  _content.asArray = &array;
}

inline JsonVariant::JsonVariant(JsonObject &object) {
  _type = Internals::JSON_OBJECT;
  _content.asObject = &object;
}

inline JsonVariant::JsonVariant(int8_t value) {
  using namespace Internals;
  _type = JSON_INTEGER;
  _content.asInteger = static_cast<JsonInteger>(value);
}

inline JsonVariant::JsonVariant(int16_t value) {
  using namespace Internals;
  _type = JSON_INTEGER;
  _content.asInteger = static_cast<JsonInteger>(value);
}

inline JsonVariant::JsonVariant(int32_t value) {
  using namespace Internals;
  _type = JSON_INTEGER;
  _content.asInteger = static_cast<JsonInteger>(value);
}

inline JsonVariant::JsonVariant(int64_t value) {
  using namespace Internals;
  _type = JSON_INTEGER;
  _content.asInteger = static_cast<JsonInteger>(value);
}

inline JsonVariant::JsonVariant(uint8_t value) {
  using namespace Internals;
  _type = JSON_INTEGER;
  _content.asInteger = static_cast<JsonInteger>(value);
}

inline JsonVariant::JsonVariant(uint16_t value) {
  using namespace Internals;
  _type = JSON_INTEGER;
  _content.asInteger = static_cast<JsonInteger>(value);
}

inline JsonVariant::JsonVariant(uint32_t value) {
  using namespace Internals;
  _type = JSON_INTEGER;
  _content.asInteger = static_cast<JsonInteger>(value);
}

inline JsonVariant::JsonVariant(uint64_t value) {
  using namespace Internals;
  _type = JSON_INTEGER;
  _content.asInteger = static_cast<JsonInteger>(value);
}

template <>
String JsonVariant::as<String>() const;

template <>
const char *JsonVariant::as<const char *>() const;

template <>
inline bool JsonVariant::as<bool>() const {
  return asInteger() != 0;
}

template <>
inline int8_t JsonVariant::as<int8_t>() const {
  return static_cast<int8_t>(asInteger());
}

template <>
inline int16_t JsonVariant::as<int16_t>() const {
  return static_cast<int16_t>(asInteger());
}

template <>
inline int32_t JsonVariant::as<int32_t>() const {
  return static_cast<int32_t>(asInteger());
}

template <>
inline int64_t JsonVariant::as<int64_t>() const {
  return static_cast<int64_t>(asInteger());
}

template <>
inline uint8_t JsonVariant::as<uint8_t>() const {
  return static_cast<uint8_t>(asInteger());
}

template <>
inline uint16_t JsonVariant::as<uint16_t>() const {
  return static_cast<uint16_t>(asInteger());
}

template <>
inline uint32_t JsonVariant::as<uint32_t>() const {
  return static_cast<uint32_t>(asInteger());
}

template <>
inline uint64_t JsonVariant::as<uint64_t>() const {
  return static_cast<uint64_t>(asInteger());
}

template <>
inline double JsonVariant::as<double>() const {
  return static_cast<double>(asFloat());
}

template <>
inline float JsonVariant::as<float>() const {
  return static_cast<float>(asFloat());
}

template <typename T>
inline T JsonVariant::invalid() {
  return T();
}

template <typename T>
inline bool JsonVariant::is() const {
  return false;
}

template <>  // in .cpp
bool JsonVariant::is<double>() const;

template <>
inline bool JsonVariant::is<bool>() const {
  return _type == Internals::JSON_BOOLEAN;
}

template <>
inline bool JsonVariant::is<char const *>() const {
  return _type == Internals::JSON_STRING;
}

template <>
inline bool JsonVariant::is<float>() const {
  return is<double>();
}

template <>
inline bool JsonVariant::is<JsonArray &>() const {
  return _type == Internals::JSON_ARRAY;
}

template <>
inline bool JsonVariant::is<JsonArray const &>() const {
  return _type == Internals::JSON_ARRAY;
}

template <>
inline bool JsonVariant::is<JsonObject &>() const {
  return _type == Internals::JSON_OBJECT;
}

template <>
inline bool JsonVariant::is<JsonObject const &>() const {
  return _type == Internals::JSON_OBJECT;
}

template <>
inline bool JsonVariant::is<signed char>() const {
  return isInteger();
}

template <>
inline bool JsonVariant::is<signed int>() const {
  return isInteger();
}

template <>
inline bool JsonVariant::is<signed long>() const {
  return isInteger();
}

template <>
inline bool JsonVariant::is<int64_t>() const {
  return isInteger();
}

template <>
inline bool JsonVariant::is<signed short>() const {
  return isInteger();
}

template <>
inline bool JsonVariant::is<unsigned char>() const {
  return isInteger();
}

template <>
inline bool JsonVariant::is<unsigned int>() const {
  return isInteger();
}

template <>
inline bool JsonVariant::is<unsigned long>() const {
  return isInteger();
}

template <>
inline bool JsonVariant::is<uint64_t>() const {
  return isInteger();
}

template <>
inline bool JsonVariant::is<unsigned short>() const {
  return isInteger();
}

#ifdef ARDUINOJSON_ENABLE_STD_STREAM
inline std::ostream &operator<<(std::ostream &os, const JsonVariant &source) {
  return source.printTo(os);
}
#endif

}  // namespace ArduinoJson
