/*UFA-ESPE
* Deber 2 Parcial 2
* Autores: Armas Daniel - Iza Christopher - Rea Denise - Rivadeneira Ricardo
* Fecha de creaci�n 15/06/2022
* Fecha de modificaci�n 17/06/2022
* Grupo 15 - 20
* github del grupo @dnrea@espe.edu.ec @cdiza5@espe.edu.ec daarmas10@espe.edu.ec rxrivadeneira1@espe.edu.ec
*/
#pragma once
#include <iostream>

class nodo
{
private:
	char valor;
	nodo* siguiente;
	

public:
	nodo(char, nodo*);
	~nodo();
	nodo();
	char getValor();
	nodo* getSiguiente();
	void setValor(char);
	void setSiguiente(nodo*);


};

