#include "Latinha.h"

Latinha::Latinha(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, const float tempo) : Projetil(pos, tam, vel, tempo){
	/*text1 = new sf::Texture();
	if (!text1->loadFromFile("latinha.png")) {
		delete text1;
		text1 = nullptr;
	}

	shape.setTexture(text1);*/
	shape.setFillColor(sf::Color::White);
}
