#pragma once

//#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Fase1.h"
#include "Fase.h"
#include "Menu.h"

class Principal {
private:
    // Estruturas SFML
    sf::RenderWindow* mainWindow;
    Telas telaAtual;
    //sf::Clock clock;

    // Classes Telas
    //Fase fase;
    Menu menu;
    Fase1 fase1;

    // Variáveis
    bool end;

public:
    Principal();
    ~Principal();
    void exec();
};