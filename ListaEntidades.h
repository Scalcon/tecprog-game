#pragma once
#include "Entidade.h"

//using namespace sf;

class ListaEntidades {
private:
	class ElementoLista {
	private:
		ElementoLista* prev;
		ElementoLista* next;
		Entidade* info;
	public:
		ElementoLista(Entidade* Info = nullptr, ElementoLista* Prev = nullptr, ElementoLista* Next = nullptr);
		~ElementoLista();

		void setInfo(Entidade* Info);
		Entidade* getInfo();
		
		void setPrev(ElementoLista* Prev);
		ElementoLista* getPrev();

		void setNext(ElementoLista* Next);
		ElementoLista* getNext();


	};

	ElementoLista* current;
	ElementoLista* head;
	ElementoLista* tail;

public:
	ListaEntidades();
	~ListaEntidades();

	void insert(Entidade* info);
	void deleteAll();
	Entidade* moveHead();
	Entidade* moveNext();

	void atualizarEntidades(sf::RenderWindow* window);
	void drawAll(sf::RenderWindow* window);
	void destroyAll();


};