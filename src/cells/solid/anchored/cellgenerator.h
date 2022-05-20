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
        virtual CellGenerator* clone() const { return new CellGenerator(0,0); }
        void update();

        // Variables
        std::string generatorType = "Sand";
};

#endif