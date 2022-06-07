#pragma once
#include "Entidade.h"

class Personagem : public Entidade {
protected:
	sf::Texture* text1, * text2;

public:
	Personagem(sf::Vector2f pos, sf::Vector2f tam);
	~Personagem();

	void colisaoPersonagemBorda(sf::RenderWindow* window);

	void atualizar(sf::RenderWindow* window);
};