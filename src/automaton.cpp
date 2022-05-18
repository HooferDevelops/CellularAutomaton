#include "automaton.h"
#include "grid.h"
#include "sand.h"
#include "cellgenerator.h"
#include <iostream>

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
    grid->update();
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
    float dt = 1.f/30.f;
    float time = 0.f;
    bool drawn = false;

    CellGenerator sand(1,1);

    grid->setCell(5, 5, &sand);

    CellGenerator sand1(1,1);

    grid->setCell(8, 5, &sand1);

    while (window.isOpen()) {
        time += clock.getElapsedTime().asSeconds();
        clock.restart();

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

        while (time >= dt) {
            update();
            time -= dt;
            drawn = false;
        }

        if (!drawn) {
            window.clear();
            window.draw(mainSprite);
            window.display();
            drawn = true;
        } else {
            sf::sleep(sf::milliseconds(1));
        }


        window.clear();
        window.draw(mainSprite);
        window.display();
    }
}