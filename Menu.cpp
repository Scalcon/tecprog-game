#include "Menu.h"

void Menu::desenhar(sf::RenderWindow* window)
{
	window->draw(novoJogo);
	window->draw(pontos);
	window->draw(opcoes);
	window->draw(sair);
	window->draw(sel);
}

Menu::Menu() : evento(), fonte()
{
	if (!this->fonte.loadFromFile("fontes//Dosis-Light.ttf"))
	{
		std::cout << "ERRO: fonte não carregada" << "\n";
	}

	novoJogo.setFont(fonte);
	novoJogo.setPosition(300, 200);
	novoJogo.setString("Novo Jogo");

	pontos.setFont(fonte);
	pontos.setPosition(300, 250);
	pontos.setString("Pontos");

	opcoes.setFont(fonte);
	opcoes.setPosition(300, 300);
	opcoes.setString("Opções");

	sair.setFont(fonte);
	sair.setPosition(300, 350);
	sair.setString("Sair");

	sel.setFont(fonte);
	sel.setPosition(270, 200);
	sel.setString(">>");
}

Menu::~Menu()
{
	//delete menu;
}

Telas Menu::executar(sf::RenderWindow* window)
{
	static int i = 1;
	while (window->pollEvent(this->evento))
	{
		switch (i)
		{
		case 1:
			sel.setPosition(270, 200);
			break;
		case 2:
			sel.setPosition(270, 250);
			break;
		case 3:
			sel.setPosition(270, 300);
			break;
		case 4:
			sel.setPosition(270, 350);
			break;
		}


		switch (evento.type)
		{
		case sf::Event::Closed:
			return Telas::FASE2;
			break;
		case sf::Event::KeyPressed:
			sf::Event::KeyEvent botao = evento.key;
			switch (botao.code)
			{
			case sf::Keyboard::Escape:
				return Telas::FASE2;
				break;
			case sf::Keyboard::S:
			case sf::Keyboard::Down:
				i >= 4 ? i = 1 : i++;
				break;
			case sf::Keyboard::W:
			case sf::Keyboard::Up:
				i <= 1 ? i = 4 : i--;
				break;
			case sf::Keyboard::Enter:
				switch (i)
				{
				case 1:
					return Telas::FASE1;
					break;
				case 2:
					//pts
					break;
				case 3:
					//opt
					break;
				case 4:
					return Telas::FASE2;
					break;
				}
			}
			break;
		}
	}

	desenhar(window);

	return Telas::MENU;
}
