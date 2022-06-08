#include "GerenciadorDeColisao.h"

bool GerenciadorDeColisao::colisao(Personagem* p, Direcoes d)
{
	if (p == uniboy) {
		for (int i = 0; i < listaI.size(); i++) {
			if (p->getRect()->getGlobalBounds().intersects(listaI[i]->getRect()->getGlobalBounds())) {
				if (d == ESQUERDA) {
					p->colidir(listaI[i], ESQUERDA);
					if (listaI[i]->getDir())
						listaI[i]->mudarDirecao();
				}
				else if (d == DIREITA) {
					p->colidir(listaI[i], DIREITA);
					if (!listaI[i]->getDir())
						listaI[i]->mudarDirecao();
				}
				else if (d == BAIXO) {
					listaI[i]->setMostrar(false);
					listaI.erase(listaI.begin() + i);
				}
			}
		}
	}
	else
	{
		if (p->getRect()->getGlobalBounds().intersects(uniboy->getRect()->getGlobalBounds())) {
			if (d == ESQUERDA) {
				p->colidir(uniboy, ESQUERDA);
				if (uniboy->getDir())
					uniboy->mudarDirecao();
			}
			else if (d == DIREITA) {
				p->colidir(uniboy, DIREITA);
				if (!uniboy->getDir())
					uniboy->mudarDirecao();
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

void GerenciadorDeColisao::setUniBoy(Personagem* p)
{
	uniboy = p;
}

void GerenciadorDeColisao::moverX(Personagem* p, Direcoes d) {
	if (d == ESQUERDA) {
		p->getRect()->move(-5.f, 0.f);
	}
	else if (d == DIREITA) {
		p->getRect()->move(5.f, 0.f);
	}
	colisao(p, d);
}

void GerenciadorDeColisao::moverY(Personagem* p, Direcoes d) {
	if (d == CIMA) {
		p->getRect()->move(0.f, p->getGravidade());
	}
	else if (d == BAIXO) {
		p->getRect()->move(0.f, p->getGravidade());
	}
	colisao(p, d);
}