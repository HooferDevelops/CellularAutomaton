#pragma once

#include "cells/cell.h"
#include <SFML/Graphics.hpp>

class Sand: public Cell {
    public:
        Sand(int ix, int iy);
        void update();
        std::string getName();
};