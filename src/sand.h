#ifndef SAND_H
#define SAND_H

#include "cell.h"
#include <SFML/Graphics.hpp>

class Sand: public Cell {
    public:
        Sand(int ix, int iy);
        void update();
        std::string getName();
};

#endif