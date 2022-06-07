#include "Entidade.h"

Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam) : position(pos), size(tam) {
    shape.setPosition(pos);
    shape.setSize(size);
}

Entidade::~Entidade() {
}

void Entidade::draw(sf::RenderWindow* window) {
    window->draw(shape);
}