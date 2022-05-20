#pragma once

#include <SFML/Graphics.hpp>

class Grid;

class Cell {
    protected:
        int x;
        int y;
        sf::Color color = sf::Color::Black;
        Grid *activeGrid = nullptr;

        int temperature = 0;
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
        virtual std::string getVariant();

        virtual int getTemperature();

        // Setters
        virtual void setX(int ix);
        virtual void setY(int iy);
        virtual void setColor(sf::Color color); 
        virtual void setGrid(Grid *grid);

        virtual void setTemperature(int temperature);

        // Methods
        virtual Cell* clone() const { return new Cell(); }
        virtual void update();
};