#ifndef CELLGENERATOR_H
#define CELLGENERATOR_H

#include "cell.h"
#include <SFML/Graphics.hpp>

class CellGenerator: public Cell {
    public:
        CellGenerator(int ix, int iy);
        void update();
        std::string getName();
        std::string generatorType = "Sand";
};

#endif