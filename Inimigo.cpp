#include "Inimigo.h"

Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam)
	: Personagem(pos, tam) {
}

Inimigo::~Inimigo()
{
}

void Inimigo::atualizar(sf::RenderWindow* window)
{
	Personagem::atualizar(window);
}
