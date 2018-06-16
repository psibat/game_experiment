#include "main_menu.h"
 
MainMenu::MainMenu(GameState &state) : state(state) {

	title = "-Hands of the Philosopher-";
	options.push_back("Play");
	options.push_back("Quit");

	int desired = 20;
	for (auto &option : options) {
		int padding = desired - option.size();
		int lpadding = padding / 2;
		int rpadding = (padding / 2) + (padding % 2);
		std::string slpadding(lpadding, ' ');
		std::string srpadding(rpadding, ' ');
		option = slpadding + option + srpadding;
	}
}

void MainMenu::run() {
	while (state == GameState::MAIN_MENU) {
		draw();
		process();
	}
}

void MainMenu::draw() {
	erase();
	int height, width;
	getmaxyx(stdscr, height, width);

	mvaddstr(height/2 - (options.size() + 1), (width/2) - (title.size()/2), title.c_str());
	for (std::vector<std::string>::size_type i = 0; i != options.size(); i++) {
		bool selected = (int) i == option_selected;
		std::string option = options.at(i);
		if (selected) attron(A_STANDOUT);
		mvaddstr(height/2 + ((i + 1) * 2) - (options.size() + 1), (width/2) - (options.at(i).size()/2),
				option.c_str());
		if (selected) attroff(A_STANDOUT);
	}

}

void MainMenu::process() {
	int ch = getch();
	if (ch == 10) {
		if (option_selected == 0) {
			state = GameState::GAMEPLAY;
		} else if (option_selected == 1) {
			state = GameState::STOP;
		}
	} else if(ch == KEY_UP) {
		if (option_selected != 0) {
			option_selected--;
		}
	} else if(ch == KEY_DOWN) {
		if (option_selected != (int) options.size() - 1) {
			option_selected++;
		}
	} 
}
