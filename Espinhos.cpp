#include "Espinhos.h"
Espinhos::Espinhos(sf::Vector2f pos ) : Obstaculo(pos, sf::Vector2f(ESPINHOS_LARGURA, ESPINHOS_ALTURA)){
	text1 = new sf::Texture();
	if (!text1->loadFromFile("espinhos.png")) {
		delete text1;
		text1 = nullptr;
	}
	shape.setFillColor(sf::Color::White);
	shape.setTexture(text1);
}

Espinhos::~Espinhos(){}

void Espinhos::atualizar(sf::RenderWindow* window) {
	Obstaculo::atualizar(window);
}

void Espinhos::colidir(Entidade* e, int dir){}
