#include "engine.h"

#include <ncurses.h>

#include "screen.h"
#include "logger.h"
 
Engine::Engine() {
	Screen scr;
}

void Engine::start() {
int height, width;
	getmaxyx(stdscr, height, width);

	int ch;
	while(true) {
		ch = getch();
		if(ch == KEY_LEFT) {
			log("Left input");
		} else if(ch == KEY_RIGHT) {
			log("Right input");
		} else if(ch == KEY_UP) {
			log("Up input");
		} else if(ch == KEY_DOWN) {
			log("Down input");
		} else if(ch == 'q' || ch == 'Q') {
			break;
		}
		erase();
		refresh();
	}
}
