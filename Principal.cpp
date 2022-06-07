#include "Principal.h"

Principal::Principal() {
    mainWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "poggers");
    mainWindow->setFramerateLimit(60);
    end = false;
    exec();
}

Principal::~Principal() {
    delete mainWindow;
}

void Principal::exec() {

    //clock.restart();

    sf::Event event;

    while (!end) {

        if (mainWindow->pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                end = true;
        }

        //sf::Time t = clock.getElapsedTime();
        //clock.restart();

        mainWindow->clear();
        fase.iniciar(mainWindow);
        mainWindow->display();

    }
}