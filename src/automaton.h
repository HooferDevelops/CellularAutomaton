#pragma once

#include <SFML/Graphics.hpp>

class Grid;

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