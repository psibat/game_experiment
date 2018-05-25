#include "logger.h"

#include <iomanip>
#include <sstream>
#include <ios>

Logger::Logger() {
	log_file.open("log", std::ios::app);
	write_log("--Started--");
}

Logger::~Logger() {
	write_log("--Closed--");
	log_file.close();
}

void Logger::write_log(std::string message) {
	log_file << get_date_string() << " | " << message << std::endl;
}

std::string Logger::get_date_string() {
	auto t = std::time(nullptr);
	auto tm = *std::localtime(&t);

	std::ostringstream oss;
	oss << std::put_time(&tm, "%d.%m.%y-%H:%M:%S");

	return oss.str();
}

void log(std::string message) {
	static Logger logger;
	logger.write_log(message);
}
