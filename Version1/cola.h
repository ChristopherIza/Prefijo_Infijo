#pragma once
#include "nodo.h"
using namespace std;
#include <conio.h>
class cola
{
public:
	cola();
	~cola();
	void agregar(int);
	void  ingresoEnteros();
	void impresion();
	int leer();
private:
	nodo* primero;
	nodo* ultimo;
};

