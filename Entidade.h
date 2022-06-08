#pragma once

#include <stdlib.h>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Entidade {
private:
    bool mostrar;
protected:

    sf::RectangleShape shape;
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Texture* text1, *text2;

public:
    Entidade(sf::Vector2f pos, sf::Vector2f tam);
    virtual ~Entidade();
    virtual void atualizar(sf::RenderWindow* window) = 0;
    void draw(sf::RenderWindow* window);

    sf::RectangleShape* getRect();
    bool getMostrar();
    void setMostrar(const bool val);
    void setPosicao(sf::Vector2f pos);

    virtual void colidir(Entidade* e, int dir) = 0;
};