#include "automaton.h"
#include "grid.h"

Automaton::Automaton(int w, int h) {
    window.create(sf::VideoMode(w, h), "Cellular Automaton");
    mainImage.create(w, h);
    mainTexture.loadFromImage(mainImage);
    mainSprite.setTexture(mainTexture);
    grid = new Grid(w, h);
}

Automaton::~Automaton() {
    delete grid;
}

void Automaton::update() {
    grid->writeToImage(&mainImage);
    mainTexture.loadFromImage(mainImage);
    mainSprite.setTexture(mainTexture);
    window.draw(mainSprite);
    window.display();
}

void Automaton::updateSpriteSize() {
    // Get scaling ratios
    float widthRatio = window.getSize().x / (float)mainImage.getSize().x;
    float heightRatio = window.getSize().y / (float)mainImage.getSize().y;
    float highestRatio = widthRatio < heightRatio ? widthRatio : heightRatio;
    mainSprite.setScale(highestRatio, highestRatio);
    // Center the sprite
    mainSprite.setPosition(
        (window.getSize().x - mainSprite.getGlobalBounds().width) / 2,
        (window.getSize().y - mainSprite.getGlobalBounds().height) / 2
    );
}

void Automaton::start() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::Resized) {
                sf::FloatRect view(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(view));

                updateSpriteSize();
            }
        }

        update();

        window.clear();
        window.draw(mainSprite);
        window.display();
    }
}