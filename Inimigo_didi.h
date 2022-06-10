#pragma once
#include "Inimigo.h"
#include "Latinha.h"

//#include "StaticObjetos.h"

#define INIMIGO_DIDI_ALTURA 100.0
#define INIMIGO_DIDI_LARGURA 100.0

class Inimigo_didi : public Inimigo {
private:
	void movimentar(sf::RenderWindow* window);
	Latinha* latinha;

public:
	Inimigo_didi(sf::Vector2f pos, Latinha* latinha);
	~Inimigo_didi();

	//void mudarDirecao() override;

	void atualizar(sf::RenderWindow* window);
	void atirarLatinha();
};