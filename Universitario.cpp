#include "Universitario.h"

void Universitario::movimentar()
{
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
	{
		shape.move(-5.f, gravidade);
		shape.setTexture(text1);
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
	{
		shape.move(5.f, gravidade);
		shape.setTexture(text2);
	}
	else
	{
		shape.move(0.f, gravidade);
	}
}

void Universitario::pular()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !midPulo)
	{
		midPulo = true;
		gravidade = -20.f;
		shape.move(0.f, gravidade);
		gravidade += 1.0f;
	}
	else if (midPulo)
	{
		if (shape.getPosition().y < 400.f)
		{
			gravidade += 1.0f;
		}
		else
		{
			midPulo = false;
			gravidade = 0.f;
		}
	}
	else
	{
		midPulo = true;
	}
}

Universitario::Universitario(sf::Vector2f pos, sf::Vector2f tam) : Personagem(pos, tam) {
	midPulo = false;
	gravidade = 0.f;

	text1 = new sf::Texture();
	if (!text1->loadFromFile("uniboy.png")) {
		delete text1;
		text1 = nullptr;
	}

	text2 = new sf::Texture();
	if (!text2->loadFromFile("uniboy2.png")) {
		delete text2;
		text2 = nullptr;
	}
	shape.setFillColor(sf::Color::White);
	shape.setTexture(text1);
}

Universitario::~Universitario()
{
	if (text1)
		delete text1;
	if (text2)
		delete text2;
}

void Universitario::atualizar(sf::RenderWindow* window)
{
	movimentar();
	pular();
	Personagem::atualizar(window);
}
