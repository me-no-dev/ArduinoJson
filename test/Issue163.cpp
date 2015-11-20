// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#include <gtest/gtest.h>
#include <ArduinoJson.h>

TEST(Issue163, NumberWithNoDecimalPoint) {
  DynamicJsonBuffer jsonBuffer;
  char json[] = "{'val':14}";
  JsonObject &root = jsonBuffer.parseObject(json);
  ASSERT_EQ(14.0, root["val"].as<double>());
}
