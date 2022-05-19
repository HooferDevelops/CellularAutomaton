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

        if (bottom != nullptr && bottom->getName() == "Air") {
            // Add gravity to velocity
            velocityY = -1;
        }

        // Move cell in direction of velocity
        // Calculate slope of velocity
        int finalX = x + velocityX;
        int finalY = y - velocityY;

        // Calculate distance between new positon and old position
        int distance = sqrt(pow(finalX - x, 2) + pow(finalY - y, 2));

        int slope = (finalX-x) == 0 ? 1 : (finalY-y) / (finalX-x);

        // Use a for loop to move the cell in the direction of the velocity
        for (int newX = x; newX <= finalX; newX++) {
            int newY = slope*(newX-x) + y;

            std::cout << "newX: " << newX << " newY: " << newY << std::endl;
            // Check if the cell is solid
            if (grid->getCell(newX, newY) != nullptr && grid->getCell(newX, newY)->getName() != "Air") {
                // If the cell is solid, stop moving the cell
                std::cout << "Cell is solid" << std::endl;
                break;
            }
            
            // Check if the cell is air
            if (grid->getCell(newX, newY) != nullptr && grid->getCell(newX, newY)->getName() == "Air") {
                // If the cell is air, move the cell
                grid->setCell(x, y, new Cell(x, y));
                grid->setCell(newX, newY, this);
                x = newX;
                y = newY;
            }
        }

        /*if (bottom != nullptr && bottom->getName() == "Air") {
            isFalling = true;
            grid->setCell(x, y, new Cell(x, y));
            grid->setCell(x, y+1, this);
            return;
        }*/

        /*if (bottomLeft != nullptr && bottomLeft->getName() == "Air") {
            isFalling = true;
            grid->setCell(x, y, new Cell(x, y));
            grid->setCell(x-1, y+1, this);
            return;
        }

        if (bottomRight != nullptr && bottomRight->getName() == "Air") {
            isFalling = true;
            grid->setCell(x, y, new Cell(x, y));
            grid->setCell(x+1, y+1, this);
            return;
        }

        isFalling = false;*/
    }
}