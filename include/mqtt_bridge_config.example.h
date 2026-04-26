#pragma once

// Copy to `include/mqtt_bridge_config.h`, set the same values on the GitHub Pages
// site, rebuild and upload.

#define MQTT_BRIDGE_ENABLED 1

// Example values for EMQX Cloud private deployment:
// - ESP32: use MQTT over TLS 8883
// - Browser: use Secure WebSocket WSS
#define MQTT_BROKER_HOST "your-deployment.emqxsl.com"
#define MQTT_BROKER_PORT 8883
#define MQTT_BROKER_WSS_URL "wss://your-deployment.emqxsl.com:8084/mqtt"
#define MQTT_USE_TLS 1

// Quick start: allow TLS without CA pinning on the ESP32.
// Later we can tighten this by pinning the CA certificate.
#define MQTT_ALLOW_INSECURE_TLS 1

// Use a long random secret because this broker is public.
// Everyone on the public broker can theoretically observe messages.
#define MQTT_DEVICE_ID "esp32-s3-cam-den-01"
#define MQTT_SHARED_KEY "replace-with-very-long-random-shared-key"

// EMQX broker authentication credentials.
#define MQTT_USERNAME "esp32-device"
#define MQTT_PASSWORD "replace-with-emqx-password"

// Cloud stream tuning.
#define MQTT_VIDEO_INTERVAL_MS 450
#define MQTT_STATE_INTERVAL_MS 10000
#define MQTT_RECONNECT_INTERVAL_MS 5000
