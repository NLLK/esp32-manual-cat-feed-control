# esp32-manual-cat-feed-control

# Project structure
src/                      # Root of source code
├── application/          # Platfrom independent application layer
│   ├── client/           # Main logic for client code
│   └── server/           # Logic for the server (which could be used in powersaving configuration)
└── platform/             # Platfroms and configurations
    ├── cyd/              # CYD platform 
    │   ├── lcd_client/   # LCD Client for CYD Platform
    │   ├── serverless/   # LCD Client + Serverless configuration for local use
    |   └── combined/     # LCD Client + HTTP Server + HTTP Client
    ├── sdl/              # SDL Platform (For now, mainly for LVGL Debug)
    │   └── lcd_client/   # LCD Client designed for LVGL Debug
    └── c3/               # ESP32-C3 Platform
        └── web_server/   # Cheap HTTP server on ESP32-C3 Platform (includes both HTTP-server and HTTP-client)