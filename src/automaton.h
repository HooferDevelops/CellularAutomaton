#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class Grid;
class Cell;

class Automaton {
    private:
        sf::RenderWindow window;
        sf::Image mainImage;
        sf::Texture mainTexture;
        sf::Sprite mainSprite;

        sf::Clock clock;

        bool leftMouseDown = false;
        bool rightMouseDown = false;
        int mouseX = 0;
        int mouseY = 0;

        int activeCellSelectionId = 0;

        std::vector<Cell*> cellSelection;

        Grid *grid;

        void mousePlacementCheck();
    public:
        Automaton(int w, int h);
        ~Automaton();

        void update();
        void updateSpriteSize();
        void draw(sf::RenderWindow &window);
        void updateMousePosition();

        void start();
};