#include "Universitario.h"

void Universitario::movimentar()
{
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
	{
		StaticObjetos::getGDC()->moverX(this, ESQUERDA);
		shape.setTexture(text1);
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
	{
		StaticObjetos::getGDC()->moverX(this, DIREITA);
		shape.setTexture(text2);
	}
	if (getGravidade() < 0)
		StaticObjetos::getGDC()->moverY(this, CIMA);
	else
		StaticObjetos::getGDC()->moverY(this, BAIXO);
}

void Universitario::pular()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !getMidPulo())
	{
		setMidPulo(true);
		setGravidade(-25.f);
		shape.move(0.f, getGravidade());
		setGravidade(getGravidade() + 1.f);
	}
	else if (getMidPulo())
	{
		if (shape.getPosition().y < 400.f)
		{
			setGravidade(getGravidade() + 1.f);
		}
		else
		{
			setMidPulo(false);
			setGravidade(0.f);
		}
	}
	else
	{
		setMidPulo(true);
	}
}

Universitario::Universitario(sf::Vector2f pos) : Personagem(pos, sf::Vector2f(UNIBOY_LARGURA, UNIBOY_ALTURA)) {

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

void Universitario::colidir(Entidade* e, int dir) {
	if (dir == 0) {
		shape.move(5.f, getGravidade());
		e->getRect()->move(-5.f, 0.f);
	}
	else if (dir == 1) {
		shape.move(-5.f, getGravidade());
		e->getRect()->move(5.f, 0.f);
	}
}