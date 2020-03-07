#ifndef __SNAKE_GAME
#define __SNAKE_GAME


/* Includes */
#include <vector>
#include <stdint.h>
#include "Double_screen.h"

/* Defines*/
#define DOUBLE_LCD_WIDTH 128
#define DOUBLE_LCD_HEIGHT 64


/* Direction of the snake*/
typedef enum {
	RIGHT,
	LEFT,
	UP,
	DOWN
} Direction;

class Snake_game {
	public :
		Snake_game(int16_t x_head, int16_t y_head, int16_t x_tail, int16_t y_tail); // define a Snake game by giving head and tail positions
		/* Function for changing position*/
		void right();
		void left();
		void up();
		void down();
	
	private :
		/* A snake will be represented by a vector of pairs, the pairs represent
  the points (x, y) of the body of the snake in the screen
	*/
		std::vector< std::pair<int, int> > snake;
	
		Direction snake_direction;
		Double_screen myscreen();
};



#endif
