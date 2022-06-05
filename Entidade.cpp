#include "Entidade.h"

Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, const string texturePath) : position{ pos }, size{tam}, text{ nullptr } {

    if (texturePath != "") {
        text = new sf::Texture();
        text->loadFromFile(texturePath);
        shape.setFillColor(sf::Color::White);
    }
    
    shape.setTexture(text);
    shape.setSize(size);
    shape.setOrigin(shape.getSize());

}

Entidade::~Entidade() {
    if(text) 
        delete text;
}

void Entidade::atualizar() {
    shape.setPosition(position);
}

void Entidade::draw(sf::RenderWindow* window) {
    window->draw(shape);
}