#pragma once

#include <stdlib.h>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Entidade {
protected:
    RectangleShape shape;
    Texture* text;
    Vector2f position;
    Vector2f speed;
public:
    Entidade(Vector2f pos, Vector2f vel, const string texturePath = nullptr);
    ~Entidade();
    void atualizar(float t);
    void draw(sf::RenderWindow* window);

};