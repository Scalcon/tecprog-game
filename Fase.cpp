#include "Fase.h"

Fase::Fase() {
    //entidades.insert(new Entidade(sf::Vector2f(800.0f, 0.0f), sf::Vector2f(800.0f, 200.0f), ""));
    entidades.insert(new Jogador(sf::Vector2f(200.0f, 400.0f), sf::Vector2f(200.0f, 200.0f)));
    entidades.insert(new Inimigo(sf::Vector2f(200.0f, 400.0f), sf::Vector2f(200.0f, 200.0f)));
}

Fase::~Fase() {
    entidades.deleteAll();
}

void Fase::iniciar(sf::RenderWindow* window) {
    entidades.atualizarEntidades(window);
    entidades.drawAll(window);
}
