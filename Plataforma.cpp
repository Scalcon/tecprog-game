#include "Plataforma.h"

Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam, const int tipo) : Obstaculo(pos, tam), tipo{ tipo }{
	if (tipo == 1) {
		//todo carregar texturas corretas
		shape.setFillColor(sf::Color::Blue);
	}
	else {
		shape.setFillColor(sf::Color::Red);
	}
}

Plataforma::~Plataforma() {}

void Plataforma::atualizar(sf::RenderWindow* window) {
	Obstaculo::atualizar(window);
}

void Plataforma::colidir(Entidade* e, int dir)
{
}
