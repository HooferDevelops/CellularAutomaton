#ifndef AUTOMATON_H
#define AUTOMATON_H

#include <SFML/Graphics.hpp>

class Grid;

class Automaton {
    private:
        sf::RenderWindow window;
        sf::Image mainImage;
        sf::Texture mainTexture;
        sf::Sprite mainSprite;

        sf::Clock clock;

        Grid *grid;
    public:
        Automaton(int w, int h);
        ~Automaton();

        void update();
        void updateSpriteSize();
        void draw(sf::RenderWindow &window);

        void start();
};

#endif