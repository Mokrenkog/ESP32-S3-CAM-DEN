#pragma once

// Optional cloud relay mode.
// Copy this file to `include/relay_config.h`, fill the values, rebuild and upload.

#define RELAY_ENABLED 1

// Public HTTPS/WSS endpoint of your relay server, without protocol.
// Example: "relay.example.com"
#define RELAY_HOST "relay.example.com"

// Public port of the relay server. Use 443 behind HTTPS/WSS reverse proxy.
#define RELAY_PORT 443

// Set to 1 for WSS, 0 for plain WS.
#define RELAY_USE_TLS 1

// Set to 1 only for local testing with a self-signed certificate.
#define RELAY_ALLOW_INSECURE_TLS 0

// Paths on the relay server.
#define RELAY_BASE_PATH ""

// Device credentials used by the ESP32 to authenticate to the relay.
#define RELAY_DEVICE_ID "esp32-s3-cam-den-01"
#define RELAY_DEVICE_TOKEN "replace-with-long-random-device-token"

// Optional always-on board-to-board audio bridge through relay media.
#define RELAY_INTERCOM_ENABLED 0

// Cloud stream tuning.
#define RELAY_FRAME_INTERVAL_MS 160
#define RELAY_STATE_INTERVAL_MS 10000
#define RELAY_RECONNECT_INTERVAL_MS 5000

