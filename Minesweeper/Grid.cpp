#include "Grid.h"

Grid::Grid(const int width, const int height, const int noOfBombs) : width(width), height(height) {
	std::vector<Tile> currentRow;

	for (int row = 0; row < height; row++) {
		currentRow = {}; //reset to empty vector before next row
		for (int col = 0; col < width; col++) {
			currentRow.push_back(Tile());
		}
		tileGrid.push_back(currentRow);
	}
	placeBombs(noOfBombs);
}

Grid::Grid() : Grid(10, 10, 10) {
}

std::string Grid::horizontalBorder() const {
	std::string returnString;

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
	srand(time(NULL)); //without seeding, the same sequence of random numbers is always produced

	for (int i = 0; i < noOfBombs; i++) {
		randRow = rand() % height;
		randCol = rand() % width;

		while (this->tileGrid[randRow][randCol].bomb == true) {
			randRow = rand() % height;
			randCol = rand() % width;
		}

		this->tileGrid[randRow][randCol].bomb = true;
	}

	updateNearbyBombs();
	//bombs won't be distributed truly randomly, some bias towards lower values here
}

void Grid::updateNearbyBombs() {
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			this->tileGrid[row][col].nearBombs = getNearbyBombs(row, col);
		}
	}
}

int Grid::getNearbyBombs(const int row, const int col) const {
	int nearBombs = 0;
	for (int checkRow = row - 1; checkRow < row + 1; checkRow++) {
		if (checkRow >= 0 && checkRow < height) {
			for (int checkCol = col - 1; checkCol < col + 1; checkCol++) {
				if (checkCol >= 0 && checkCol < width) {
					if (this->tileGrid[checkRow][checkCol].bomb) {
						nearBombs += 1;
					}
				}
			}
		}
	}

	return nearBombs;
}

void Grid::flagTile(const int row, const int col) {
	this->tileGrid[row][col].flagged = !this->tileGrid[row][col].flagged;
}

void Grid::clickTile(const int row, const int col) {
	Tile& currentTile = this->tileGrid[row][col];

	currentTile.revealed = true;

	if (currentTile.bomb == false && currentTile.nearBombs == 0) {
		revealZeroes(row, col);
	}
}

void Grid::revealZeroes(const int row, const int col) {
	for (int checkRow = row - 1; checkRow < row+1; checkRow++) {
		if (checkRow >= 0 && checkRow < height) {
			//for the rows either side, if they don't go out-of-bounds
			for (int checkCol = col - 1; checkCol < col + 1; checkCol++) {
				if (checkCol >= 0 && checkCol < height) {
					//for the columns either side, if they don't go out-of-bounds
					
					if (!this->tileGrid[checkRow][checkCol].revealed) {
						//if not already revealed
						this->tileGrid[checkRow][checkCol].revealed = true;
						
						if (this->tileGrid[checkRow][checkCol].nearBombs == 0) {
							revealZeroes(checkRow, checkCol);
						}
					}
				}
			}
		}
	}
}

void Grid::placeBombManual(const int row, const int col) {
	this->tileGrid[row][col].bomb = true;
	updateNearbyBombs();
}

std::ostream& operator<<(std::ostream& out, const Grid& o) {
	out << o.horizontalBorder() << "\n";
	for (auto& row : o.tileGrid) {
		out << "|";
		for (auto& tile : row) {
			out << tile;
		}
		out << "|\n";
	}
	out << o.horizontalBorder();

	return out;
}
