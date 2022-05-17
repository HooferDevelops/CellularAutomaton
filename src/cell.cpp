#include "cell.h"
#include "grid.h"

Cell::Cell() {
    x = 0;
    y = 0;
}

Cell::Cell(int ix, int iy) {
    x = ix;
    y = iy;
}

Cell::~Cell() {
    if (activeGrid != nullptr) {
        activeGrid->setCell(x, y, nullptr);
    }
}

sf::Color Cell::getColor() {
    return color;
}

void Cell::setColor(sf::Color color) {
    this->color = color;
}

void Cell::setX(int ix) {
    x = ix;
}

void Cell::setY(int iy) {
    y = iy;
}

int Cell::getX() {
    return x;
}

int Cell::getY() {
    return y;
}

void Cell::setGrid(Grid *grid) {
    activeGrid = grid;
}

Grid *Cell::getGrid() {
    return activeGrid;
}