#include "Snake_game.h"
#include "my_vector.h"

/* A snake will be represented by a vector of pairs, the pairs represent
  the points (x, y) of the body of the snake in the screen
	*/

						
Snake_game::Snake_game(int16_t x_head, int16_t y_head, int16_t x_tail, int16_t y_tail) {
	if ( x_head != x_tail && y_head != y_tail ) { // The snake is not horizontal nor vertical
		// Error
	}
	else {
		initializeScreen();
		////////// test
		addNewHead(10, 10);
		addNewHead(10, 20);
		addNewHead(20, 20);
		addNewHead(20, 30);
		addNewHead(30, 30);
		addNewHead(30, 40);
	}
}

void Snake_game::right() {
	
}

void Snake_game::left() {
	
}

void Snake_game::up() {
	
}

void Snake_game::down() {
	
}

int Snake_game::getSize() {
	return snake.size();
}

/* Add point new head(x, y) to the snake pair list*/
void Snake_game::addNewHead(int x, int y) {
	// make the head as a vector
	Vector<int> head ;
	head.push_back(x);
	head.push_back(y);
	// add the head to the snake
	snake.push_back(head);
}
/* Delete the tail of the snake (first element)*/
void Snake_game::popTail() {
	
}
/* Initialize the LCD screen*/
void Snake_game::initializeScreen() {
		mydoubleScreen.begin(SSD1306_SWITCHCAPVCC, 0x78);
		mydoubleScreen.display();
		HAL_Delay(500);
}
/*Draw the current snake in the LCD screens*/
void Snake_game::drawCurrentSnake() {
	// clear the screen
	mydoubleScreen.clearDisplay();
	// get the tail
	int x_0 = snake.at(0).front(), y_0 = snake.at(0).back() ;
	int x, y ; // variable for storing next point
	for (int i = 1; i<getSize(); i++) {
		// get next point
		x = snake.at(i).front();
		y = snake.at(i).back();
		// draw the line
		mydoubleScreen.drawLine(x, y, x_0, y_0, WHITE);
		// update x_0, y0
		x_0 = x; y_0 = y;
	}
	// display the snake
	mydoubleScreen.display();
	HAL_Delay(500);
}


//////////////// test functions
int Snake_game::getElem() {
	return snake.at(1).back();
}
