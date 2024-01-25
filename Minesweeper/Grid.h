#pragma once
#include "Tile.h"
#include <vector>
#include <iostream>

class Grid {
	friend std::ostream& operator<<(std::ostream& out, const Grid& o);

	private:
		std::vector<std::vector<Tile>> tileGrid; //2d vector - we don't know its size at compile time
		int width, height;
		std::string horizontalBorder() const;

	public:
		Grid();
		Grid(const int width, const int height, int noOfBombs);
		int getWidth() const { return width; }
		int getHeight() const { return height; }
		std::vector<std::vector<Tile>> getTileGrid() const { return tileGrid; }
		
		void placeBombs(const int noOfBombs);
		void updateNearbyBombs();
		int getNearbyBombs(const int row, const int col) const;
		void flagTile(const int row, const int col);
		void clickTile(const int row, const int col);
		void revealZeroes(const int row, const int col);
		void placeBombManual(const int row, const int col); //for testing
};