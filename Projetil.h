#pragma once
#include "Entidade.h"
class Projetil : public Entidade{
protected:
	const float tempoAtivo;
	sf::Vector2f velocidade;
	sf::Clock clock;
public:
	Projetil(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, const float tempo);
	~Projetil();
	void atualizar(sf::RenderWindow* window);
	void atualizarAtivo();

	virtual void colidir(Entidade* e, int dir);
};

