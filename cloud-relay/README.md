# Cloud relay

Node.js relay для схеми:

- `ESP32 -> WSS relay` для відео та аудіо з плати
- `GitHub Pages -> WSS relay` для перегляду
- `браузерний мікрофон -> WSS relay -> ESP32 speaker`

## Швидкий старт

```powershell
cd cloud-relay
copy .env.example .env
npm install
npm start
```

За замовчуванням relay слухає порт `8080`.

## Обов'язкові секрети

- `DEVICE_ID`
- `DEVICE_TOKEN`
- `VIEWER_TOKEN`

`DEVICE_TOKEN` прошивається в ESP через `include/relay_config.h`.

`VIEWER_TOKEN` вводиться на GitHub Pages сторінці вручну.

## Продакшн

Рекомендовано поставити relay за `Caddy` або `Nginx`, щоб отримати:

- `HTTPS` для сторінки
- `WSS` для WebSocket
- валідний TLS-сертифікат для мікрофона браузера
