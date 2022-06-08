#pragma once

#include "ListaEntidades.h"
#include "Universitario.h"
#include "Inimigo_didi.h"
#include "StaticObjetos.h"

class Fase {
private:
	ListaEntidades entidades;

public:
	Fase();
	~Fase();
	void iniciar(sf::RenderWindow* window);
};