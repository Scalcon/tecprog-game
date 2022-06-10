#pragma once
#include "Inimigo.h"

#define INIMIGO_PASSARO_ALTURA 75.0
#define INIMIGO_PASSARO_LARGURA 75.0

class InimigoPassaro : public Inimigo {
public:
	InimigoPassaro(sf::Vector2f pos);
	~InimigoPassaro();

	void movimentar(sf::RenderWindow* window);


};

