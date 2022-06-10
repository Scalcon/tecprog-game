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

Telas Fase::executar(sf::RenderWindow* window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return Telas::FASE2;
    entidades.atualizarEntidades(window);
    entidades.drawAll(window);
    return Telas::FASE1;
}

void Fase::constroiPlataformas(sf::Vector2f pos) {
    entidades.insert(new Plataforma(pos, 1));
}

void Fase::constroiJogador(sf::Vector2f pos) {
    Personagem* uniboy = new Universitario(pos);
    entidades.insert(uniboy);
    StaticObjetos::getGDC()->setUniBoy(uniboy);
}

void Fase::constroiInimigoDidi(sf::Vector2f pos) {
    //Latinha* latinha = new Latinha(sf::Vector2f(200.0f, 400.0f), sf::Vector2f(100.0f, 100.0f), sf::Vector2f(10.0f, 0.0f));
    Personagem* inimigo = new Inimigo_didi(pos, nullptr);
    entidades.insert(inimigo);
    StaticObjetos::getGDC()->inserirPersonagem(inimigo);
    //entidades.insert(latinha);
}

void Fase::constroiInimigoPassaro(sf::Vector2f pos) {
    Personagem* inimigo = new InimigoPassaro(pos);
    entidades.insert(inimigo);
    StaticObjetos::getGDC()->inserirPersonagem(inimigo);
}

void Fase::constroiEspinhos(sf::Vector2f pos) {
    entidades.insert(new Espinhos(pos));
}
