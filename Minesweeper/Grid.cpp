#include "Grid.h"
#include <vector>

Grid::Grid() : Grid(0) {
}

Grid::Grid(const int size) : Grid(size,size) {
}

Grid::Grid(const int width, const int height) : width(width), height(height) {
	std::vector<Tile> currentRow;

	for (int row = 0; row < height; row++) {
		currentRow = {}; //reset to empty vector before next row
		for (int col = 0; col < width; col++) {
			
			currentRow.push_back(Tile());
		}
		this->tileGrid.push_back(currentRow);
	}
}



ostream& operator<<(ostream& os, const Grid grid) {
	os << "+";
	for (int i = 0; i < grid.getWidth(); i++) {
		os << "-";
	}
	os << "+" << endl;

	for (vector<Tile>& row : grid.getTileGrid()) {
		os << "|";
		for (Tile& currentTile : row) {
			os << currentTile;
		}
		os << "|" << endl;
	}

	os << "+";
	for (int i = 0; i < grid.getWidth(); i++) {
		os << "-";
	}
	os << "+";

	return os;
}