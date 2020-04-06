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
#define SNAKE_STEP 5 // steps of the snake in pixels 
#define TIME_BETWEEN_DRAW 300 // time between updates of the snake in the screen (in ms)
/*Initial parameters of the game*/
#define INIT_HEAD_X     50
#define INIT_HEAD_Y			10
#define INIT_TAIL_X			0
#define INIT_TAIL_Y			10
#define INIT_DIRECTION  RIGHT
/*User buttons pins*/
#define START_BUTTON     GPIO_PIN_0
#define RIGHT_BUTTON     GPIO_PIN_11
#define LEFT_BUTTON			 GPIO_PIN_8
#define UP_BUTTON        GPIO_PIN_9
#define DOWN_BUTTON      GPIO_PIN_10


/* Direction of the snake*/
typedef enum {
	RIGHT,
	LEFT,
	UP,
	DOWN
} Direction;

class Snake_game {
	public :
		Snake_game(); // define a Snake game by giving head and tail positions
		/* Game functions*/
		void start();
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
		void modifyHead(int x, int y);
		void modifyTail(int x, int y);
		void popTail();
		void popHead();
		void headStep(Direction direction) ;
		void tailStep();
	
		/* Graphic variables and functions*/
		Double_screen mydoubleScreen;
		void initializeScreen();
		void drawCurrentSnake();
};



#endif
