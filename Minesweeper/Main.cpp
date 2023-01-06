#include "Tile.h"
#include "Grid.h"
#include <iostream>

using namespace std;

int main() {
    Tile myTile;
    cout << myTile << endl;

    myTile.flagged = true;
    cout << myTile << endl;

    myTile.flagged = false;
    myTile.bomb = true;
    myTile.revealed = true;
    cout << myTile << endl;
    
    myTile.bomb = false;
    cout << myTile << endl;

    myTile.nearBombs = 5;
    cout << myTile << endl;

    Grid myGrid(5);
    cout << myGrid << endl;
    myGrid.placeBombs(10);
    cout << myGrid;
}