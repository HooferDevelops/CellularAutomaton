#pragma once

#include "cells/liquid/liquidcell.h"
#include <SFML/Graphics.hpp>

class Water: public LiquidCell {
    public:
        // Constructors
        Water(int ix, int iy);

        // Getters
        std::string getName();

        // Setters

        // Methods
        virtual Water* clone() const { return new Water(0,0); }
        void update();
};