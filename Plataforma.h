#pragma once
#include "Obstaculo.h"

#define PLATAFORMA_ALTURA 60
#define PLATAFORMA_LARGURA 80

class Plataforma : public Obstaculo {
private:
	const int tipo;
public:
	Plataforma(sf::Vector2f pos, const int tipo);
	~Plataforma();
	void atualizar(sf::RenderWindow* window);

	void colidir(Entidade* e, int dir);
};


