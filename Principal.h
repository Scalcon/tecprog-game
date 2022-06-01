#pragma once

#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Fase.h"

class Principal {
private:
    sf::RenderWindow* mainWindow;
    sf::Clock clock;
    Fase fase;
    bool end;

public:
    Principal();
    ~Principal();
    void exec();
};