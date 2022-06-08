#include "Fase.h"

Fase::Fase() {
    //entidades.insert(new Entidade(sf::Vector2f(800.0f, 0.0f), sf::Vector2f(800.0f, 200.0f), ""));
    entidades.insert(new Universitario(sf::Vector2f(200.0f, 400.0f), sf::Vector2f(200.0f, 200.0f)));

    Latinha* latinha = new Latinha(sf::Vector2f(200.0f, 400.0f), sf::Vector2f(100.0f, 100.0f), sf::Vector2f(10.0f, 0.0f));
    entidades.insert(new Inimigo_didi(sf::Vector2f(200.0f, 400.0f), sf::Vector2f(200.0f, 200.0f), latinha));
    entidades.insert(latinha);
}

Fase::~Fase() {
    entidades.deleteAll();
}

void Fase::iniciar(sf::RenderWindow* window) {
    entidades.atualizarEntidades(window);
    entidades.drawAll(window);
}
