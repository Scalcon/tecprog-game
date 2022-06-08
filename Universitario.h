#pragma once
#include "StaticObjetos.h"

class Universitario : public Personagem {
private:
	void movimentar();
	void pular();

public:
	Universitario(sf::Vector2f pos, sf::Vector2f tam);
	~Universitario();


	void atualizar(sf::RenderWindow* window);
	
	void colidir(Entidade* e, int dir);
};

