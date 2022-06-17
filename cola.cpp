/*UFA-ESPE
* Deber 1 Parcial 2
* Autores: Iza Christopher- Rea Denise
* Fecha de creación 13/05/2022
* Fecha de modificación 15/05/2022
* Grupo 20
* github del grupo @dnrea@espe.edu.ec @cdiza5@espe.edu.ec
*/

#include "cola.h"

cola::cola()
{
	primero = NULL;
	ultimo = NULL;
}

cola::~cola()
{
	while (primero) {
		leer();
	}
}

void cola::agregar(int val)
{
	nodo* nuevo = new nodo();
	nuevo->setValor(val);
	nuevo->setSiguiente(NULL);
	if(!primero)
	{
		primero = nuevo;
		ultimo = primero;
	}
	else  {
		ultimo->setSiguiente(nuevo);
		ultimo = nuevo;
	}
}

void cola::ingresoEnteros()
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
				break;
			}
		}
		dato[i] = '\0';
		this->agregar(atoi(dato));
		cout << "\n";
	}
}

void cola::impresion()
{
	nodo* aux = new nodo();
	aux = primero;
	if (primero->getValor() == NULL) {
		cout << "La cola esta vacia" << endl;
	}
	else {
		do {
		
			cout << aux->getValor() << endl;
			aux = aux->getSiguiente();
		} while (aux->getSiguiente() != NULL);
	}
}

int cola::leer()
{
	int val = 0;
	nodo*  aux = new nodo();
	aux = primero;
	if (primero->getValor() == NULL ){
		val =  0;
	}
	else {
		primero = aux->getSiguiente();
		val = aux->getValor();
		//delete aux;
	}
	return val;
}

