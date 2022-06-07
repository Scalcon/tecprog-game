#pragma once
#include "Inimigo.h"

class Inimigo_didi : public Inimigo {
private:
	void movimentar(sf::RenderWindow* window);

public:
	Inimigo_didi(sf::Vector2f pos, sf::Vector2f tam);
	~Inimigo_didi();

	void atualizar(sf::RenderWindow* window);
};