#include "Inimigo_didi.h"

void Inimigo_didi::movimentar(sf::RenderWindow* window)
{
	static bool horizontal = false, vertical = false;
	if (!horizontal) {
		shape.move(-2.f, 0.f);
		if (shape.getGlobalBounds().left <= 0.f) {
			horizontal = true;
			shape.setTexture(text2);
		}
	}
	else {
		shape.move(2.f, 0.f);
		if ((shape.getGlobalBounds().left + shape.getGlobalBounds().width) >= window->getSize().x) {
			horizontal = false;
			shape.setTexture(text1);
		}
	}
}

Inimigo_didi::Inimigo_didi(sf::Vector2f pos, sf::Vector2f tam) : Inimigo(pos, tam)
{
	text1 = new sf::Texture();
	if (!text1->loadFromFile("inimigo_didi.png")) {
		delete text1;
		text1 = nullptr;
	}

	text2 = new sf::Texture();
	if (!text2->loadFromFile("inimigo_didi2.png")) {
		delete text2;
		text2 = nullptr;
	}
	shape.setFillColor(sf::Color::White);
	shape.setTexture(text1);
}

Inimigo_didi::~Inimigo_didi()
{
	if (text1)
		delete text1;
	if (text2)
		delete text2;
}

void Inimigo_didi::atualizar(sf::RenderWindow* window)
{
	Inimigo::atualizar(window);
	movimentar(window);
}
