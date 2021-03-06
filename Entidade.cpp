#include "Entidade.h"

Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam) : position(pos), size(tam) {
    text1 = nullptr;
    text2 = nullptr;
    mostrar = true;
    shape.setPosition(position);
    shape.setSize(size);
}

Entidade::~Entidade() {
}

void Entidade::draw(sf::RenderWindow* window) {
    if (mostrar) {
        window->draw(shape);
    }
}

bool Entidade::getMostrar() {
    return mostrar;
}

void Entidade::setMostrar(const bool val) {
    mostrar = val;
}

void Entidade::setPosicao(sf::Vector2f pos) {
    shape.setPosition(pos);
}

sf::RectangleShape* Entidade::getRect()
{
    return &shape;
}
