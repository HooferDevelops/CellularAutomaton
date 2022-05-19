#ifndef CELLGENERATOR_H
#define CELLGENERATOR_H

#include "cells/cell.h"
#include <SFML/Graphics.hpp>

class CellGenerator: public Cell {
    public:
        // Constructors
        CellGenerator(int ix, int iy);

        // Getters
        std::string getName();

        // Setters

        // Methods
        void update();

        // Variables
        std::string generatorType = "Sand";
};

#endif