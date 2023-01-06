#include "Tile.h"
#include "Grid.h"
#include <iostream>

using namespace std;

int main() {
    Grid myGrid(5);
    myGrid.placeBombManual(0, 0);

    cout << myGrid << endl;
    myGrid.clickTile(4, 4);
    cout << myGrid;
}