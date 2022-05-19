#include "automaton.h"
#include "grid.h"
#include "cells/solid/powder/sand.h"
#include "cells/solid/anchored/cellgenerator.h"
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

void Automaton::mousePlacementCheck() {
    if (leftMouseDown) {
        grid->setCell(mouseX, mouseY, new Sand(mouseX, mouseY));
    }
    if (rightMouseDown) {
        grid->setCell(mouseX, mouseY, new Cell(mouseX, mouseY));
    }
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
    //mainSprite.setPosition(
    //    (window.getSize().x - mainSprite.getGlobalBounds().width) / 2,
    //    (window.getSize().y - mainSprite.getGlobalBounds().height) / 2
    //);
}

void Automaton::updateMousePosition() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    mouseX = mousePos.x;
    mouseY = mousePos.y;
    
    float widthRatio = window.getSize().x / (float)mainImage.getSize().x;
    float heightRatio = window.getSize().y / (float)mainImage.getSize().y;
    float highestRatio = widthRatio < heightRatio ? widthRatio : heightRatio;

    mouseX = (mouseX - mainSprite.getGlobalBounds().left) / highestRatio;
    mouseY = (mouseY - mainSprite.getGlobalBounds().top) / highestRatio;

    // Clamp the mouse position to the window
    if (mouseX < 0) {
        mouseX = 0;
    }

    if (mouseY < 0) {
        mouseY = 0;
    }

    if (mouseX >= mainImage.getSize().x) {
        mouseX = mainImage.getSize().x - 1;
    }

    if (mouseY >= mainImage.getSize().y) {
        mouseY = mainImage.getSize().y - 1;
    }
}

void Automaton::start() {
    float dt = 1.f/60.f;
    float time = 0.f;
    bool drawn = false;

    Sand sand(1,1);

    grid->setCell(5, 5, &sand);

    // Create a row of sand
    for (int i = 0; i < 50; i++) {
        //grid->setCell(i+25, 1, new CellGenerator(i, 0));
    }

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

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    leftMouseDown = true;
                }
                if (event.mouseButton.button == sf::Mouse::Right) {
                    rightMouseDown = true;
                }
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    leftMouseDown = false;
                }
                if (event.mouseButton.button == sf::Mouse::Right) {
                    rightMouseDown = false;
                }
            }
        }

        updateMousePosition();
        //mouseX = window.mapPixelToCoords(sf::Mouse::getPosition(window)).x;
        //mouseY = window.mapPixelToCoords(sf::Mouse::getPosition(window)).y;

        //std::cout << mouseX << " " << mouseY << std::endl;

        while (time >= dt) {
            update();
            mousePlacementCheck();
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