# LCD Blinking Eye - LovyanGFX

A simple animated blinking eye display for circular SGC9A01 LCD panels using the LovyanGFX graphics library.

Information about this project is avaible at **[Animating a Blinking Eye on an Arduino-Powered LCD Display](https://garrysblog.com/2025/11/13/animating-a-blinking-eye-on-an-arduino-powered-lcd-display)**

## 🎬 Demo

The animation alternates between an open eye and a quick blink.

## 🛠️ Hardware Requirements

- **Display**: SGC9A01 240x240 circular LCD display
- **Microcontroller**: ESP32
- **Connections**: Standard SPI interface

### Wiring Example (ESP32)

| Display Pin | ESP32 Pin | Description |
|------------|-----------|-------------|
| VCC | 3.3V | Power |
| GND | GND | Ground |
| SCL/SCLK | GPIO 18 | SPI Clock |
| SDA/MOSI | GPIO 23 | SPI Data |
| RES/RST | GPIO 4 | Reset |
| DC | GPIO 2 | Data/Command |
| CS | GPIO 15 | Chip Select |
| BL/BLK | GPIO 32 | Backlight (optional) |

*Note: Pin assignments may vary depending on your display module and microcontroller.*

## 📚 Software Dependencies

- **[LovyanGFX Library](https://github.com/lovyan03/LovyanGFX)** - High-performance graphics library

## 📄 License

This project is open source. Please check the repository for license details.
