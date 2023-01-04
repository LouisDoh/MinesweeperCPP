#pragma once
#include "Tile.h"
#include <vector>
using namespace std;

class Grid {
	private:
		vector<vector<Tile>> tileGrid; //2d vector - we don't know its size at compile time
		int width, height;

	public:
		Grid();
		Grid(const int size);
		Grid(const int width, const int height);
};

