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

string Grid::horizontalBorder() const {
	string returnString;

	returnString.append("+");
	for (int i = 0; i < this->width; i++) {
		returnString.append("-");
	}
	returnString.append("+");

	return returnString;
}

void Grid::placeBombs(const int noOfBombs) {
	int randRow;
	int randCol;

	for (int i = 0; i < noOfBombs; i++) {
		randRow = rand() % height;
		randCol = rand() % width;

		while (this->tileGrid[randRow][randCol].bomb == true) {
			randRow = rand() % height;
			randCol = rand() % width;
		}

		this->tileGrid[randRow][randCol].bomb = true;
	}

	//bombs won't be distributed truly randomly, some bias towards lower values here
}

ostream& operator<<(ostream& os, const Grid grid) {
	os << grid.horizontalBorder() << endl;

	for (vector<Tile>& row : grid.getTileGrid()) {
		os << "|";
		for (Tile& currentTile : row) {
			os << currentTile;
		}
		os << "|" << endl;
	}

	os << grid.horizontalBorder();

	return os;
}