#include "Plataforma.h"

Plataforma::Plataforma(sf::Vector2f pos, const int tipo) : Obstaculo(pos, sf::Vector2f(PLATAFORMA_LARGURA, PLATAFORMA_ALTURA)), tipo{ tipo }{
	if (tipo == 1) {
		//todo carregar texturas corretas
		text1 = new sf::Texture();
		if (!text1->loadFromFile("plataforma1.png")) {
			delete text1;
			text1 = nullptr;
		}
		shape.setFillColor(sf::Color::White);
		shape.setTexture(text1);
		//shape.setFillColor(sf::Color::Blue);
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
