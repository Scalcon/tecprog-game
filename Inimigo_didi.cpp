#include "Inimigo_didi.h"

void Inimigo_didi::movimentar(sf::RenderWindow* window)
{
	if (!horizontal) {
		StaticObjetos::getGDC()->moverX(this, ESQUERDA, true);
		if (shape.getGlobalBounds().left <= 0.f) {
			horizontal = true;
			shape.setTexture(text2);
		}
	}
	else {
		StaticObjetos::getGDC()->moverX(this, DIREITA, true);
		if ((shape.getGlobalBounds().left + shape.getGlobalBounds().width) >= window->getSize().x) {
			horizontal = false;
			shape.setTexture(text1);
		}
	}
}

Inimigo_didi::Inimigo_didi(sf::Vector2f pos, sf::Vector2f tam, Latinha* latinha) : Inimigo(pos, tam), latinha{ latinha }
{
	horizontal = false;
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
	delete latinha;
}

void Inimigo_didi::mudarDirecao()
{
	Personagem::mudarDirecao();
	horizontal ? horizontal = false : horizontal = true;
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
