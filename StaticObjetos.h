#pragma once

#include "GerenciadorDeColisao.h"

enum Telas { MENU = 0, FASE1, FASE2 };

class StaticObjetos
{
private:
	static GerenciadorDeColisao gerenciador;
public:
	static GerenciadorDeColisao* getGDC();
};