#pragma once

#include "cells/cell.h"
#include <SFML/Graphics.hpp>

class LiquidCell: public Cell {
    protected:
        float velocityX = 0;
        float velocityY = 0;

    public:
        // Constructors
        LiquidCell(int ix, int iy);

        // Getters
        virtual float getVelocityX();
        virtual float getVelocityY();
        virtual std::string getVariant();

        // Setters
        virtual void setVelocityX(float velocityX);
        virtual void setVelocityY(float velocityY);

        // Methods
        virtual LiquidCell* clone() const { return new LiquidCell(0,0); }
        virtual void calculateVelocityMovement(int &vX, int &vY);
};