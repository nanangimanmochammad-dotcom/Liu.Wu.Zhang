# STM32 Super Mario Parkour & UI System 🍄

An embedded entertainment system based on **STM32F446RE** and **LCD1602**. It features a robust UI state machine and a custom character-based **Super Mario Parkour Game**.

## ✨ Features

The project implements a comprehensive UI state machine with the following modes:
* **🌊 Splash Screen**: Scrolling welcome interface.
* **ℹ️ Info Mode**: Real-time system status display.
* **🎨 ASCII Art**: Graphic rendering using characters.
* **🎬 Animation**: Large-scale Mario animation composed of 3x2 characters.
* **🎮 Mini Game**: **Super Mario Parkour** (jump to avoid obstacles).

## 🛠️ Hardware Requirements

* **MCU**: STM32F446RE (Nucleo-64 Board)
* **Display**: LCD1602 (16x2 Character LCD)
* **Input**: User Button (Blue)
* **Toolchain**: STM32CubeIDE

## 📂 Project Structure

```text
MES204_TC/
├── Core/
│   ├── Inc/                  # Header files
│   │   ├── main.h
│   │   ├── dino_game.h       # Game logic definitions
│   │   ├── lcd_driver.h      # LCD1602 driver definitions
│   │   └── ui_manager.h      # UI state machine headers
│   ├── Src/                  # Source code
│   │   ├── main.c            # Main entry point
│   │   ├── dino_game.c       # Mario/Dino game implementation
│   │   ├── lcd_driver.c      # Low-level LCD control functions
│   │   └── ui_manager.c      # UI logic handling
│   └── Startup/              # Startup code
├── Drivers/                  # STM32 HAL Library
├── MES204_TC.ioc             # STM32CubeMX Configuration
└── MES204_TC.launch          # Debug Configuration
```

## 🚀 Quick Start

1.  **Clone/Download** this repository.
2.  Open **STM32CubeIDE**.
3.  Go to `File` -> `Import` -> `Existing Projects into Workspace`.
4.  Select the project folder.
5.  **Build** the project (If you see errors about missing drivers, open the `.ioc` file and generate code).
6.  **Debug**: Connect your board and click the Debug button to flash and run.

## 🎮 Game Controls

* **Button**: Blue User Button
* **Action**: Press to **Jump** / **Start Game**.
* **Objective**: Avoid obstacles and survive as long as possible for a high score!

---
Created with ❤️ (https://github.com/nanangimanmochammad-dotcom)
