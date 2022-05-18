#include "cellgenerator.h"
#include "grid.h"
#include "cells/solid/powder/sand.h"

#include <iostream>

CellGenerator::CellGenerator(int ix, int iy) : Cell(ix, iy) {
    color = sf::Color::White;
}

std::string CellGenerator::getName() {
    return "CellGenerator";
}

void CellGenerator::update() {
    if (activeGrid != nullptr) {
        Grid *grid = activeGrid;
        
        Cell *bottom = grid->getCell(x, y+1);

        if (rand() % 4 == 0 && bottom != nullptr && bottom->getName() == "Air") {
            if (generatorType == "Sand") {
                grid->setCell(x, y+1, new Sand(x, y+1));
            }
        }
    }
}