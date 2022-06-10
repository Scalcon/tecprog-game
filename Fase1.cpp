#include "Fase1.h"

Fase1::Fase1(float sX, float sY) : Fase(sX, sY) {}
Fase1::~Fase1() {}

void Fase1::iniciar() {
    int i = 0;
    for (i; i < 10; i++) {
        constroiPlataformas(sf::Vector2f(i * 120.f, i * 70.f));
    }
    constroiJogador(sf::Vector2f(0.0f, 0.0f));
    constroiInimigoDidi(sf::Vector2f(600.0f, 400.0f));
    constroiInimigoPassaro(sf::Vector2f(800.0f, 0.0f));
}