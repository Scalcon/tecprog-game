#pragma once
#include "StaticObjetos.h"

#define UNIBOY_ALTURA 200.0
#define UNIBOY_LARGURA 200.0

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

