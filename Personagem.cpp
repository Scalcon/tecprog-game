#include "Personagem.h"

void Personagem::inicializar() {
	shape.setPosition(position.x, position.y);
}

Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, const string texturePath) :
    Entidade(pos, tam, texturePath) {
	inicializar();
}

Personagem::~Personagem(){
}

void Personagem::colisaoPersonagemBorda(sf::RenderWindow* window)
{
	if (shape.getGlobalBounds().left <= 0.f)
	{
		shape.setPosition(1.f, shape.getGlobalBounds().top);
	}
	else if ((shape.getGlobalBounds().left + shape.getGlobalBounds().width) >= window->getSize().x)
	{
		shape.setPosition(window->getSize().x - shape.getGlobalBounds().width - 1.f, shape.getGlobalBounds().top);
	}

	if (shape.getGlobalBounds().top <= 0.f)
	{
		shape.setPosition(shape.getGlobalBounds().left, 1.f);
		
	}
	else if ((shape.getGlobalBounds().top + shape.getGlobalBounds().height) >= (window->getSize().y))
	{
		shape.setPosition(shape.getGlobalBounds().left, window->getSize().y - shape.getGlobalBounds().height - 1.f);
	}
}

void Personagem::atualizar(sf::RenderWindow* window) {
	colisaoPersonagemBorda(window);
}
