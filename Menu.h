#pragma once

#include "StaticObjetos.h"

class Menu {
private:

	sf::Font fonte;
	sf::Event evento;
	sf::Text novoJogo, pontos, opcoes, sair, sel;

	void desenhar(sf::RenderWindow* window);

public:
	Menu();
	~Menu();

	Telas executar(sf::RenderWindow* window);
};