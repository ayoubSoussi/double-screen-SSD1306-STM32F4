#include "Double_screen.h"



#define ssd1306_swap(a, b) { int16_t t = a; a = b; b = t; }



extern I2C_HandleTypeDef hi2c1, hi2c2;
Adafruit_SSD1306 lcd_top(&hi2c1, 0), lcd_bottom(&hi2c2, 0);


Double_screen::Double_screen():
WIDTH(128), HEIGHT(64) {
	/*Initialize other parameters*/
	_width    = WIDTH;
  _height   = HEIGHT;
  rotation  = 0;
  cursor_y  = cursor_x    = 0;
  textsize  = 1;
  textcolor = textbgcolor = 0xFFFF;
  wrap      = true;
}

void Double_screen::drawPixel(int16_t x, int16_t y, uint16_t color) {
	if (y < SSD1306_LCDHEIGHT) {
		lcd_top.drawPixel(x, y, color);
	}
	else {
		lcd_bottom.drawPixel(x, y - SSD1306_LCDHEIGHT, color);
	}
}

void Double_screen::drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color) {
	if (y0 < SSD1306_LCDHEIGHT && y1 < SSD1306_LCDHEIGHT) { // The two points are in the top side
		lcd_top.drawLine(x0, y0, x1, y1, color);
	}
	else if (y0 >= SSD1306_LCDHEIGHT && y1 >= SSD1306_LCDHEIGHT) { // The two points are in the bottom side
		lcd_bottom.drawLine(x0, y0 - SSD1306_LCDHEIGHT, x1, y1 - SSD1306_LCDHEIGHT, color);
	}
	else {
		if (y0 >= SSD1306_LCDHEIGHT && y1 < SSD1306_LCDHEIGHT) { // The first point is in the bottom and the second in the top side
			ssd1306_swap(y0, y1); ssd1306_swap(x0, x1);  // swap the two points
		}
		// NOW The first point is in the top and the second in the bottom side
		
		lcd_top.drawLine(x0, y0, x1, y1, color);
		lcd_bottom.drawLine(x0 , y0 - SSD1306_LCDHEIGHT, x1, y1 - SSD1306_LCDHEIGHT, color);
	}
}

void Double_screen::drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) {
	// IMPLEMENT
}

void Double_screen::drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) {
	// IMPLEMENT
}
void Double_screen::drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
	// IMPLEMENT
}

void Double_screen::fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
	// IMPLEMENT
}

void Double_screen::fillScreen(uint16_t color) {
	// IMPLEMENT
}

void Double_screen::drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color) {
	// IMPLEMENT
}

void Double_screen::drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color) {
	// IMPLEMENT
}

void Double_screen::fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color) {
	// IMPLEMENT
}

void Double_screen::fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color) {
	// IMPLEMENT
}

void Double_screen::drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color) {
	// IMPLEMENT
}

void Double_screen::fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color) {
	// IMPLEMENT
}

void Double_screen::drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color) {
	// IMPLEMENT
}

void Double_screen::fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color) {
	// IMPLEMENT
}

void Double_screen::drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color) {
	// IMPLEMENT
}

void Double_screen::drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color, uint16_t bg) {
	// IMPLEMENT
}

void Double_screen::drawXBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color) {
	// IMPLEMENT
}

void Double_screen::drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size) {
	// IMPLEMENT
}

void Double_screen::write(uint8_t) {
	// IMPLEMENT
}

void Double_screen::begin(uint8_t switchvcc, uint8_t i2caddr, bool reset) {
	lcd_top.begin(SSD1306_SWITCHCAPVCC, 0x78);
	lcd_bottom.begin(SSD1306_SWITCHCAPVCC, 0x78);
}

void Double_screen::clearDisplay(void) {
	lcd_top.clearDisplay();
	lcd_bottom.clearDisplay();
}

void Double_screen::invertDisplay(uint8_t i) {
	// IMPLEMENT
}

void Double_screen::display() {
	lcd_top.display();
	lcd_bottom.display();
}

void Double_screen::startscrollright(uint8_t start, uint8_t stop) {
	// IMPLEMENT
}

void Double_screen::startscrollleft(uint8_t start, uint8_t stop) {
	// IMPLEMENT
}

void Double_screen::startscrolldiagright(uint8_t start, uint8_t stop) {
	// IMPLEMENT
}

void Double_screen::startscrolldiagleft(uint8_t start, uint8_t stop) {
	// IMPLEMENT
}

void Double_screen::stopscroll(void) {
	// IMPLEMENT
}

void Double_screen::dim(bool dim) {
	// IMPLEMENT
}

void Double_screen::printTop(const char* format) {
	lcd_top.printf(format);
}

void Double_screen::printBottom(const char* format) {
	lcd_bottom.printf(format);
}

void Double_screen::fastSPIwrite(uint8_t c) {
	// IMPLEMENT
}

void Double_screen::memset(uint8_t buffer[], uint16_t start_address, uint16_t length) {
	// IMPLEMENT
}

void Double_screen::drawFastVLineInternal(int16_t x, int16_t y, int16_t h, uint16_t color) {
	// IMPLEMENT
}

void Double_screen::drawFastHLineInternal(int16_t x, int16_t y, int16_t w, uint16_t color) {
	// IMPLEMENT
}


// Return the size of the display (per current rotation)
int16_t Double_screen::width(void) const {
  return _width;
}
 
int16_t Double_screen::height(void) const {
  return _height;
}

void Double_screen::setCursor(int16_t x, int16_t y) {
	// set cursor for the two screens
	lcd_top.setCursor(x, y);
	lcd_bottom.setCursor(x, y);
	// update internal attributes
  cursor_x = x;
  cursor_y = y;
}

void Double_screen::setTextSize(uint8_t s) {
	// set text size for the two screens
	lcd_top.setTextSize(s);
	lcd_bottom.setTextSize(s);
	// update internal attributes
  textsize = (s > 0) ? s : 1;
}

void Double_screen::setTextColor(uint16_t c) {
	// set text color for the two screens
	lcd_top.setTextColor(c);
	lcd_bottom.setTextColor(c);
	
  // For 'transparent' background, we'll set the bg 
  // to the same as fg instead of using a flag
  textcolor = textbgcolor = c;
}

void Double_screen::setTextColor(uint16_t c, uint16_t b) {
	// set text color for the two screens
	lcd_top.setTextColor(c, b);
	lcd_bottom.setTextColor(c, b);
	// update the internal attributes
  textcolor   = c;
  textbgcolor = b; 
}

void Double_screen::setTextWrap(bool w) {
  wrap = w;
}

uint8_t Double_screen::getRotation(void) const {
  return rotation;
}

void Double_screen::setRotation(uint8_t x) {
  rotation = (x & 3);
  switch(rotation) {
   case 0:
   case 2:
    _width  = WIDTH;
    _height = HEIGHT;
    break;
   case 1:
   case 3:
    _width  = HEIGHT;
    _height = WIDTH;
    break;
  }
}
