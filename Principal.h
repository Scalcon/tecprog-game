#pragma once

#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "ListaEntidades.h"

class Principal {
private:
    RenderWindow* mainWindow;
    Clock clock;
    ListaEntidades poggers;
    bool end;

public:
    Principal();
    ~Principal();
    void exec();
};