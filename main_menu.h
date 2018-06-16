#include <vector>
#include <string>
#include <string.h>
#include <ncurses.h>

#include "game_state.h"

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

class MainMenu {
	public:
		MainMenu(GameState &state);
		std::string title;
		std::vector<std::string> options;

		void run();
		void process();
		void draw();
	private:
		int option_selected = 0;
		GameState &state;


};

#endif
