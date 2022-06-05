#include "Fase.h"

Fase::Fase() {
    entidades.insert(new Entidade(sf::Vector2f(800.0f, 0.0f), sf::Vector2f(800.0f, 200.0f), ""));
    entidades.insert(new Personagem(sf::Vector2f(200.0f, 600.0f), sf::Vector2f(200.0f, 200.0f), "uniboy.png", sf::Vector2f(50.0f, 0.0f)));
    entidades.insert(new Personagem(sf::Vector2f(200.0f, 600.0f), sf::Vector2f(200.0f, 200.0f), "inimigo_didi.png", sf::Vector2f(50.0f, 0.0f)));
    
}

Fase::~Fase() {
    entidades.deleteAll();
}

void Fase::iniciar(float t, sf::RenderWindow* window) {
    entidades.atualizarEntidades(t);
    entidades.drawAll(window);
}
