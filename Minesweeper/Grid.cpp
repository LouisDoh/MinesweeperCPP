#include "Grid.h"
#include <vector>

Grid::Grid() : Grid(0) {
}

Grid::Grid(const int size) : Grid(size,size) {
}

Grid::Grid(const int width, const int height) : width(width), height(height) {
	std::vector<Tile> currentRow;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			currentRow = {}; //reset to empty vector
			currentRow.push_back(Tile());
		}
		this->tileGrid.push_back(currentRow);
	}
}