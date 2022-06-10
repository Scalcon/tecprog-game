#include "InimigoPassaro.h"

InimigoPassaro::InimigoPassaro(sf::Vector2f pos) : Inimigo( pos, sf::Vector2f(INIMIGO_PASSARO_LARGURA, INIMIGO_PASSARO_ALTURA) ){
	text1 = new sf::Texture();
	if (!text1->loadFromFile("inimigo_passaro.png")) {
		delete text1;
		text1 = nullptr;
	}

	text2 = new sf::Texture();
	if (!text2->loadFromFile("inimigo_passaro2.png")) {
		delete text2;
		text2 = nullptr;
	}
	shape.setFillColor(sf::Color::White);
	shape.setTexture(text1);
}

InimigoPassaro::~InimigoPassaro() {
	if (text1)
		delete text1;
	if (text2)
		delete text2;
	text1 = nullptr;
	text2 = nullptr;
}

void InimigoPassaro::movimentar(sf::RenderWindow* window)
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