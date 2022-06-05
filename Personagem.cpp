#include "Personagem.h"

Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, const string texturePath, sf::Vector2f vel) : Entidade(pos, tam, texturePath), speed{ vel } {}
Personagem::~Personagem(){}

void Personagem::atualizar(float t) {
    position += speed * t;
    shape.setPosition(position);
}
