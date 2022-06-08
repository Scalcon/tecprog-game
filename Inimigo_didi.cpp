#include "Inimigo_didi.h"

void Inimigo_didi::movimentar(sf::RenderWindow* window)
{
	if (!getDir()) {
		StaticObjetos::getGDC()->moverX(this, ESQUERDA);
		if (shape.getGlobalBounds().left <= 0.f) {
			mudarDirecao();
		}
	}
	else {
		StaticObjetos::getGDC()->moverX(this, DIREITA);
		if ((shape.getGlobalBounds().left + shape.getGlobalBounds().width) >= window->getSize().x) {
			mudarDirecao();
		}
	}
}

Inimigo_didi::Inimigo_didi(sf::Vector2f pos, sf::Vector2f tam, Latinha* latinha) : Inimigo(pos, tam), latinha{ latinha }
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
	latinha->setMostrar(false);
	text1 = nullptr;
	text2 = nullptr;
	latinha = nullptr;
}

void Inimigo_didi::mudarDirecao()
{
	Personagem::mudarDirecao();
}

void Inimigo_didi::atualizar(sf::RenderWindow* window)
{
	Inimigo::atualizar(window);
	movimentar(window);
	atirarLatinha();
	latinha->atualizar(window);
}

void Inimigo_didi::atirarLatinha(){
	latinha->setPosicao(this->shape.getPosition());
	latinha->setMostrar(true);
}

void Inimigo_didi::colidir(Entidade* e, int dir) {
	if (dir == 0) {
		shape.move(5.f, getGravidade());
		//shape.move(e->getRect()->getPosition().x + e->getRect()->getGlobalBounds().width + 5.f, 0.f);
		mudarDirecao();
		//e->getRect()->move(-5.f, 0.f);
	}
	else if (dir == 1) {
		shape.move(-5.f, getGravidade());
		//shape.move(e->getRect()->getPosition().x - 5.f, 0.f);
		mudarDirecao();
		//e->getRect()->move(5.f, 0.f);
	}
}
