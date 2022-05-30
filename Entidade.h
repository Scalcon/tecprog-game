#pragma once

#include <stdlib.h>
#include <iostream>
#include <SFML/Graphics.hpp>

class Entidade {
protected:
    sf::RectangleShape shape;
    sf::Texture* text;
    float x, y;
public:
    Entidade(float xIn = 0.0f, float yIn = 0.0f, const std::string texturePath = nullptr);
    ~Entidade();
    void atualizar();
    void draw(sf::RenderWindow* window);

};