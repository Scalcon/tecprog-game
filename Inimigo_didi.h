#pragma once
#include "Inimigo.h"
#include "Latinha.h"

#include "StaticObjetos.h"

class Inimigo_didi : public Inimigo {
private:
	bool horizontal;
	void movimentar(sf::RenderWindow* window);
	Latinha* latinha;

public:
	Inimigo_didi(sf::Vector2f pos, sf::Vector2f tam, Latinha* latinha);
	~Inimigo_didi();

	void mudarDirecao() override;

	void atualizar(sf::RenderWindow* window);
	void atirarLatinha();
};