#ifndef __DOUBLE_SCREEN
#define __DOUBLE_SCREEN

#ifdef __cplusplus
 extern "C" {
#endif
   
#include "stm32f4xx_hal.h"
#include "Adafruit_SSD1306.h"
#ifdef __cplusplus
}
#endif


class Double_screen {

 public:

  Double_screen(); // Constructor

  // This MUST be defined by the subclass:
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
    drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color),
    drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,
      uint16_t color),
    fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color),
    fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,
      int16_t delta, uint16_t color),
    drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
      int16_t x2, int16_t y2, uint16_t color),
    fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
      int16_t x2, int16_t y2, uint16_t color),
    drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
      int16_t radius, uint16_t color),
    fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
      int16_t radius, uint16_t color),
    drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap,
      int16_t w, int16_t h, uint16_t color),
    drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap,
      int16_t w, int16_t h, uint16_t color, uint16_t bg),
    drawXBitmap(int16_t x, int16_t y, const uint8_t *bitmap, 
      int16_t w, int16_t h, uint16_t color),
    drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color,
      uint16_t bg, uint8_t size),
    setCursor(int16_t x, int16_t y),
    setTextColor(uint16_t c),
    setTextColor(uint16_t c, uint16_t bg),
    setTextSize(uint8_t s),
    setTextWrap(bool w),
    setRotation(uint8_t r);

  void write(uint8_t);

  int16_t height(void) const;
  int16_t width(void) const;

  uint8_t getRotation(void) const;
/*______________________________ SSD1306_____________________________________*/
	void begin(uint8_t switchvcc, uint8_t i2caddr, bool reset=true);

  void clearDisplay(void);
  void invertDisplay(uint8_t i);
  void display();

  void startscrollright(uint8_t start, uint8_t stop);
  void startscrollleft(uint8_t start, uint8_t stop);

  void startscrolldiagright(uint8_t start, uint8_t stop);
  void startscrolldiagleft(uint8_t start, uint8_t stop);
  void stopscroll(void);

  void dim(bool dim);

  void printTop(const char* format);
	void printBottom(const char* format);
	/*--------------------------------------------------------------*/
 protected:
  const int16_t WIDTH, HEIGHT;   // This is the 'raw' display w/h - never changes
  int16_t _width, _height, // Display w/h as modified by current rotation
    cursor_x, cursor_y;
  uint16_t textcolor, textbgcolor;
  uint8_t textsize, rotation;
  bool
    wrap; // If set, 'wrap' text at right edge of display
	
 private:
  int8_t _i2caddr, _vccstate, sid, sclk, dc, rst, cs;
  void fastSPIwrite(uint8_t c);
  void memset(uint8_t buffer[], uint16_t start_address, uint16_t length);


  inline void drawFastVLineInternal(int16_t x, int16_t y, int16_t h, uint16_t color) __attribute__((always_inline));
  inline void drawFastHLineInternal(int16_t x, int16_t y, int16_t w, uint16_t color) __attribute__((always_inline));
};

#endif // __DOUBLE_SCREEN


