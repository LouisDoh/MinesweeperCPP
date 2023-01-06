#pragma once
#include <iostream>

//just holds data, a class impl. would only have getter and setter functions
struct Tile { 
	bool bomb = false, flagged = false, revealed = true;
	int nearBombs = 0;
};
std::ostream& operator<<(std::ostream& os, const Tile tile);
