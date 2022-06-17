/*UFA-ESPE
* Deber 2 Parcial 2
* Autores: Armas Daniel - Iza Christopher - Rea Denise - Rivadeneira Ricardo
* Fecha de creación 15/06/2022
* Fecha de modificación 17/06/2022
* Grupo 15 - 20
* github del grupo @dnrea@espe.edu.ec @cdiza5@espe.edu.ec daarmas10@espe.edu.ec rxrivadeneira1@espe.edu.ec
*/
#include "pila.h"

pila::pila() {
	ultimo = NULL;
}


void pila::push(char val)
{
	nodo* nuevo = new nodo();
	nuevo->setValor(val);
	if (ultimo == NULL) {
		nuevo->setSiguiente(NULL);
		ultimo = nuevo;
	}
	else {
		nuevo->setSiguiente(ultimo);
		ultimo = nuevo;
	}
}


void pila::ingresoEnteros()
{
	char c = {};

	while (c != 47) {
		int i = 0;
		char* dato = new char[10];
		printf("Ingrese un entero o '/' detener: ");
		while ((c = _getch()) != 13) {
			if (c >= '0' && c <= '9') {
				printf("%c", c);
				dato[i++] = c;
			}
			else if (c == 8 || c == 127) {
				printf("\b \b");
				dato[i--] = 0;
			}
			else if (c == 47) {
				printf("/");
				return;
			}
		}
		dato[i] = '\0';
		this->push(atoi(dato));
		cout << "\n";
	}
}

void pila::impresion()
{
	nodo* aux = new  nodo();
	aux = ultimo;
	while (aux != NULL) {
		cout << aux->getValor() << endl;
		aux = aux->getSiguiente();
	}
}

char pila::pop()
{
	int val = 0;
	nodo* aux = new nodo();

	if (ultimo == NULL) {
		val = 0;
	}
	else {
		aux = ultimo;
		ultimo = aux->getSiguiente();
		val = aux->getValor();
		delete aux;
	}
	return val;
}

char pila::peek() {
	return ultimo->getValor();
}