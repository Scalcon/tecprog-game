#pragma once
#include "Obstaculo.h"

#define ESPINHOS_ALTURA 40
#define ESPINHOS_LARGURA 80

class Espinhos : public Obstaculo {
public:
	Espinhos(sf::Vector2f pos );
	~Espinhos();

	void atualizar(sf::RenderWindow* window);
	void colidir(Entidade* e, int dir);

};

