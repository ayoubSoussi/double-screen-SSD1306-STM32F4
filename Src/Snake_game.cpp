#include "Snake_game.h"
#include "my_vector.h"

/* A snake will be represented by a vector of pairs, the pairs represent
  the points (x, y) of the body of the snake in the screen
	*/

						
Snake_game::Snake_game() {
	
}
/*Start the game*/
void Snake_game::start() {
	// initialize the screen
	initializeScreen();
	// initialize the snake
	addNewHead(INIT_TAIL_X, INIT_TAIL_Y) ;  // add the initial tail
	addNewHead(INIT_HEAD_X, INIT_HEAD_Y) ;  // add the initial head
	snake_direction = INIT_DIRECTION ; // add the initial direction
	while (1) {
		switch(snake_direction) {
			case RIGHT :
				right();
				break;
			case LEFT :
				left();
				break;
			case UP :
				up();
				break;
			case DOWN :
				down();
				break;
			default :
				break ;
		}
		drawCurrentSnake();
	}
}
/*This function update the snake vector when it turns right*/
void Snake_game::right() {
	if ( snake_direction == LEFT) return;
	// add step to the head
	headStep(RIGHT) ;
	// add step to the tail
	tailStep() ;
	// update the current direction
	snake_direction = RIGHT;
}
/*This function update the snake vector when it turns left*/
void Snake_game::left() {
	if ( snake_direction == RIGHT) return;
	// add step to the head
	headStep(LEFT) ;
	// add step to the tail
	tailStep() ;
	// update the current direction
	snake_direction = LEFT;
}
/*This function update the snake vector when it turns up*/
void Snake_game::up() {
	if ( snake_direction == DOWN) return;
	// add step to the head
	headStep(UP) ;
	// add step to the tail
	tailStep() ;
	// update the current direction
	snake_direction = UP;
}
/*This function update the snake vector when it turns down*/
void Snake_game::down() {
	if ( snake_direction == UP) return;
	// add step to the head
	headStep(DOWN) ;
	// add step to the tail
	tailStep() ;
	// update the current direction
	snake_direction = DOWN;
}

int Snake_game::getSize() {
	return snake.size();
}

/* Add point new head(x, y) to the snake pair list*/
void Snake_game::addNewHead(int x, int y) {
	if (x >= 0 && x < mydoubleScreen.width() && y >= 0 && y < mydoubleScreen.height()) {
			// make the head as a vector
			Vector<int> head ;
			head.push_back(x);
			head.push_back(y);
			// add the head to the snake
			snake.push_back(head);
	}
	else {
		// throw error : snake is out of the screen
	}
}
void Snake_game::modifyHead(int x, int y) {
		if (x >= 0 && x < mydoubleScreen.width() && y >= 0 && y < mydoubleScreen.height()) {
			// make the head as a vector
			Vector<int> new_head ;
			new_head.push_back(x);
			new_head.push_back(y);
			// delete the current head
			snake.pop_back();
			// add the new head to the snake
			snake.push_back(new_head);
	}
	else {
		// throw error : snake is out of the screen
	}
}
/* Modify the tail of the snake*/
void Snake_game::modifyTail(int x, int y) {
	if (x >= 0 && x < mydoubleScreen.width() && y >= 0 && y < mydoubleScreen.height()) {
			// make the new tail as a vector
			Vector<int> new_tail ;
			new_tail.push_back(x);
			new_tail.push_back(y);
			// remove the current tail
			snake.pop_front();
			// add the new tail to the snake
			snake.push_front(new_tail);
	}
	else {
		// throw error : snake is out of the screen
	}
}
/* Delete the tail of the snake (first element)*/
void Snake_game::popTail() {
	snake.pop_front();
}

/* Delete the head of the snake (first element)*/
void Snake_game::popHead() {
	snake.pop_back();
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
	HAL_Delay(TIME_BETWEEN_DRAW);
}
/*This function adds a step to the tail of the snake*/
void Snake_game::tailStep() {
	// get the current tail
	int x_tail = snake.at(0).front(), y_tail = snake.at(0).back();
	int x_btail = snake.at(1).front(), y_btail = snake.at(1).back(); // get the point right before the tail
	if(x_tail == x_btail) {
		if (y_tail - y_btail > SNAKE_STEP) { y_tail -= SNAKE_STEP ; modifyTail(x_tail, y_tail); }
		else if (y_btail - y_tail > SNAKE_STEP) { y_tail += SNAKE_STEP ;  modifyTail(x_tail, y_tail); }
		else snake.pop_front(); // delete the tail of the snake
	}
	else if (y_tail == y_btail) {
		if (x_tail - x_btail > SNAKE_STEP) { x_tail -= SNAKE_STEP; modifyTail(x_tail, y_tail); }
		else if (x_btail - x_tail > SNAKE_STEP) { x_tail += SNAKE_STEP; modifyTail(x_tail, y_tail); }
		else snake.pop_front(); // delete the tail of the snake
	}
	else {
		// error
	}
}
/*This function adds a step to the head of the snake*/
void Snake_game::headStep(Direction direction) {
	// get current head
	int x_head = snake.at(getSize()-1).front(), y_head = snake.at(getSize()-1).back();
	switch(direction) {
		case RIGHT :
			if (snake_direction == UP || snake_direction == DOWN) addNewHead(x_head + SNAKE_STEP, y_head);
			else if (snake_direction == RIGHT) modifyHead(x_head + SNAKE_STEP, y_head);
			break;
		case LEFT :
			if (snake_direction == UP || snake_direction == DOWN) addNewHead(x_head - SNAKE_STEP, y_head);
			else if (snake_direction == LEFT) modifyHead(x_head - SNAKE_STEP, y_head);
			break;
		case UP :
			if (snake_direction == RIGHT || snake_direction == LEFT) addNewHead(x_head , y_head - SNAKE_STEP);
			else if (snake_direction == UP) modifyHead(x_head , y_head - SNAKE_STEP);
			break;
		case DOWN :
			if (snake_direction == RIGHT || snake_direction == LEFT) addNewHead(x_head , y_head + SNAKE_STEP);
			else if (snake_direction == DOWN) modifyHead(x_head , y_head + SNAKE_STEP);
			break;
		default :
			break ;
	}
}
//////////////// test functions
int Snake_game::getElem() {
	return snake.at(0).back();
}

