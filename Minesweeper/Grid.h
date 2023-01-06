#pragma once
#include "Tile.h"
#include <vector>
#include <iostream>
using namespace std;

class Grid {
	private:
		vector<vector<Tile>> tileGrid; //2d vector - we don't know its size at compile time
		int width, height;

	public:
		Grid();
		Grid(const int size);
		Grid(const int width, const int height);
		int getWidth() const { return width; }
		int getHeight() const { return height; }
		vector<vector<Tile>> getTileGrid() const { return tileGrid; }
		string horizontalBorder() const;
		void placeBombs(const int noOfBombs);
		void updateNearbyBombs();
		int getNearbyBombs(const int row, const int col) const;
		void flagTile(const int row, const int col);
		void clickTile(const int row, const int col);
		void revealZeroes(const int row, const int col);
		void placeBombManual(const int row, const int col); //for testing
};

ostream& operator<<(ostream& os, const Grid grid);
