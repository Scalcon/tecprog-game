#include "ListaEntidades.h"
//métodos lista entidades
ListaEntidades::ListaEntidades() : current{ nullptr }, head{ nullptr }, tail{ nullptr } {}

ListaEntidades::~ListaEntidades() {
	destroyAll();
}

void ListaEntidades::insert(Entidade* info) {
	if (info) {
		ElementoLista* elem = new ElementoLista(info);
		if (!head) {
			head = elem;
			tail = elem;
		} else {
			tail->setNext(elem);
			elem->setPrev(tail);

			tail = elem;
		}
	}
}

void ListaEntidades::deleteAll() {
	ElementoLista* aux = head;
	current = head;

	while (current != nullptr) {
		aux = current->getNext();
		delete current;

		current = aux;
	}

	head = nullptr;
	current = nullptr;
	tail = nullptr;

}

Entidade* ListaEntidades::moveHead() {
	current = head;
	return current ? current->getInfo() : nullptr;
}

Entidade* ListaEntidades::moveNext() {
	current = current->getNext();
	return current ? current->getInfo() : nullptr;
}

void ListaEntidades::atualizarEntidades(float t) {
	Entidade* e = moveHead();

	while (e) {
		e->atualizar();
		e = moveNext();
	}
}

void ListaEntidades::drawAll(sf::RenderWindow* window) {
	Entidade* e = moveHead();

	while (e) {
		e->draw(window);
		e = moveNext();
	}
}

void ListaEntidades::destroyAll() {
	Entidade* e = moveHead();

	while (e) {
		delete e;
		e = moveNext();
	}

	deleteAll();
}

//métodos da elemento lista
ListaEntidades::ElementoLista::ElementoLista(Entidade* Info, ElementoLista* Prev, ElementoLista* Next) : 
	info{ Info }, prev{ Prev }, next{ Next } {
}

ListaEntidades::ElementoLista::~ElementoLista() {}

void ListaEntidades::ElementoLista::setInfo(Entidade* Info) {
	info = Info;
}

Entidade* ListaEntidades::ElementoLista::getInfo() {
	return info;
}

void ListaEntidades::ElementoLista::setPrev(ElementoLista* Prev) {
	prev = Prev;
}

ListaEntidades::ElementoLista* ListaEntidades::ElementoLista::getPrev() {
	return prev;
}

void ListaEntidades::ElementoLista::setNext(ElementoLista* Next) {
	next = Next;
}

ListaEntidades::ElementoLista* ListaEntidades::ElementoLista::getNext() {
	return next;
}

