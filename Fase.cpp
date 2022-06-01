#include "Fase.h"

Fase::Fase() {
    entidades.insert(new Entidade(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(50.0f, 5.0f), "uniboy.png"));
    entidades.insert(new Entidade(sf::Vector2f(100.0f, 0.0f), sf::Vector2f(5.0f, 50.0f), "uniboy.png"));
    entidades.insert(new Entidade(sf::Vector2f(380.0f, 100.0f), sf::Vector2f(50.0f, 5.0f), "uniboy.png"));
    entidades.insert(new Entidade(sf::Vector2f(250.0f, 0.0f), sf::Vector2f(5.0f, 50.0f), "uniboy.png"));
    entidades.insert(new Entidade(sf::Vector2f(0.0f, 200.0f), sf::Vector2f(50.0f, 5.0f), "uniboy.png"));
}

Fase::~Fase() {
    entidades.deleteAll();
}

void Fase::iniciar(float t, sf::RenderWindow* window) {
    entidades.atualizarEntidades(t);
    entidades.drawAll(window);
}
