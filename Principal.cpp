#include "Principal.h"

Principal::Principal() : mainWindow{ new sf::RenderWindow(VideoMode(800, 600), "poggers") },
end{ false } {
    //todo fase
    poggers.insert(new Entidade(Vector2f(0.0f, 0.0f), Vector2f(50.0f, 5.0f), "uniboy.png"));
    poggers.insert(new Entidade(Vector2f(100.0f, 0.0f), Vector2f(5.0f, 50.0f), "uniboy.png"));
    poggers.insert(new Entidade(Vector2f(380.0f, 100.0f), Vector2f(50.0f, 5.0f), "uniboy.png"));
    poggers.insert(new Entidade(Vector2f(250.0f, 0.0f), Vector2f(5.0f, 50.0f), "uniboy.png"));
    poggers.insert(new Entidade(Vector2f(0.0f, 200.0f), Vector2f(50.0f, 5.0f), "uniboy.png"));

    exec();
}

Principal::~Principal() {
    delete mainWindow;
    poggers.deleteAll();
}

void Principal::exec() {

    clock.restart();

    Event event;

    while (!end) {

        if (mainWindow->pollEvent(event)) {
            if (event.type == Event::Closed)
                end = true;
        }

        Time t = clock.getElapsedTime();
        clock.restart();

        mainWindow->clear();
        poggers.atualizarEntidades(t.asSeconds());
        poggers.drawAll(mainWindow);
        mainWindow->display();

    }
}