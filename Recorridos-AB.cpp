#include <queue>
#include <stack>
#include <cstdlib>
#include <iostream>
using namespace std;

class Arbol {
public:
	class Nodo {
	public:
		Nodo* izq;
		Nodo* der;
		char dato;
		Nodo(){}
		Nodo(char dato) {
			this->dato = dato;
			this->izq = NULL;
			this->der = NULL;
		}
	};
private: 
	Nodo* raiz;
public:
	Arbol() {
		this->raiz = new Nodo;//crea espacio para el nodo raiz
	}

	Nodo* getRaiz() { return this->raiz; }
	
	void carga(Nodo* nodo) {  //<----------------------------ARBOL PREDETERMINADO
		cout << endl << "\tArbol predefinido cargado";
		nodo->dato = 'A';
		nodo->izq = new Nodo('B');
		nodo->der = new Nodo('C');
		nodo->izq->izq = new Nodo('D');
		nodo->izq->der = new Nodo('E');
		nodo->der->izq = new Nodo('F');
		nodo->der->der = new Nodo('G');
		nodo->izq->izq->izq = new Nodo('H');
		nodo->izq->izq->der = new Nodo('I');
		nodo->der->izq->izq = new Nodo('J');
		nodo->der->izq->der = new Nodo('K');
	}

	/*
	void carga(Nodo* aux) {  //<---------------------------- CARGA NORMAL DE ARBOL
		char resp, info;
		Nodo* otro;
		cout << "\n\tDame el dato: ";
		cin >> info;
		aux->dato = info;
		cout << endl << " " << aux->dato << "\tTiene nodo por la izq? s/n ";
		cin >> resp;
		if (resp == 's' || resp == 'S') {
			otro = new Nodo;
			aux->izq = otro;
			carga(aux->izq); //recursivo
		}
		else {
			aux->izq = NULL;
		}
		cout << endl << "  " << aux->dato << "\tTiene nodo por la der? s/n ";
		cin >> resp;
		if (resp == 's' || resp == 'S') {
			otro = new Nodo;
			aux->der = otro;
			carga(aux->der);
		}
		else {
			aux->der = NULL;
		}
	}
	*/

	void preOrden(Nodo* nodo) {
		if (nodo != NULL) {
			cout << nodo->dato<<" ";
			preOrden(nodo->izq);
			preOrden(nodo->der);
		}
	}

	void enOrden(Nodo* nodo) {
		if (nodo != NULL) {
			enOrden(nodo->izq);
			cout << nodo->dato << " ";
			enOrden(nodo->der);
		}
	}
	
	void postOrden(Nodo* nodo) {
		if (nodo != NULL) {
			postOrden(nodo->izq);
			postOrden(nodo->der);
			cout << nodo->dato << " ";
		}
	}
	
	void amplitud(Nodo* raiz) {  //Método utilizando una COLA -- AMPLITUD
		queue<Nodo*>fila;
		Nodo* aux=raiz;
		fila.push(aux);
		while (!fila.empty()){  //Mientras la cola no esté vacia
			aux = fila.front();
			cout << aux->dato << " ";
			fila.pop();
			if(aux->izq)
			fila.push(aux->izq);
			if(aux->der)
			fila.push(aux->der);
		}
	}
	/*
	void amplitud(Nodo* raiz) {  //Método utilizando una PILA -- AMPLITUD INVERSA
		stack<Nodo*>fila;
		Nodo* aux = raiz;
		fila.push(aux);
		while (!fila.empty()) {  //Mientras la pila no esté vacia
			aux = fila.top();
			cout << aux->dato << " ";
			fila.pop();
			if (aux->izq)
				fila.push(aux->izq);
			if (aux->der)
				fila.push(aux->der);
		}
	}
	*/	
};

int main() {
	Arbol* a = new Arbol;
	Arbol::Nodo* raiz;
	raiz = a->getRaiz();

	a->carga(raiz); cout << "\t";

	cout << endl << "\n\tMetodo preOrden\n"; cout << "\t";
	a->preOrden(raiz);
	cout << endl << "\n\tMetodo enOrden\n"; cout << "\t";
	a->enOrden(raiz);
	cout << endl << "\n\tMetodo postOrden\n"; cout << "\t";
	a->postOrden(raiz);
	cout << endl << "\n\tMetodo por Amplitud\n"; cout << "\t";
	a->amplitud(raiz);

	cout << endl << endl;
}