#pragma once

#include <SFML/Graphics.hpp>

class Grid;

class Cell {
    protected:
        int x;
        int y;
        sf::Color color = sf::Color::Black;
        Grid *activeGrid = nullptr;
        bool isFalling = false;
    public:
        // Constructors
        Cell();
        Cell(int x, int y);
        ~Cell();

        // Getters
        int getX();
        int getY();
        virtual sf::Color getColor();
        virtual Grid *getGrid();
        virtual std::string getName();

        // Setters
        virtual void setX(int ix);
        virtual void setY(int iy);
        virtual void setColor(sf::Color color); 
        virtual void setGrid(Grid *grid);

        // Methods
        virtual void update();
};