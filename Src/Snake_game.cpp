#include "Snake_game.h"

Snake_game::Snake_game(int16_t x_head, int16_t y_head, int16_t x_tail, int16_t y_tail) {
	if ( x_head != x_tail && y_head != y_tail ) { // The snake is not horizontal nor vertical
		// Error
	}
	else {
		std::vector< std::pair<int, int> > tmp;
		//tmp.insert(tmp.begin(), std::make_pair(x_head, y_head));
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
