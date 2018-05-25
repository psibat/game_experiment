#include <string>
#include <fstream>

#ifndef LOGGER
#define LOGGER

class Logger {
	public:
		Logger();
		~Logger();

		void write_log(std::string message);

	private:
		std::ofstream log_file;

		std::string get_date_string();
};

void log(std::string message);

#endif
