#include "grid.h"
#include "cell.h"
#include <iostream>

Grid::Grid(int w = 10, int h = 10) {
    setSize(w, h);
}

Grid::~Grid() {
    grid.clear();
}

void Grid::setSize(int w, int h) {
    width = w;
    height = h;

    // Clear the grid
    grid.clear();

    // Resize the grid
    grid.resize(width);
    for (int i = 0; i < width; i++) {
        grid[i].resize(height);
    }
}

tuple<int, int> Grid::getSize() {
    return make_tuple(width, height);
}

Cell *Grid::getCell(int x, int y) {
    return &grid[x][y];
}

void Grid::setCell(int x, int y, Cell *cell) {
    if (cell == nullptr) {
        grid[x].erase(grid[x].begin() + y);
        return;
    }

    Grid *oldGrid = cell->getGrid();

    if (oldGrid != nullptr) {
        std::cout << "Cell already has a grid" << std::endl;
        std::cout << cell->getX() << " " << cell->getY() << std::endl;
        std::cout << cell->getGrid()->height;
        oldGrid->setCell(cell->getX(), cell->getY(), nullptr);
    }

    grid[x][y] = *cell;

    cell->setX(x);
    cell->setY(y);
    cell->setGrid(this);
}

void Grid::writeToImage(sf::Image *img) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            img->setPixel(i, j, getCell(i, j)->getColor());
        }
    }
}