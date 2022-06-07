#pragma once
#include "Personagem.h"

class Jogador : public Personagem {
private:
	bool midPulo;
	float gravidade;

	void movimentar();
	void pular();

public:
	Jogador(sf::Vector2f pos, sf::Vector2f tam);
	~Jogador();


	void atualizar(sf::RenderWindow* window);
};

