#include "water.h"
#include "grid.h"

#include <iostream>

Water::Water(int ix, int iy) : LiquidCell(ix, iy) {
    sf::Color colorOptions[3] = {
        sf::Color(110, 219, 255),
        sf::Color(110, 204, 255),
        sf::Color(57, 167, 250)
    };

    color = colorOptions[rand() % 3];
}

std::string Water::getName() {
    return "Water";
}

void Water::update() {
    if (activeGrid != nullptr) {
        Grid *grid = activeGrid;

        // Bottom left and bottom right cells
        Cell *bottomLeft = grid->getCell(x-1, y+1);
        Cell *bottomRight = grid->getCell(x+1, y+1);
        Cell *bottom = grid->getCell(x, y+1);
        Cell *left = grid->getCell(x-1, y);
        Cell *right = grid->getCell(x+1, y);

        // Check if bottom cell is air
        // If it is, apply gravity to the sand
        if (bottom != nullptr && bottom->getName() == "Air") {
            velocityY -= 0.1;
        }
        
        // Limit velocity to a maximum of 3
        if (abs(velocityX) > 3) {
            velocityX = 3 * (velocityX / abs(velocityX));
        }

        // Apply air resistance
        velocityX *= 0.99;
        velocityY *= 0.99;

        // Check if bottom left cell is air
        // If it is, apply sliding to the sand
        // If not, check if bottom right cell is air
        if (velocityY == 0 && bottom != nullptr && bottom->getName() != "Air") {
            bool checkLeftFirst = rand() % 2 == 0;

            for (int i = 0; i < 1; i++) {
                if ((i != 0 || checkLeftFirst) && bottomLeft != nullptr && bottomLeft->getName() == "Air") {
                    velocityX -= 1;
                    break;
                }
                
                if ((i == 0 || !checkLeftFirst) && bottomRight != nullptr && bottomRight->getName() == "Air") {
                    velocityX += 1;
                    break;
                }

                if ((i != 0 || checkLeftFirst) && left != nullptr && left->getName() == "Air") {
                    velocityX -= 1;
                    break;
                }

                if ((i == 0 || !checkLeftFirst) && right != nullptr && right->getName() == "Air") {
                    velocityX += 1;
                    break;
                }
            }
        }

        // Move cell in direction of velocity
        // Calculate slope of velocity

        int resultX = x, resultY = y;

        calculateVelocityMovement(resultX, resultY);

        if (resultX != x || resultY != y) {
            grid->setCell(x, y, grid->getCell(resultX, resultY));
            grid->setCell(resultX, resultY, this);
        }
    }
}