#include "GerenciadorDeColisao.h"

bool GerenciadorDeColisao::colisao(Personagem* p, Direcoes d)
{
	for (auto e : listaI) {
		if (p == e)
			continue;
		if (p->getRect()->getGlobalBounds().intersects(e->getRect()->getGlobalBounds())) {
			if (d == ESQUERDA) {
				p->getRect()->move(5.f, p->getGravidade());

			}
			else if (d == DIREITA) {
				p->getRect()->move(-5.f, p->getGravidade());
				p->mudarDirecao();
				e->mudarDirecao();
			}
		}
	}
	return false;
}

GerenciadorDeColisao::GerenciadorDeColisao()
{
	inColisao = false;
	uniboy = nullptr;
}

GerenciadorDeColisao::~GerenciadorDeColisao()
{
}

void GerenciadorDeColisao::inserirPersonagem(Personagem* p)
{
	listaI.push_back(p);
}

void GerenciadorDeColisao::moverX(Personagem* p, Direcoes d) {
	if (d == ESQUERDA) {
		p->getRect()->move(-5.f, p->getGravidade());
		colisao(p, d);
	}
	else if (d == DIREITA) {
		p->getRect()->move(5.f, p->getGravidade());
		colisao(p, d);
	}
}

void GerenciadorDeColisao::moverY(Personagem* p, Direcoes d) {
	if (d == CIMA) {
		p->getRect()->move(0.f, p->getGravidade());
	}
	else if (d == BAIXO) {
		p->getRect()->move(0.f, p->getGravidade());
	}
}