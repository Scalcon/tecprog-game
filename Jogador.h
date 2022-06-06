#pragma once
#include "Personagem.h"

class Jogador : public Personagem {
private:
	void movimentar();

public:
	Jogador(sf::Vector2f pos, sf::Vector2f tam, const string texturePath);
	~Jogador();


	void atualizar(sf::RenderWindow* window);
};

