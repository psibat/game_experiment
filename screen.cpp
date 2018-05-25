#include "screen.h"

Screen::Screen() {
	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
}

Screen::~Screen() {
	endwin();
}
