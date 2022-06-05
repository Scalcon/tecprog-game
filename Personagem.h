#pragma once
#include "Entidade.h"

class Personagem : public Entidade {
protected:
	sf::Vector2f speed;

public:
	Personagem(sf::Vector2f pos, sf::Vector2f tam, const string texturePath, sf::Vector2f vel );
	~Personagem();

	void atualizar(float t);
};