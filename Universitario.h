#pragma once
#include "Personagem.h"

class Universitario : public Personagem {
private:
	bool midPulo;
	float gravidade;

	void movimentar();
	void pular();

public:
	Universitario(sf::Vector2f pos, sf::Vector2f tam);
	~Universitario();


	void atualizar(sf::RenderWindow* window);
};

