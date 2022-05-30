#pragma once

#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Entidade.h"

class Principal {
private:
    sf::RenderWindow* mainWindow;
    Entidade poggers;

public:
    Principal();
    ~Principal();
    void exec();
};