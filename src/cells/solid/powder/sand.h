#pragma once

#include "cells/solid/gravitycell.h"
#include <SFML/Graphics.hpp>

class Sand: public GravityCell {
    public:
        // Constructors
        Sand(int ix, int iy);

        // Getters
        std::string getName();

        // Setters

        // Methods
        virtual Sand* clone() const { return new Sand(0,0); }
        void update();
};