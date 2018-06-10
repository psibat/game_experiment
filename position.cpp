#include "position.h"

Position::Position(int y, int x) : y(y), x(x) { }


Position Position::operator+(const Position& other) {
	return Position(this->y + other.y, this->x + other.x);
}

Position Position::operator-(const Position& other) {
	return Position(this->y - other.y, this->x - other.x);
}

bool Position::operator==(const Position& other) {
	return this->y == other.y && this->x == other.x;
}

bool Position::operator!=(const Position& other) {
	return !(*this == other);
}
