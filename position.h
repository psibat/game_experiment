#ifndef POSITION_H
#define POSITION_H

struct Position {
	Position(int y, int x);
	Position operator+(const Position &other);
	Position operator-(const Position &other);
	bool operator==(const Position &other);
	bool operator!=(const Position &other);

	int y;
	int x;
};

#endif
