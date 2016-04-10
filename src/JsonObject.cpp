// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#include "../include/ArduinoJson/JsonObject.hpp"

#include <string.h>  // for strcmp

#include "../include/ArduinoJson/Internals/StaticStringBuilder.hpp"
#include "../include/ArduinoJson/JsonArray.hpp"
#include "../include/ArduinoJson/JsonBuffer.hpp"

using namespace ArduinoJson;
using namespace ArduinoJson::Internals;

JsonObject JsonObject::_invalid(NULL);

JsonObject::node_type *JsonObject::getNodeAt(const char *key) const {
  for (node_type *node = _firstNode; node; node = node->next) {
    if (!strcmp(node->content.key, key)) return node;
  }
  return NULL;
}

size_t JsonObject::writeTo(JsonWriter &writer) const {
  size_t written = 0;
  if((written = writer.beginObject()) == 0)
    return 0;

  const node_type *node = _firstNode;
  size_t total = written;
  while (node) {
    if((written = writer.writeString(node->content.key)) == 0)
      break;
    total += written;
    if((written = writer.writeColon()) == 0)
      break;
    total += written;
    if((written = node->content.value.writeTo(writer)) == 0)
      break;
    total += written;

    node = node->next;
    if (!node) break;

    if((written = writer.writeComma()) == 0)
      break;
    total += written;
  }

  if(written)
    total += writer.endObject();
  return total;
}
