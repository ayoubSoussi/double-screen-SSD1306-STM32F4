# double-screen-SSD1306-STM32F4
This is a library to make 2 LCD screens 128*32 screens to work as one 128*64 screen

## Introduction
You may have two 128*32 LCD screens and you want to transform them into one 128*64 screen, then this library is what you need.
It's a library that implements all the Adafruit-SSD1306 library functions and adapt them to your needs. By using it, you can draw shapes,
write words and draw Bitmap images.

## Functions
This C++ library includes the following functions :

- drawPixel
- drawLine
- drawRect
- fillRect
- fillScreen
- drawCircle
- drawCircleHelper
- fillCircle
- fillCircleHelper
- drawTriangle
- fillTriangle
- drawRoundRect
- fillRoundRect
- drawBitmap
- drawBitmap
- drawXBitmap
- drawChar
- write

## How to use
After adding the Driver files in your projects, you only need to include the header file and create an object, then you are ready to go :
```
#include "Double_screen.h"

Double_screen mydoubleScreen;
```

## Demo
The Demo folder containts a Keil µVision project and uses the double_screen library to draw shapes and bitmaps on the two LCD screens. 
### 1. Hardware : 
  - two 128*32 SSD1306 LCD screens (I2C communication bus)
  - STM32F4 discovery board
### 2. Circuit :

![al](https://img.techpowerup.org/200409/double-lcd-circuit.jpg)

### 3. Results :
You can find the demo Youtube video [here](https://youtu.be/yQ_l5s9f1W8).

