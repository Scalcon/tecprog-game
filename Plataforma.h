#pragma once
#include "Obstaculo.h"

class Plataforma : public Obstaculo {
private:
	const int tipo;
public:
	Plataforma(sf::Vector2f pos, sf::Vector2f tam, const int tipo);
	~Plataforma();
	void atualizar(sf::RenderWindow* window);

	void colidir(Entidade* e, int dir);
};


