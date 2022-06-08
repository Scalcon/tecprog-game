#pragma once
#include "Entidade.h"

class Personagem : public Entidade {

	bool midPulo;
	float gravidade;
	bool horizontal;

public:
	Personagem(sf::Vector2f pos, sf::Vector2f tam);
	~Personagem();

	void setGravidade(float g);
	float getGravidade();

	void setMidPulo(bool m);
	bool getMidPulo();
	const bool getDir() const;

	virtual void mudarDirecao();

	void colisaoPersonagemBorda(sf::RenderWindow* window);

	void atualizar(sf::RenderWindow* window);

	virtual void colidir(Entidade* e, int dir);
};