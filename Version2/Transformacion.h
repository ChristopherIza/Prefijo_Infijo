#pragma once
#include "Pila.h"
#include "ingresoDatos.cpp"
class Transformacion
{	
public:
	Transformacion();
	string postFix(string);
	int esOperador(char);
	int prioridades(char);
	string reverso(string);
	string preFix(string);
	float calcular(string, string);
	bool detectarOperadores(char);
	string postFix1(string);
	bool validarString(string);
};

