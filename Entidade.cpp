#include "Entidade.h"

Entidade::Entidade(float xIn, float yIn, const std::string texturePath) : x{ xIn }, y{ yIn }, text{nullptr} {

    if (texturePath != "") {
        text = new sf::Texture();
        text->loadFromFile(texturePath);
    }
    
    shape.setTexture(text);
    std::cout << texturePath << std::endl;
    shape.setSize(sf::Vector2f(200.0f, 200.0f));
    shape.setOrigin(shape.getSize() / 2.0f);

}

Entidade::~Entidade() {
    if(text) 
        delete text;
}

void Entidade::atualizar() {
    x += 8;
    y += 6;

    shape.setPosition(sf::Vector2f(x, y));
}

void Entidade::draw(sf::RenderWindow* window) {
    window->draw(shape);
}