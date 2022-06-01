#include "Entidade.h"

Entidade::Entidade(Vector2f pos, Vector2f vel, const string texturePath) : position{ pos }, speed{vel},
text{ nullptr } {

    if (texturePath != "") {
        text = new sf::Texture();
        //todo carregar textura
        text->loadFromFile(texturePath);
    }
    
    shape.setTexture(text);
    shape.setSize(Vector2f(200.0f, 200.0f));
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