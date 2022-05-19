#pragma once

#include "cells/cell.h"
#include <SFML/Graphics.hpp>

class Sand: public Cell {
    public:
        // Constructors
        Sand(int ix, int iy);

        // Getters
        std::string getName();

        // Setters

        // Methods
        void update();
};