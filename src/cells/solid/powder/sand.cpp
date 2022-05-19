#include "sand.h"
#include "grid.h"

#include <iostream>
#include <cmath>

Sand::Sand(int ix, int iy) : Cell(ix, iy) {
    sf::Color colorOptions[3] = {
        sf::Color(238, 216, 156),
        sf::Color(231, 209, 151),
        sf::Color(243, 222, 166)
    };

    color = colorOptions[rand() % 3];
}

std::string Sand::getName() {
    return "Sand";
}

void Sand::update() {
    if (activeGrid != nullptr) {
        Grid *grid = activeGrid;

        
        
        // Bottom left and bottom right cells
        Cell *bottomLeft = grid->getCell(x-1, y+1);
        Cell *bottomRight = grid->getCell(x+1, y+1);
        Cell *bottom = grid->getCell(x, y+1);

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
                    velocityX -= .01;
                    break;
                }
                
                if ((i == 0 || !checkLeftFirst) && bottomRight != nullptr && bottomRight->getName() == "Air") {
                    velocityX += .01;
                    break;
                }
            }
        }

        // Move cell in direction of velocity
        // Calculate slope of velocity

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
        

        int resultX = x, resultY = y;

        for (float n = 0; n <= std::fabs(max); n++) {
            currentX += slopeRun;
            currentY += slopeRise;

            if (grid->getCell((int) currentX, (int) currentY) != nullptr && grid->getCell((int) currentX, (int) currentY)->getName() != "Air") {
                // If the cell is solid, stop moving the cell
                velocityX = 0;
                velocityY = 0;
                break;
            } else if (grid->getCell((int) currentX, (int) currentY) == nullptr) {
                velocityX = 0;
                velocityY = 0;
                break;
            }

            if (grid->getCell((int) currentX, (int) currentY) != nullptr && grid->getCell((int) currentX, (int) currentY)->getName() == "Air") {
                // If the cell is air, move the cell
                resultX = (int) currentX;
                resultY = (int) currentY;
            }
        }

        if (resultX != x || resultY != y) {
            grid->setCell(x, y, new Cell(x, y));
            grid->setCell(resultX, resultY, this);
        }
    }
}