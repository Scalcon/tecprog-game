#include "ListaEntidades.h"
//métodos lista entidades
ListaEntidades::ListaEntidades() : current{ nullptr }, head{ nullptr }, tail{ nullptr } {
}

ListaEntidades::~ListaEntidades() {
	destroyAll();
}

void ListaEntidades::insert(Entidade* info) {
	if (info) {
		ElementoLista* elem = new ElementoLista(info);
		elem->setPrev(nullptr);
		elem->setNext(nullptr);

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

ListaEntidades::ElementoLista* ListaEntidades::moveHead() {
	current = head;
	return current ? current : nullptr;
}

ListaEntidades::ElementoLista* ListaEntidades::moveNext() {
	current = current->getNext();
	return current ? current : nullptr;
}

void ListaEntidades::atualizarEntidades(sf::RenderWindow* window) {
	ElementoLista* e = moveHead();

	while (e) {
		if (e->getInfo()->getMostrar() == false) {
			if (e->getPrev())
				e->getPrev()->setNext(e->getNext());
			if (e->getNext())
				e->getNext()->setPrev(e->getPrev());
			ElementoLista* aux = e->getNext();
			delete e;
			e = aux;
		}
		else {
			e->getInfo()->atualizar(window);
			e = moveNext();
		}
	}
}

void ListaEntidades::drawAll(sf::RenderWindow* window) {
	ElementoLista* e = moveHead();

	while (e) {
		if (e->getInfo()->getMostrar() == false) {
			if (e->getPrev())
				e->getPrev()->setNext(e->getNext());
			if (e->getNext())
				e->getNext()->setPrev(e->getPrev());
			current = e->getNext();
			if (e == head)
				head = current;
			if (e == tail)
				tail = e->getPrev();
			delete e;
			e = current;
		}
		else {
			e->getInfo()->draw(window);
			e = moveNext();
		}
	}
}

void ListaEntidades::destroyAll() {
	ElementoLista* e = moveHead();

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

ListaEntidades::ElementoLista::~ElementoLista() {
	delete info;
}

void ListaEntidades::ElementoLista::setInfo(Entidade* Info) {
	info = Info;
}

Entidade* ListaEntidades::ElementoLista::getInfo() {
	return info ? info : nullptr;
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

