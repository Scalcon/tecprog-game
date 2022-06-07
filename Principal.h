#pragma once

//#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Fase.h"

class Principal {
private:
    // Estruturas SFML
    sf::RenderWindow* mainWindow;
    //sf::Clock clock;

    // Classes Telas
    Fase fase;

    // Variáveis
    bool end;

public:
    Principal();
    ~Principal();
    void exec();
};