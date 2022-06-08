#pragma once
#include "Entidade.h"
class Obstaculo : public Entidade {
public:
	Obstaculo(sf::Vector2f pos, sf::Vector2f tam);
	~Obstaculo();
	void atualizar(sf::RenderWindow* window);
};