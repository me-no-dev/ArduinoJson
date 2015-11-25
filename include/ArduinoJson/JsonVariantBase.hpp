// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

#include "Internals/ForceInline.hpp"
#include "JsonObjectKey.hpp"

namespace ArduinoJson {

// Forward declarations.
class JsonArraySubscript;
template <typename TKey>
class JsonObjectSubscript;

template <typename TImpl>
class JsonVariantBase : public Internals::JsonPrintable<TImpl> {
 public:
  // Gets the variant as a boolean value.
  // Returns false if the variant is not a boolean value.
  FORCE_INLINE operator bool() const { return as<bool>(); }

  // Gets the variant as a floating-point value.
  // Returns 0.0 if the variant is not a floating-point value
  FORCE_INLINE operator double() const { return as<double>(); }
  FORCE_INLINE operator float() const { return as<float>(); }

  // Gets the variant as an integer value.
  // Returns 0 if the variant is not an integer value.
  FORCE_INLINE operator int8_t() const { return as<int8_t>(); }
  FORCE_INLINE operator int16_t() const { return as<int16_t>(); }
  FORCE_INLINE operator int32_t() const { return as<int32_t>(); }
  FORCE_INLINE operator int64_t() const { return as<int64_t>(); }
  FORCE_INLINE operator uint8_t() const { return as<uint8_t>(); }
  FORCE_INLINE operator uint16_t() const { return as<uint16_t>(); }
  FORCE_INLINE operator uint32_t() const { return as<uint32_t>(); }
  FORCE_INLINE operator uint64_t() const { return as<uint64_t>(); }

  // Gets the variant as a string.
  // Returns NULL if variant is not a string.
  FORCE_INLINE operator const char *() const { return as<const char *>(); }
  FORCE_INLINE const char *asString() const { return as<const char *>(); }
  FORCE_INLINE operator String() const { return as<String>(); }

  // Gets the variant as an array.
  // Returns a reference to the JsonArray or JsonArray::invalid() if the
  // variant
  // is not an array.
  FORCE_INLINE operator JsonArray &() const { return as<JsonArray &>(); }
  FORCE_INLINE JsonArray &asArray() const { return as<JsonArray &>(); }

  // Gets the variant as an object.
  // Returns a reference to the JsonObject or JsonObject::invalid() if the
  // variant is not an object.
  FORCE_INLINE operator JsonObject &() const { return as<JsonObject &>(); }
  FORCE_INLINE JsonObject &asObject() const { return as<JsonObject &>(); }

  template <typename T>
  FORCE_INLINE const T as() const {
    return impl()->template as<T>();
  }

  // Mimics an array or an object.
  // Returns the size of the array or object if the variant has that type.
  // Returns 0 if the variant is neither an array nor an object
  size_t size() const { return asArray().size() + asObject().size(); }

  // Mimics an array.
  // Returns the element at specified index if the variant is an array.
  // Returns JsonVariant::invalid() if the variant is not an array.
  FORCE_INLINE const JsonArraySubscript operator[](int index) const;

  // Mimics an object.
  // Returns the value associated with the specified key if the variant is
  // an object.
  // Return JsonVariant::invalid() if the variant is not an object.
  FORCE_INLINE const JsonObjectSubscript<const char *> operator[](
      const char *key) const;
  FORCE_INLINE const JsonObjectSubscript<const String &> operator[](
      const String &key) const;

  // Serialize the variant to a JsonWriter
  void writeTo(Internals::JsonWriter &writer) const;

 private:
  const TImpl *impl() const { return static_cast<const TImpl *>(this); }
};

template <typename TImpl, typename TComparand>
inline bool operator==(const JsonVariantBase<TImpl> &left, TComparand right) {
  return left.template as<TComparand>() == right;
}

template <typename TImpl, typename TComparand>
inline bool operator==(TComparand left, const JsonVariantBase<TImpl> &right) {
  return left == right.template as<TComparand>();
}

template <typename TImpl, typename TComparand>
inline bool operator!=(const JsonVariantBase<TImpl> &left, TComparand right) {
  return left.template as<TComparand>() != right;
}

template <typename TImpl, typename TComparand>
inline bool operator!=(TComparand left, const JsonVariantBase<TImpl> &right) {
  return left != right.template as<TComparand>();
}

template <typename TImpl, typename TComparand>
inline bool operator<=(const JsonVariantBase<TImpl> &left, TComparand right) {
  return left.template as<TComparand>() <= right;
}

template <typename TImpl, typename TComparand>
inline bool operator<=(TComparand left, const JsonVariantBase<TImpl> &right) {
  return left <= right.template as<TComparand>();
}

template <typename TImpl, typename TComparand>
inline bool operator>=(const JsonVariantBase<TImpl> &left, TComparand right) {
  return left.template as<TComparand>() >= right;
}

template <typename TImpl, typename TComparand>
inline bool operator>=(TComparand left, const JsonVariantBase<TImpl> &right) {
  return left >= right.template as<TComparand>();
}

template <typename TImpl, typename TComparand>
inline bool operator<(const JsonVariantBase<TImpl> &left, TComparand right) {
  return left.template as<TComparand>() < right;
}

template <typename TImpl, typename TComparand>
inline bool operator<(TComparand left, const JsonVariantBase<TImpl> &right) {
  return left < right.template as<TComparand>();
}

template <typename TImpl, typename TComparand>
inline bool operator>(const JsonVariantBase<TImpl> &left, TComparand right) {
  return left.template as<TComparand>() > right;
}

template <typename TImpl, typename TComparand>
inline bool operator>(TComparand left, const JsonVariantBase<TImpl> &right) {
  return left > right.template as<TComparand>();
}
}
