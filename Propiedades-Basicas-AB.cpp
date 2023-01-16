#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <queue>

using namespace std;

class Arbol {
public:
	class Nodo {
	public:
		Nodo* izq;
		Nodo* der;
		char dato;

		Nodo() { }

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
		this->raiz = new Nodo;
	}

	Nodo* getRaiz() {
		return this->raiz;
	}

	void cargaArbol(Nodo* nodo) {
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

	void verArbol(Nodo* arbol, int n) {
		if (arbol == NULL) {
			return;
		}
		verArbol(arbol->der, n + 1);
		for (int i = 0; i < n; i++) {
			cout << "   ";
		}
		cout << arbol->dato << endl;
		verArbol(arbol->izq, n + 1);
	}

	int misterio1(Nodo* nodo) {//Peso del arbol - Nodos terminales
		if (nodo == NULL) {
			return 0;
		}
		else {
			if (nodo->izq == NULL && nodo->der == NULL) {
				//cout << "  NODO: " << nodo->dato;
				return 1;
			}
			else {
				return misterio1(nodo->izq) + misterio1(nodo->der);
			}
		}
	}

	bool misterio2(Nodo* nodo, char info) {//Busqueda de un Nodo en el Arbol
		if (nodo == NULL) {
			return false;
		}
		//cout << endl << " " << nodo->dato;
		if (nodo->dato == info) {
			return true;
		}

		bool res1 = misterio2(nodo->izq, info);

		if (res1 == true) {
			return true;
		}

		bool res2 = misterio2(nodo->der, info);

		return res2;
	}

	int misterio3(Nodo* nodo) {//Nivel del Arbol, desde 0++
		int der = (nodo->der == NULL ? 0 : 1 + misterio3(nodo->der));
		int izq = (nodo->izq == NULL ? 0 : 1 + misterio3(nodo->izq));
		return (der > izq) ? der : izq;
	}

	int misterio4(Nodo* raiz) {//Nodos totales
		if (raiz != NULL) {
			return 1 + misterio4(raiz->izq) + misterio4(raiz->der);
		}
		else {
			return 0;
		}
	}

	void nodoInternos(Nodo* nodo) { //Nodos internos (Raiz y terminales no)
		queue<Nodo*> cola;
		cola.push(nodo);
		while (!cola.empty()) {
			Nodo* aux = cola.front();
			cola.pop();
			bool esInterno = 0;
			if (aux->izq) {
				esInterno = 1;
				cola.push(aux->izq);
			}
			if (aux->der) {
				esInterno = 1;
				cola.push(aux->der);
			}
			if (esInterno) {
				if (aux != raiz) {  //Para que la raiz no se imprima
					cout << " " << aux->dato << " ";
				}
			}
		}
	}
};

int main() {
	Arbol* a = new Arbol;
	Arbol::Nodo* raiz;
	raiz = a->getRaiz();
	a->cargaArbol(raiz);

	cout << endl << "\n\tARBOL: " << endl << endl;
	a->verArbol(raiz,0);

	cout << endl << "\n\tMisterio 1: ";
	cout << "Retorna el peso del Arbol";
	cout << endl << "\tPeso: " << a->misterio1(raiz);

	cout << endl << "\n\tMisterio 2: ";
	cout << "Busca un dato en el Arbol";
	cout << endl << "\tDato a buscar: "; char dat = 0;
	cin >> dat;
	if (a->misterio2(raiz,dat)) {
		cout << endl << "\tNodo encontrado";
	}
	else {
		cout << endl << "\tNodo NO encontrado";
	}

	cout << endl << "\n\tMisterio 3: ";
	cout << "Retorna el nivel del Arbol";
	cout << endl << "\tNivel: " << a->misterio3(raiz);

	cout << endl << "\n\tMisterio 4: ";
	cout << "Retorna el total de nodos existentes";
	cout << endl << "\tNum de Nodos: " << a->misterio4(raiz);

	cout << endl << "\n\tNodos internos: ";
	a->nodoInternos(raiz);

	cout << endl << endl;
	return 0;
}