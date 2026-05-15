# PC proxy for ESP32-S3-CAM-DEN

This proxy runs on a Windows PC in the same local network as the ESP32 board.
The browser opens one PC address, while the server forwards:

- `/video` -> `http://<ESP32-IP>:80/stream`
- `/audio.ws` -> `ws://<ESP32-IP>:81/audio.ws`
- `/audio.wav`, `/audio/sample.wav`, `/audio/debug` -> ESP32 audio port `81`

## Quick start

1. Install Node.js LTS if it is not installed.
2. Run `start-proxy.bat`.
3. Enter the ESP32 IP, for example `192.168.4.1`.
4. Open `http://localhost:8080/`.

The BAT file sets defaults:

```text
ESP32_HTTP_PORT=80
ESP32_AUDIO_PORT=81
PROXY_PORT=8080
ESP32_AUTH_USER=cam
ESP32_AUTH_PASSWORD=1234
```

## Internet access

Expose the PC proxy, not the ESP32 directly. For example, use Cloudflare Tunnel,
ngrok, Tailscale Funnel, or router port forwarding to the PC port `8080`.

For public access, set a token before running:

```bat
set PROXY_TOKEN=change-this-password
start-proxy.bat
```

Then open:

```text
http://localhost:8080/?token=change-this-password
```

The browser keeps the token in a cookie so video and audio requests work from
the same page.
