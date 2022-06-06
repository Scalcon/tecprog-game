#pragma once

#include "ListaEntidades.h"
#include "Jogador.h"
#include "Inimigo.h"

class Fase {
private:
	ListaEntidades entidades;

public:
	Fase();
	~Fase();
	void iniciar(sf::RenderWindow* window);
};