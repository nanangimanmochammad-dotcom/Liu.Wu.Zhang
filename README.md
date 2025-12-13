# STM32 Super Mario Parkour & UI System 🍄

这是一个基于 **STM32F446RE** 和 **LCD1602** 的嵌入式娱乐系统。不仅包含基础的信息显示，还内置了一个基于自定义字符的**超级玛丽跑酷小游戏**。

## ✨ 功能特性

本项目实现了一个完整的 UI 状态机，包含以下模式：
* **🌊 Splash Screen**: 滚动欢迎界面
* **ℹ️ Info Mode**: 显示实时系统信息（日期/学号等）
* **🎨 ASCII Art**: 字符画展示 (Peace/Love/Code)
* **🎬 Animation**: 巨型马里奥动画 (使用 3x2 字符拼接)
* **🎮 Mini Game**: **超级玛丽跑酷游戏** (通过按键跳跃躲避障碍)

## 🛠️ 硬件清单

* **MCU**: STM32F446RE (Nucleo-64 开发板)
* **Display**: LCD1602 (16x2 字符液晶屏)
* **Input**: 蓝色按钮 (User Button) 用于游戏控制
* **Toolchain**: STM32CubeIDE

## 📂 项目结构说明

```text
MES204_TC/
├── Core/
│   ├── Inc/              # 头文件 (main.h, ui_manager.h 等)
│   ├── Src/              # 源代码 (main.c, ui_manager.c 等)
│   └── Startup/          # 启动文件
├── Drivers/              # STM32 HAL 库文件
├── MES204_TC.ioc         # STM32CubeMX 硬件配置文件
└── MES204_TC.launch      # 调试启动配置

## 🚀 快速开始

1.  **克隆/下载** 本仓库到本地。
2.  打开 **STM32CubeIDE**。
3.  选择 `File` -> `Import` -> `Existing Projects into Workspace`。
4.  选择本项目所在的文件夹导入。
5.  **编译 (Build)** 项目 (如果报错提示缺少 Drivers，请打开 .ioc 文件并在 Device Configuration Tool 中点击生成代码)。
6.  **调试 (Debug)**: 连接开发板，点击调试按钮即可烧录运行。

## 🎮 游戏操作
* **按键**: 蓝色按钮 (User Button) 用于 **跳跃** 和 **开始游戏**。
* **目标**: 控制马里奥避开障碍物，坚持时间越长分数越高！

---
Created with ❤️ (https://github.com/nanangimanmochammad-dotcom)
