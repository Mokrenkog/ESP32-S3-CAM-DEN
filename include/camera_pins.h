#pragma once

#include <Arduino.h>

/*
  ESP32-S3-SPK / ESP32-S3 N16R8 + OV2640 camera pin preset.

  Board marks visible on the photo:
  - "ESP32-S3-SPK"
  - "N16R8"
  - OV2640 camera module

  The pins match the public ESPHome configuration shared for this AliExpress
  ESP32-S3 camera/speaker board family.
*/

#if defined(CAMERA_MODEL_ESP32_S3_SPK_OV2640)

#define CAMERA_PIN_PWDN -1
#define CAMERA_PIN_RESET -1
#define CAMERA_PIN_XCLK 33
#define CAMERA_PIN_SIOD 37
#define CAMERA_PIN_SIOC 36

#define CAMERA_PIN_Y2 7
#define CAMERA_PIN_Y3 5
#define CAMERA_PIN_Y4 4
#define CAMERA_PIN_Y5 6
#define CAMERA_PIN_Y6 8
#define CAMERA_PIN_Y7 42
#define CAMERA_PIN_Y8 48
#define CAMERA_PIN_Y9 47
#define CAMERA_PIN_VSYNC 35
#define CAMERA_PIN_HREF 34
#define CAMERA_PIN_PCLK 41

#define CAMERA_PINSET_NAME "ESP32-S3-SPK N16R8 OV2640"

#else

#error "Select a camera preset in platformio.ini build_flags."

#endif
