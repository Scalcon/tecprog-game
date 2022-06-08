#pragma once

#include "Projetil.h"

#define TEMPO_PROJETIL_LATINHA 2.0

class Latinha : public Projetil {

public:
	Latinha(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, const float tempo = TEMPO_PROJETIL_LATINHA);

	void colidir(Entidade* e, int dir);

};

