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

        int temperature = 0;

        int velocityX = 0;
        int velocityY = 0;
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

        virtual int getTemperature();

        virtual int getVelocityX();
        virtual int getVelocityY();


        // Setters
        virtual void setX(int ix);
        virtual void setY(int iy);
        virtual void setColor(sf::Color color); 
        virtual void setGrid(Grid *grid);

        virtual void setTemperature(int temp);

        virtual void setVelocityX(int ix);
        virtual void setVelocityY(int iy);

        // Methods
        virtual void update();
};