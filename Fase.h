#pragma once

#include "ListaEntidades.h"

class Fase {
private:
	ListaEntidades entidades;

public:
	Fase();
	~Fase();
	void iniciar(float t, sf::RenderWindow* window);
};