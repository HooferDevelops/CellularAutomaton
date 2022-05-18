#pragma once

class Cell;
#include <SFML/Graphics.hpp>

#include <vector>
#include <tuple>

using namespace std;

class Grid {
    private:
        int width;
        int height;
        vector<vector<Cell*>> grid;
    public:
        // Constructors
        Grid(int w, int h);
        ~Grid();

        // Getters
        Cell *getCell(int x, int y);
        tuple<int, int> getSize();

        // Setters
        void setCell(int x, int y, Cell *cell);
        void setSize(int w, int h);

        // Methods
        void writeToImage(sf::Image *tex);
        void update();
};