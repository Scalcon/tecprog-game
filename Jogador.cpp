#include "Jogador.h"

void Jogador::movimentar()
{
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
	{
		shape.move(-5.f, 0.f);
		//this->updateColisaoJogadorPlataforma(shape.getPosition().x + 5.f,
		//	shape.getPosition().y);
		//this->updateColisaoJogadorBorda();
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
	{
		shape.move(5.f, 0.f);
		//this->updateColisaoJogadorPlataforma(shape.getPosition().x - 5.f,
		//	shape.getPosition().y);
		//this->updateColisaoJogadorBorda();
	}
	/*else
	{
		shape.move(0.f, 0.f);
	}*/
}

Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, const string texturePath) :
	Personagem(pos, tam, texturePath) {
}

Jogador::~Jogador()
{
}

void Jogador::atualizar(sf::RenderWindow* window)
{
	movimentar();
	Personagem::atualizar(window);
}
