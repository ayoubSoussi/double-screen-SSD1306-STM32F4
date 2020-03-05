#ifndef __DOUBLE_SCREEN
#define __DOUBLE_SCREEN

#ifdef __cplusplus
 extern "C" {
#endif
   
#include "stm32f4xx_hal.h"

#ifdef __cplusplus
}
#endif


class Double_screen {

 public:

  Double_screen(I2C_HandleTypeDef *top_hi2c, I2C_HandleTypeDef *bottom_hi2c, int8_t reset); // Constructor

  // draw pixel:
  void drawPixel(int16_t x, int16_t y, uint16_t color);

  // These MAY be overridden by the subclass to provide device-specific
  // optimized code.  Otherwise 'generic' versions are used.
  void
    drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color),
    drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color),
    drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color),
    drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color),
    fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color),
    fillScreen(uint16_t color);


  // These exist only with Adafruit_GFX (no subclass overrides)
  void
    drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color,
      uint16_t bg, uint8_t size),
    setCursor(int16_t x, int16_t y),
    setTextColor(uint16_t c),
    setTextColor(uint16_t c, uint16_t bg),
    setTextSize(uint8_t s),
    setTextWrap(bool w),
    setRotation(uint8_t r);

#if ARDUINO >= 100
  virtual size_t write(uint8_t);
#else
  virtual void   write(uint8_t);
#endif

  int16_t height(void) const;
  int16_t width(void) const;

  uint8_t getRotation(void) const;

 protected:
  const int16_t
    WIDTH, HEIGHT;   // This is the 'raw' display w/h - never changes
  int16_t
    _width, _height, // Display w/h as modified by current rotation
    cursor_x, cursor_y;
  uint16_t
    textcolor, textbgcolor;
  uint8_t
    textsize,
    rotation;
  bool
    wrap; // If set, 'wrap' text at right edge of display
};

#endif // __DOUBLE_SCREEN


