#include "Inimigo.h"

void Inimigo::movimentar(sf::RenderWindow* window)
{
	static bool horizontal = false, vertical = false;
	if (!horizontal) {
		shape.move(-2.f, 0.f);
		if (shape.getGlobalBounds().left <= 0.f)
			horizontal = true;
	}
	else {
		shape.move(2.f, 0.f);
		if ((shape.getGlobalBounds().left + shape.getGlobalBounds().width) >= window->getSize().x)
			horizontal = false;
	}

	if (!vertical) {
		shape.move(0.f, -0.5f);
		if (shape.getGlobalBounds().top <= 0.f)
			vertical = true;
	}
	else {
		shape.move(0.f, 0.5f);
		if ((shape.getGlobalBounds().top + shape.getGlobalBounds().height) >= window->getSize().y)
			vertical = false;
	}
}

Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, const string texturePath)
	: Personagem(pos, tam, texturePath) {
}

Inimigo::~Inimigo()
{
}

void Inimigo::atualizar(sf::RenderWindow* window)
{
	movimentar(window);
	Personagem::atualizar(window);
}
