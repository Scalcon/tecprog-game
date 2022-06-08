#include "Projetil.h"

Projetil::Projetil(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f vel, const float tempo) : Entidade(pos, tam), velocidade{ vel },
tempoAtivo{tempo} {
	setMostrar(false);
}

Projetil::~Projetil() {}

void Projetil::atualizar(sf::RenderWindow* window) {
	if (getMostrar()) {
		atualizarAtivo();
	}
}

void Projetil::atualizarAtivo() {

	float t = clock.getElapsedTime().asSeconds();

	if ( t >= tempoAtivo ) {
		setMostrar(false);
		clock.restart();
	}
	else {
		shape.move( velocidade * t);
	}

}
