#pragma once
#include <iostream>

struct Tile { //just holds data, a class impl. would only have getter and setter functions
	bool bomb = false, flagged = false, revealed = false;
	int nearBombs = 0;
};
std::ostream& operator<<(std::ostream& os, const Tile tile);
