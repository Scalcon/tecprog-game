#pragma once

#include <stdlib.h>
#include <iostream>
#include <SFML/Graphics.hpp>

//using namespace sf;
using namespace std;

class Entidade {
protected:
    sf::RectangleShape shape;
    sf::Texture* text;
    sf::Vector2f position;
    sf::Vector2f speed;
public:
    Entidade(sf::Vector2f pos, sf::Vector2f vel, const string texturePath = nullptr);
    ~Entidade();
    void atualizar(float t);
    void draw(sf::RenderWindow* window);

};