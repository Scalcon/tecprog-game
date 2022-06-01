#include "Entidade.h"

Entidade::Entidade(sf::Vector2f pos, sf::Vector2f vel, const string texturePath) : position{ pos }, speed{vel},
text{ nullptr } {

    if (texturePath != "") {
        text = new sf::Texture();
        text->loadFromFile(texturePath);
    }
    
    shape.setTexture(text);
    shape.setSize(sf::Vector2f(200.0f, 200.0f));
    shape.setOrigin(shape.getSize());

}

Entidade::~Entidade() {
    if(text) 
        delete text;
}

void Entidade::atualizar(float t) {
    
    position += speed * t;
    shape.setPosition(position);
}

void Entidade::draw(sf::RenderWindow* window) {
    window->draw(shape);
}