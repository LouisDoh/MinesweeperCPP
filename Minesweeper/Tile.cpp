#include "Tile.h"

std::ostream& operator<<(std::ostream& os, const Tile tile) {
    if (!tile.revealed) {
        if (tile.flagged) {
            os << "!";
        }
        else {
            os << "o";
        }
    }
    else {
        if (tile.bomb) {
            os << "B";
        }
        else {
            if (tile.nearBombs == 0) {
                os << ".";
            }
            else {
                os << tile.nearBombs;
            }
        }
    }

    return os;
}