# esp32-manual-cat-feed-control
ESP32 Manual Cat Feed Control

This project is yet another variation of my idea of controlling ever-hungry pet feeding process by a group of people with different schedules. The previous version is located [here](https://github.com/NLLK/manual-cat-feed-control-device)

The idea is quite simple - when a person feeds the cat, they mark the action in the app. To make this process as simple as possible one could use a special device based on [CYD](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display) (or in my case it's 2.4 inch variant), where a person marks when they fed the cat according to a unified schedule (currently 4 times a day). To be able to see whether the cat has been fed or needs feeding without looking to the device screen, one could connect to the local Wi-FI network and check the fed status on the HTTP page.

# Tech stack
A quick overview of the tech stack (both hardware and software):

- LVGL 9.3;
- Arduino ESP32 platform;
- Platform IO;
- SDL 2 mainly for LVGL debug;
- I2C for RTC;
- Battery management and powersaving;
- Arduino HTTP-server and HTTP-client;
- Wi-Fi.

# Design
The system designed to be modular - the client and the server applications could run on the same or on a different MCUs.

I designed it to run in a three different configurations:
- CYD Client and ESP32-S3 Mini under my desk as a server;
- CYD Standalone; 
- CYD USB-powered.

The first one allows user to control when they fed the cat with a device and with HTTP-page, and device could be placed in a wireless enviroment.

The second option allows user to set feeding time only with CYD board, but makes it the only board needed (in case there is no local server one can setup).

The third option is called "combined" for the reason it handles both LVGL UI Client and HTTP-server things. This variantion meant to be connected to the USB power source continuously.

# Project structure
```
src/                      # Root of the source code
├── application/          # Platfrom independent application layer
│   ├── client/           # Main logic for the client code
│   └── server/           # Logic for the server (which could be used in the powersaving configuration)
└── platform/             # Platfroms and configurations
    ├── cyd/              # CYD platform 
    │   ├── lcd_client/   # LCD Client for the CYD Platform
    │   ├── serverless/   # LCD Client + Serverless configuration for the local usage
    |   └── combined/     # LCD Client + HTTP Server + HTTP Client
    ├── sdl/              # SDL Platform (For now, mainly for LVGL Debug)
    │   └── serverless/   # LCD Client designed for LVGL Debug
    └── c3/               # ESP32-C3 Platform
        └── web_server/   # Cheap HTTP server on the ESP32-C3 Platform (includes both HTTP-server and HTTP-client)
```