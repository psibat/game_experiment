#include "screen.h"

#include <locale.h>

Screen::Screen() {
	initscr();
	setlocale(LC_ALL, "");
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
}

Screen::~Screen() {
	endwin();
}
