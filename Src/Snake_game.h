#ifndef __SNAKE_GAME
#define __SNAKE_GAME

#ifdef __cplusplus
 extern "C" {
#endif
	 
/* Includes */
#include <stdint.h>
#include "Double_screen.h"
#ifdef __cplusplus
}
#endif
// C++ includes
#include "my_vector.h"
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
		int getSize();
	////// test functions
		int getElem();
	
	//private :
		Vector<Vector<int> > snake;
		Direction snake_direction;
		Double_screen myscreen();
		/* Functions for snake list manipulation*/
		void addNewHead(int x, int y);
		void popTail();
	
		/* Graphic variables and functions*/
		Double_screen mydoubleScreen;
		void initializeScreen();
		void drawCurrentSnake();
};



#endif
