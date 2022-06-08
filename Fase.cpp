#include "Fase.h"

Fase::Fase(float sX, float sY) : sizeX(sX), sizeY(sY) {
    //entidades.insert(new Entidade(sf::Vector2f(800.0f, 0.0f), sf::Vector2f(800.0f, 200.0f), ""));
    //Personagem* u = new Universitario(sf::Vector2f(200.0f, 400.0f), sf::Vector2f(200.0f, 200.0f));
    //Latinha* latinha = new Latinha(sf::Vector2f(200.0f, 400.0f), sf::Vector2f(100.0f, 100.0f), sf::Vector2f(10.0f, 0.0f));
    //Personagem* i = new Inimigo_didi(sf::Vector2f(700.0f, 400.0f), sf::Vector2f(200.0f, 200.0f), nullptr);
    //entidades.insert(i);
    //entidades.insert(latinha);
    //entidades.insert(u);
    //StaticObjetos::getGDC()->setUniBoy(u);
    //StaticObjetos::getGDC()->inserirPersonagem(i);
}

Fase::~Fase() {
    entidades.deleteAll();
}

void Fase::iniciar(const int numFase) {
    switch (numFase) {
    case 1:
        //int tamPlataformaX = sizeX/10;
        int i = 0;
        for (i; i < 10; i++) {
            constroiPlataformas(sf::Vector2f(i * 120.f, i * 70.f));
        }
        constroiJogador(sf::Vector2f(400.0f, 400.0f));
        constroiInimigoDidi(sf::Vector2f(600.0f, 400.0f));
        break;

    }
}

Telas Fase::executar(sf::RenderWindow* window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return Telas::FASE2;
    entidades.atualizarEntidades(window);
    entidades.drawAll(window);
    return Telas::FASE1;
}

void Fase::constroiPlataformas(sf::Vector2f pos) {
    entidades.insert(new Plataforma(pos, sf::Vector2f(100.f, 50.f), 1));
}

void Fase::constroiJogador(sf::Vector2f pos) {
    Personagem* uniboy = new Universitario(pos, sf::Vector2f(200.f, 200.f));
    entidades.insert(uniboy);
    StaticObjetos::getGDC()->setUniBoy(uniboy);
}

void Fase::constroiInimigoDidi(sf::Vector2f pos) {
    //Latinha* latinha = new Latinha(sf::Vector2f(200.0f, 400.0f), sf::Vector2f(100.0f, 100.0f), sf::Vector2f(10.0f, 0.0f));
    Personagem* inimigo = new Inimigo_didi(sf::Vector2f(200.0f, 400.0f), sf::Vector2f(200.0f, 200.0f), nullptr);
    entidades.insert(inimigo);
    StaticObjetos::getGDC()->inserirPersonagem(inimigo);
    //entidades.insert(latinha);
}