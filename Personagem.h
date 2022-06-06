#pragma once
#include "Entidade.h"

class Personagem : public Entidade {
protected:
	//sf::Vector2f speed;

	// Inicializadores
	void inicializar();

public:
	Personagem(sf::Vector2f pos, sf::Vector2f tam, const string texturePath);
	~Personagem();

	void colisaoPersonagemBorda(sf::RenderWindow* window);

	void atualizar(sf::RenderWindow* window);
};