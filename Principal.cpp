#include "Principal.h"

Principal::Principal() : mainWindow{ new sf::RenderWindow(sf::VideoMode(800, 600), "poggers") },
end{ false }, fase() {
    exec();
}

Principal::~Principal() {
    delete mainWindow;
}

void Principal::exec() {

    clock.restart();

    sf::Event event;

    while (!end) {

        if (mainWindow->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                end = true;
        }

        sf::Time t = clock.getElapsedTime();
        clock.restart();

        mainWindow->clear();
        fase.iniciar(t.asSeconds(), mainWindow);
        mainWindow->display();

    }
}