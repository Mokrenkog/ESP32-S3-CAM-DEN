#pragma once

#include <Arduino.h>

/*
  Built-in MSM261D3526H1CPM PDM microphone pins for the ESP32-S3-SPK N16R8 board.

  The seller diagram marks MSM261D3526H1CPM, which is a PDM digital MEMS
  microphone. The board exposes three related GPIOs: DATA, CLK and L/R select.
*/

#define MIC_PIN_DATA 38
#define MIC_PIN_CLK 39
#define MIC_PIN_LR 40
#define MIC_PINSET_NAME "ESP32-S3-SPK MSM261D3526H1CPM PDM microphone"
