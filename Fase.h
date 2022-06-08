#pragma once

#include "ListaEntidades.h"
#include "Universitario.h"
#include "Inimigo_didi.h"
#include "Plataforma.h"
#include "StaticObjetos.h"

#define PLATAFORMA_ALTURA 60
#define PLATAFORMA_LARGURA 80

#define FASE_X 10
#define FASE_Y 10

class Fase {
private:
	ListaEntidades entidades;
	float sizeX, sizeY;

public:
	Fase(float sX, float sY);
	~Fase();
	void iniciar(const int numFase);
	Telas executar(sf::RenderWindow* window);
	void constroiPlataformas(sf::Vector2f pos);
	void constroiJogador(sf::Vector2f pos);
	void constroiInimigoDidi(sf::Vector2f pos);

	//void carregarEntidades(char* ents, int m, int n);
};