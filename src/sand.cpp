#include "sand.h"
#include "grid.h"

#include <iostream>

Sand::Sand(int ix, int iy) : Cell(ix, iy) {
    sf::Color colorOptions[3] = {
        sf::Color(238, 216, 156),
        sf::Color(231, 209, 151),
        sf::Color(243, 222, 166)
    };

    color = colorOptions[rand() % 3];
}

std::string Sand::getName() {
    return "Sand";
}

void Sand::update() {
    if (activeGrid != nullptr) {
        Grid *grid = activeGrid;
        
        // Bottom left and bottom right cells
        Cell *bottomLeft = grid->getCell(x-1, y+1);
        Cell *bottomRight = grid->getCell(x+1, y+1);
        Cell *bottom = grid->getCell(x, y+1);

        if (bottom != nullptr && bottom->getName() == "Air") {
            isFalling = true;
            grid->setCell(x, y, new Cell(x, y));
            grid->setCell(x, y+1, this);
            return;
        }

        if (bottomLeft != nullptr && bottomLeft->getName() == "Air") {
            isFalling = true;
            grid->setCell(x, y, new Cell(x, y));
            grid->setCell(x-1, y+1, this);
            return;
        }

        if (bottomRight != nullptr && bottomRight->getName() == "Air") {
            isFalling = true;
            grid->setCell(x, y, new Cell(x, y));
            grid->setCell(x+1, y+1, this);
            return;
        }

        isFalling = false;
    }
}