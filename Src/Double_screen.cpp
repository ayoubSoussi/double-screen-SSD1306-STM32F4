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
  textcolor = WHITE;
	textbgcolor = BLACK;
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
	//lcd_top.drawFastVLineInternal(x, y, h, color);
}

void Double_screen::drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) {
	
}
void Double_screen::drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
	int16_t x_1 = x + w, y_1 = y + h;
	
	if (x > x_1) ssd1306_swap(x, x_1);
	if (y > y_1) ssd1306_swap (y, y_1);
	// draw first part of rect in top LCD
	lcd_top.drawRect(x, y, w, h, color);
	
	if ( y_1 >= SSD1306_LCDHEIGHT) {
		// draw second part of the rect in bottom LCD
		lcd_bottom.drawRect(x, y - SSD1306_LCDHEIGHT, w, h , color);
	}
}

void Double_screen::fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
	int16_t x_1 = x + w, y_1 = y + h;
	
	if (x > x_1) ssd1306_swap(x, x_1);
	if (y > y_1) ssd1306_swap (y, y_1);
	// draw first part of rect in top LCD
	lcd_top.fillRect(x, y, w, h, color);
	
	if ( y_1 >= SSD1306_LCDHEIGHT) {
		// draw second part of the rect in bottom LCD
		lcd_bottom.fillRect(x, y - SSD1306_LCDHEIGHT, w, h , color);
	}
}

void Double_screen::fillScreen(uint16_t color) {
	lcd_top.fillScreen(color);
	lcd_bottom.fillScreen(color);
}

void Double_screen::drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color) {
	// draw first part in top LCD
	lcd_top.drawCircle(x0, y0, r, color);
	// draw second part in bottom LCD
	lcd_bottom.drawCircle(x0, y0 - SSD1306_LCDHEIGHT, r, color);
	
}

void Double_screen::drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color) {
	// draw first part in top LCD
	lcd_top.drawCircleHelper(x0, y0, r, cornername, color);
	// draw second part in bottom LCD
	lcd_bottom.drawCircleHelper(x0, y0 - SSD1306_LCDHEIGHT, r, cornername, color);
}

void Double_screen::fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color) {
	// draw first part in top LCD
	lcd_top.fillCircle(x0, y0, r, color);
	// draw second part in bottom LCD
	lcd_bottom.fillCircle(x0, y0 - SSD1306_LCDHEIGHT, r, color);
}

void Double_screen::fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color) {
	// draw first part in top LCD
	lcd_top.fillCircleHelper(x0, y0, r, cornername, delta, color);
	// draw second part in bottom LCD
	lcd_bottom.fillCircleHelper(x0, y0 - SSD1306_LCDHEIGHT, r, cornername, delta, color);
}

void Double_screen::drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color) {
	// draw first part in top LCD
	lcd_top.drawTriangle(x0, y0, x1, y1, x2, y2, color);
	// draw second part in bottom LCD
	lcd_bottom.drawTriangle(x0, y0 - SSD1306_LCDHEIGHT, x1, y1 - SSD1306_LCDHEIGHT, x2, y2 - SSD1306_LCDHEIGHT, color);
}

void Double_screen::fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color) {
	// draw first part in top LCD
	lcd_top.fillTriangle(x0, y0, x1, y1, x2, y2, color);
	// draw second part in bottom LCD
	lcd_bottom.fillTriangle(x0, y0 - SSD1306_LCDHEIGHT, x1, y1 - SSD1306_LCDHEIGHT, x2, y2 - SSD1306_LCDHEIGHT, color);
}

void Double_screen::drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color) {
	// draw first part in top LCD
	lcd_top.drawRoundRect(x0, y0, w, h, radius, color);
	// draw second part in bottom LCD
	lcd_bottom.drawRoundRect(x0, y0 - SSD1306_LCDHEIGHT, w, h, radius, color);
}

void Double_screen::fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color) {
	// draw first part in top LCD
	lcd_top.fillRoundRect(x0, y0, w, h, radius, color);
	// draw second part in bottom LCD
	lcd_bottom.fillRoundRect(x0, y0 - SSD1306_LCDHEIGHT, w, h, radius, color);
}

void Double_screen::drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color) {
	int16_t i, j, byteWidth = (w + 7) / 8;

  for(j=0; j<h; j++) {
    for(i=0; i<w; i++ ) {
      if(pgm_read_byte(bitmap + j * byteWidth + i / 8) & (128 >> (i & 7))) {
        drawPixel(x+i, y+j, color);
      }
    }
  }
}

void Double_screen::drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color, uint16_t bg) {
	int16_t i, j, byteWidth = (w + 7) / 8;
  
  for(j=0; j<h; j++) {
    for(i=0; i<w; i++ ) {
      if(pgm_read_byte(bitmap + j * byteWidth + i / 8) & (128 >> (i & 7))) {
        drawPixel(x+i, y+j, color);
      }
      else {
      	drawPixel(x+i, y+j, bg);
      }
    }
  }
}

void Double_screen::drawXBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color) {
	int16_t i, j, byteWidth = (w + 7) / 8;
  
  for(j=0; j<h; j++) {
    for(i=0; i<w; i++ ) {
      if(pgm_read_byte(bitmap + j * byteWidth + i / 8) & (1 << (i % 8))) {
        drawPixel(x+i, y+j, color);
      }
    }
  }
}

void Double_screen::drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size) {
	if((x >= _width)            || // Clip right
     (y >= _height)           || // Clip bottom
     ((x + 6 * size - 1) < 0) || // Clip left
     ((y + 8 * size - 1) < 0))   // Clip top
    return;

  for (int8_t i=0; i<6; i++ ) {
    uint8_t line;
    if (i == 5) 
      line = 0x0;
    else 
      line = pgm_read_byte(FONT_5x7+(c*5)+i);
    for (int8_t j = 0; j<8; j++) {
      if (line & 0x1) {
        if (size == 1) // default size
          drawPixel(x+i, y+j, color);
        else {  // big size
          fillRect(x+(i*size), y+(j*size), size, size, color);
        }
      } else if (bg != color) {
        if (size == 1) // default size
          drawPixel(x+i, y+j, bg);
        else {  // big size
          fillRect(x+i*size, y+j*size, size, size, bg);
        }
      }
      line >>= 1;
    }
  }
}

void Double_screen::write(uint8_t c) {
	if (c == '\n') {
    cursor_y += textsize*8;
    cursor_x  = 0;
  } else if (c == '\r') {
    // skip em
  } else {
			drawChar(cursor_x, cursor_y, c, textcolor, textbgcolor, textsize);
			cursor_x += textsize*6;
			if (wrap && (cursor_x > (_width - textsize*6))) {
				cursor_y += textsize*8;
				cursor_x = 0;
			}
	}
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
	lcd_top.invertDisplay(i);
	lcd_bottom.invertDisplay(i);
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
