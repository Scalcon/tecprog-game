#pragma once

#include "ListaEntidades.h"
#include "Universitario.h"
#include "Inimigo_didi.h"
#include "InimigoPassaro.h"
#include "Plataforma.h"
#include "StaticObjetos.h"

#define FASE_X 10
#define FASE_Y 10

class Fase {
private:
	ListaEntidades entidades;
	float sizeX, sizeY;

public:
	Fase(float sX, float sY);
	~Fase();
	virtual void iniciar() = 0;
	Telas executar(sf::RenderWindow* window);
	void constroiPlataformas(sf::Vector2f pos);
	void constroiJogador(sf::Vector2f pos);
	void constroiInimigoDidi(sf::Vector2f pos);
	void constroiInimigoPassaro(sf::Vector2f pos);

	//void carregarEntidades(char* ents, int m, int n);
};