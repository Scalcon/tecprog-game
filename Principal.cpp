#include "Principal.h"

Principal::Principal() : mainWindow{new sf::RenderWindow(sf::VideoMode(800, 600), "poggers", sf::Style::Close | sf::Style::Titlebar)},
telaAtual(MENU), fase1(mainWindow->getSize().x, mainWindow->getSize().y) {
    mainWindow->setFramerateLimit(60);
    end = false;
    exec();
}

Principal::~Principal() {
    delete mainWindow;
}

void Principal::exec() {

    //clock.restart();

    while (!end) {

        //sf::Time t = clock.getElapsedTime();
        //clock.restart();
        while (telaAtual == Telas::MENU) {
            mainWindow->clear();
            telaAtual = menu.executar(mainWindow);
            mainWindow->display();
        }

        if (telaAtual == Telas::FASE2)
            end = true;

        fase1.iniciar();
        while (telaAtual == Telas::FASE1) {
            mainWindow->clear();
            telaAtual = fase1.executar(mainWindow);
            mainWindow->display();
        }

    }
}