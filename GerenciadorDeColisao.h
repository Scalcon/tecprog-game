#pragma once

#include <vector>
#include "Personagem.h"

enum Direcoes { ESQUERDA = 0, DIREITA, CIMA, BAIXO };

class GerenciadorDeColisao
{
private:
	bool inColisao;
	std::vector<Personagem*> listaI;
	Personagem* uniboy;

	bool colisao(Personagem* p, Direcoes d);
public:
	GerenciadorDeColisao();
	~GerenciadorDeColisao();

	void setUniBoy(Personagem* p);
	void inserirPersonagem(Personagem* p);

	void moverX(Personagem* p, Direcoes d);
	void moverY(Personagem* p, Direcoes d);
};