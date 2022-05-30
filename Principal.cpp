#include "Principal.h"

Principal::Principal() : mainWindow{ new sf::RenderWindow(sf::VideoMode(800, 600), "poggers") },
poggers { 0, 0, "uniboy.png" } {
    exec();
}

Principal::~Principal() {
    delete mainWindow;
}

void Principal::exec() {
    while (true) {
        mainWindow->clear();
        poggers.atualizar();
        poggers.draw(mainWindow);
        mainWindow->display();
    }
}