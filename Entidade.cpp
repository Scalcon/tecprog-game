#include "Entidade.h"

Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam) : position(pos), size(tam) {
    mostrar = true;
    shape.setPosition(pos);
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
