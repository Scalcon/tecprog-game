#pragma once
#include "Personagem.h"
#include "StaticObjetos.h"
class Inimigo : public Personagem {
protected:

public:
	Inimigo(sf::Vector2f pos, sf::Vector2f tam);
	~Inimigo();

	void atualizar(sf::RenderWindow* window);
	void mudarDirecao();

	void colidir(Entidade* p, Entidade* e, int dir);
};

