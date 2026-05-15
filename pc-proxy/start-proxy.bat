@echo off
setlocal
cd /d "%~dp0"

where node >nul 2>nul
if errorlevel 1 (
  echo Node.js is not installed or is not in PATH.
  echo Install Node.js LTS from https://nodejs.org/ and run this file again.
  pause
  exit /b 1
)

if "%ESP32_HOST%"=="" (
  set /p ESP32_HOST=ESP32 IP address [192.168.4.1]: 
  if "%ESP32_HOST%"=="" set ESP32_HOST=192.168.4.1
)

if "%ESP32_HTTP_PORT%"=="" set ESP32_HTTP_PORT=80
if "%ESP32_AUDIO_PORT%"=="" set ESP32_AUDIO_PORT=81
if "%PROXY_PORT%"=="" set PROXY_PORT=8080

if "%ESP32_AUTH_USER%"=="" set ESP32_AUTH_USER=cam
if "%ESP32_AUTH_PASSWORD%"=="" set ESP32_AUTH_PASSWORD=1234

echo.
echo ESP32 video: http://%ESP32_HOST%:%ESP32_HTTP_PORT%/stream
echo ESP32 audio: ws://%ESP32_HOST%:%ESP32_AUDIO_PORT%/audio.ws
echo PC proxy:    http://localhost:%PROXY_PORT%/
echo.

set OPEN_BROWSER=1
node server.js

echo.
pause
