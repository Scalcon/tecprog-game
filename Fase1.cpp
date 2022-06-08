#include "Fase1.h"

Fase1::Fase1(float sX, float sY) : Fase(sX, sY) {}
Fase1::~Fase1() {}

void Fase1::iniciar() {
	Fase::iniciar(1);
}