#pragma once
#include "Inimigo.h"

#define INIMIGO_PASSARO_ALTURA 150.0
#define INIMIGO_PASSARO_LARGURA 150.0

class InimigoPassaro : public Inimigo {
public:
	InimigoPassaro(sf::Vector2f pos);
	~InimigoPassaro();

	void movimentar(sf::RenderWindow* window);


};

