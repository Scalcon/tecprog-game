#pragma once
#include "Personagem.h"
class Inimigo : public Personagem {
private:
	void movimentar(sf::RenderWindow* window);

public:
	Inimigo(sf::Vector2f pos, sf::Vector2f tam, const string texturePath);
	~Inimigo();

	void atualizar(sf::RenderWindow* window);
};
