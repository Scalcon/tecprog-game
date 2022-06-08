#pragma once
#include "Entidade.h"

class Personagem : public Entidade {

	bool midPulo;
	float gravidade;

public:
	Personagem(sf::Vector2f pos, sf::Vector2f tam);
	~Personagem();

	float getGravidade();

	virtual void mudarDirecao();

	void colisaoPersonagemBorda(sf::RenderWindow* window);

	void atualizar(sf::RenderWindow* window);
};