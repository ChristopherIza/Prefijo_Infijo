/*UFA-ESPE
* Deber 2 Parcial 2
* Autores: Armas Daniel - Iza Christopher - Rea Denise - Rivadeneira Ricardo
* Fecha de creación 15/06/2022
* Fecha de modificación 17/06/2022
* Grupo 15 - 20
* github del grupo @dnrea@espe.edu.ec @cdiza5@espe.edu.ec daarmas10@espe.edu.ec rxrivadeneira1@espe.edu.ec
*/
#include "nodo.h"


nodo::nodo(char val, nodo* Siguiente)
{
	this->siguiente = Siguiente;
	this->valor = val;
}
nodo::~nodo() {


}

nodo::nodo()
{
	valor = {};
	siguiente = nullptr;
}


char nodo::getValor()
{
	return this->valor;
}


nodo* nodo::getSiguiente()
{
	return siguiente;
}


void nodo::setValor(char val)
{
	this->valor = val;
}


void nodo::setSiguiente(nodo* Siguiente)
{
	this->siguiente = Siguiente;
}