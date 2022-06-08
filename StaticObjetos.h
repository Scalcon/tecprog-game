#pragma once

#include "GerenciadorDeColisao.h"

class StaticObjetos
{
private:
	static GerenciadorDeColisao gerenciador;
public:
	static GerenciadorDeColisao* getGDC();
};