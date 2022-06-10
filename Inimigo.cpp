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

void Inimigo::mudarDirecao() {
	Personagem::mudarDirecao();
}

void Inimigo::colidir(Entidade* p, Entidade* e, int dir) {
	if (dir == 0) {
		shape.move(5.f, getGravidade());
		mudarDirecao();
	}
	else if (dir == 1) {
		shape.move(-5.f, getGravidade());
		mudarDirecao();
	}
}
