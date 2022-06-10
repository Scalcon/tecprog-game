#pragma once
#include "StaticObjetos.h"

#define UNIBOY_ALTURA 100.0
#define UNIBOY_LARGURA 80.0

class Universitario : public Personagem {
private:
	void movimentar();
	void pular();

public:
	Universitario(sf::Vector2f pos);
	~Universitario();


	void atualizar(sf::RenderWindow* window);
	
	void colidir(Entidade* e, int dir);
};

