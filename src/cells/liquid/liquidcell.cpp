#include "LiquidCell.h"
#include "grid.h"

#include <iostream>
#include <cmath>

LiquidCell::LiquidCell(int ix, int iy) : Cell(ix, iy) {

}

float LiquidCell::getVelocityX() {
    return velocityX;
}

float LiquidCell::getVelocityY() {
    return velocityY;
}

void LiquidCell::setVelocityX(float ix) {
    velocityX = ix;
}

void LiquidCell::setVelocityY(float iy) {
    velocityY = iy;
}

void LiquidCell::calculateVelocityMovement(int &vX, int &vY) {
    Grid *grid = activeGrid;

    if (velocityX == 0 && velocityY == 0) {
        return;
    }
    
    float currentX = x, currentY = y;
    float velocityResultX = currentX + velocityX, velocityResultY = currentY - velocityY;
    float slopeRun = (velocityResultX - currentX), slopeRise = (velocityResultY - currentY);
    float max = std::max(std::fabs(slopeRun), std::fabs(slopeRise));

    // Check if the line is horizontal or vertical
    if (slopeRun == 0 && slopeRise != 0) {
        max = slopeRise;
        slopeRise /= std::fabs(slopeRise);
    } else if (slopeRise == 0 && slopeRun != 0) {
        max = slopeRun;
        slopeRun /= std::fabs(slopeRun);
    } else if (slopeRun != 0 && slopeRise != 0) {
        slopeRun /= max;
        slopeRise /= max;
    }
    
    for (float n = 0; n <= std::fabs(max); n++) {
        currentX += slopeRun;
        currentY += slopeRise;

        if (grid->getCell((int) currentX, (int) currentY) != nullptr) {
            // If the cell is solid, stop moving the cell
            if (grid->getCell((int) currentX, (int) currentY)->getName() != "Air") {
                velocityX = 0;
                velocityY = 0;
                break;
            }else if (grid->getCell((int) currentX, (int) currentY)->getName() == "Air") {
                // If the cell is air, move the cell
                vX = (int) currentX;
                vY = (int) currentY;
            } else if (grid->getCell((int) currentX, (int) currentY)->getName() == "Liquid" && velocityY < 0) {
                // If the cell is liquid, move the cell
                vX = (int) currentX;
                vY = (int) currentY;
            }
        } else {
            velocityX = 0;
            velocityY = 0;
            break;
        }
    }
}

std::string LiquidCell::getVariant() {
    return "Liquid";
}