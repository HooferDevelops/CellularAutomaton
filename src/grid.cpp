#include "grid.h"
#include "cells/cell.h"
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

    // Write blank cells to the grid
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            grid[i][j] = new Cell(i, j);
        }
    }
}

tuple<int, int> Grid::getSize() {
    return make_tuple(width, height);
}

Cell *Grid::getCell(int x, int y) {
    // Check if the coordinates are valid
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return nullptr;
    }
    return grid[x][y];
}

void Grid::setCell(int x, int y, Cell *cell) {
    if (cell == nullptr) {
        grid[x].erase(grid[x].begin() + y);
        return;
    }

    Grid *oldGrid = cell->getGrid();

    if (oldGrid != nullptr) {
        //oldGrid->setCell(cell->getX(), cell->getY(), nullptr);
    }

    grid[x][y] = cell;

    cell->setX(x);
    cell->setY(y);
    cell->setGrid(this);
}

void Grid::writeToImage(sf::Image *img) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (getCell(i, j) != nullptr) {
                img->setPixel(i, j, getCell(i, j)->getColor());
            }
        }
    }
}

void Grid::update() {
    vector<Cell *> cellsToUpdate;
    cellsToUpdate.resize(width * height);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (getCell(i, j) != nullptr) {
                cellsToUpdate[i * height + j] = getCell(i, j);
            }
        }
    }

    for (int i = cellsToUpdate.size() - 1; i > 0; i--) {
        if (cellsToUpdate[i] != nullptr) {
            cellsToUpdate[i]->update();
        }
    }
}