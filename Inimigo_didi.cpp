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

Inimigo_didi::Inimigo_didi(sf::Vector2f pos, Latinha* latinha) : Inimigo(pos, sf::Vector2f(INIMIGO_DIDI_LARGURA, INIMIGO_DIDI_ALTURA) ),
latinha{ latinha } {
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
	if (latinha)
		latinha->setMostrar(false);
	text1 = nullptr;
	text2 = nullptr;
	latinha = nullptr;
}

void Inimigo_didi::atualizar(sf::RenderWindow* window)
{
	Inimigo::atualizar(window);
	movimentar(window);
	if (latinha) {
		latinha->atualizar(window);
		atirarLatinha();
	}
}

void Inimigo_didi::atirarLatinha(){
	latinha->setPosicao(this->shape.getPosition());
	latinha->setMostrar(true);
}

