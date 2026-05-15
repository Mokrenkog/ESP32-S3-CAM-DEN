# PC proxy for ESP32-S3-CAM-DEN

This proxy runs on a Windows PC in the same local network as the ESP32 board.
The browser opens one PC address, while the server forwards:

- `/video` -> `http://<ESP32-IP>:80/stream`
- `/audio.ws` -> `ws://<ESP32-IP>:81/audio.ws`
- `/audio.wav`, `/audio/sample.wav`, `/audio/debug` -> ESP32 audio port `81`

## Quick start

1. Install Node.js LTS if it is not installed.
2. Run `start-proxy.bat`.
3. The script finds the ESP32, starts the local proxy, starts an internet tunnel,
   and opens the public URL automatically.

The BAT file sets defaults:

```text
ESP32_HTTP_PORT=80
ESP32_AUDIO_PORT=81
PROXY_PORT=8080
ESP32_AUTH_USER=cam
ESP32_AUTH_PASSWORD=1234
```

## Find the board IP

Run:

```bat
find-board.bat
```

If the board is connected to the same router as the PC, the IP should look like
the PC/router subnet, for example `192.168.50.xxx`.

If the board is not connected to that router, connect the PC directly to:

```text
SSID: ESP32-S3-CAM-DEN
Password: 12345678
Board IP: 192.168.4.1
```

## Internet access

Run:

```bat
start-proxy.bat
```

The script tries ngrok first, using saved ngrok configuration from a previous
successful login.

For the first ngrok setup:

1. Create a free ngrok account.
2. Copy your token from `https://dashboard.ngrok.com/get-started/your-authtoken`.
3. Run once:

```bat
pc-proxy\tools\ngrok.exe config add-authtoken YOUR_TOKEN
```

After that, `start-proxy.bat` does not ask for the token again.

The public URL will look similar to:

```text
https://random-name.ngrok-free.app/
```

Keep the BAT window open while streaming.

If ngrok reports `ERR_NGROK_334`, an old ngrok tunnel is still online. The script
tries to stop old local `ngrok.exe` processes automatically before starting a
new tunnel. If the error remains, close old terminal windows or stop the endpoint
from the ngrok dashboard.

If ngrok fails, the script tries Cloudflare Tunnel, then localtunnel.
