#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>

class Grid;

class Cell {
    private:
        int x;
        int y;
        sf::Color color = sf::Color::White;
        Grid *activeGrid = nullptr;
    public:
        // Constructors
        Cell();
        Cell(int x, int y);
        ~Cell();

        // Getters
        int getX();
        int getY();
        sf::Color getColor();
        Grid *getGrid();

        // Setters
        void setX(int ix);
        void setY(int iy);
        void setColor(sf::Color color); 
        void setGrid(Grid *grid);

        // Methods
};

#endif