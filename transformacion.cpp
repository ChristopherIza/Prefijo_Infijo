/*UFA-ESPE
* Deber 2 Parcial 2
* Autores: Armas Daniel - Iza Christopher - Rea Denise - Rivadeneira Ricardo
* Fecha de creación 15/06/2022
* Fecha de modificación 17/06/2022
* Grupo 15 - 20
* github del grupo @dnrea@espe.edu.ec @cdiza5@espe.edu.ec daarmas10@espe.edu.ec rxrivadeneira1@espe.edu.ec
*/
#include "transformacion.h"
#include "Validacion.h"
#include <math.h>
# define MY_PI 3.14159265358979323846
template<class TIPO> class pilai;

template<class TIPO>
class nodot {
public:
	nodot(TIPO v, nodot<TIPO>* sig = NULL) {
		valor = v;
		siguiente = sig;
	}

private:
	TIPO valor;
	nodot<TIPO>* siguiente;

	friend class pilai<TIPO>;
};

template<class TIPO>
class pilai {
public:
	pilai() : ultimo(NULL) {}
	~pilai();

	void Push(TIPO v);
	TIPO Pop();

private:
	nodot<TIPO>* ultimo;
};

template<class TIPO>
pilai<TIPO>::~pilai() {
	while (ultimo) Pop();
}

template<class TIPO>
void pilai<TIPO>::Push(TIPO v) {
	nodot<TIPO>* nuevo;

	nuevo = new nodot<TIPO>(v, ultimo);
	ultimo = nuevo;
}

template<class TIPO>
TIPO pilai<TIPO>::Pop() {
	nodot<TIPO>* Nodo; 
	TIPO v;     
	if (!ultimo) return 0; 
	Nodo = ultimo;
	ultimo = Nodo->siguiente;
	v = Nodo->valor;
	delete Nodo;
	return v;
}

string transformacion::postfijo(string expresion)
{
	pila pila;
	pila.push('#');
	int i, j;
	char actual={};
	//string aux;
	//aux = "";
	//char aux[100]{};
	Validacion v;
	//if (v.vaidar_Escritura(expresion)) {
		char aux[100]{};
		for (i = 0, j = 0; i < expresion.size(); i++)
		{
			actual = expresion.at(i);
			if (esOperador(actual) == 0) {
				aux[j] = actual;
				j++;
			}
			else {
				if (actual == '(') {
					pila.push(actual);
				}
				else if (actual == ')') {
					while (pila.peek() != '(') {
						aux[j] = pila.pop();
						j++;
					}
					pila.pop();
				}
				else {
					if (prcd(pila.peek()) < prcd(actual)) {
						pila.push(actual);
					}
					else {
						while (prcd(pila.peek()) >= prcd(actual)) {
							aux[j] = pila.pop();
							//aux.at(j) = pila.pop();
							j++;
						}
						pila.push(actual);
					}
				}
			}

		}
		while (pila.peek() != '#') {
			aux[j] = pila.pop();
			j++;
		}
	//}
	//else {
	//	cout << "\n Ingrese correctamente su expresion por favor" << endl;
	//}

	return  aux;
}



int transformacion::esEntero(char ch)
{
	return (ch >= '0' && ch <= '9') ;
}
int transformacion::esOperador(char ch) {
	switch (ch) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	case '%':
	case '(':
	case ')':
		return 1;
		break;
	default:
		return 0;
	}
}
int transformacion:: prcd(char ch){ 
	int n = 0;
	switch (ch) {
		
		case '-':
			//n = 2;
			//break;
		case '+':
			n= 3;
			break;
		case '*':
		case '/':
		case '%':
			n= 4;
			break;
		case '^':
		case 's':
			n= 6;
			break;
		case '(':
		case ')':
		case '#':
			n=1;
			break;
}
	return n;
}

string transformacion::reverso(string expresion1)
{
	
		int i = 0;
		string expresionInvertida;
		for (i = expresion1.length() - 1; i >= 0; i--) {
			if (expresion1.at(i) == '(') {
				expresionInvertida.append(")");
			}
			else if (expresion1.at(i) == ')' ){
				expresionInvertida.append("(");
			}
			else {
				expresionInvertida.append(expresion1.substr(i, 1));
			}
		}
		
		return expresionInvertida;
	
}
bool transformacion::oper(char ch) {

		if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^' || ch == 's' || ch == 't' || ch == 'c' || ch == 'p') {
			return true;
		}
		return false;
	}

// post: 867*35/+cos50-
// infi: 86*7+3/5-cos(50)sqrt(4)
void transformacion::calculo(string post,string infi)
{
	pila pila;
	pilai<float> pilat;
	char aux1[10]{}, aux2[10]{};
	char actual ={};
	int cal[10]{};
	int	k = 0, l=0, m=0 ;
	float val1, val2;
	for (int i = 0; i < post.size(); i++) {
		aux1[0] = post.at(i);
		if (!oper(aux1[0])) {
			pilat.Push(atof(aux1));
			aux1[0] = {};
		}
	
		else{		
			switch (aux1[0])
			{
			case '+':
				val1 = pilat.Pop();
				val2 = pilat.Pop();
				pilat.Push(val1 + val2);
				break;
			case '-':
				val1 = pilat.Pop();
				val2 = pilat.Pop();
				pilat.Push(val2 - val1);
				break;
			case '*':
				val1 = pilat.Pop();
				val2 = pilat.Pop();
				pilat.Push(val1 * val2);
				break;
			case '/':
				val1 = pilat.Pop();
				val2 = pilat.Pop();
				pilat.Push(val2 / val1);
				break;
			case '^':
				val1 = pilat.Pop();
				val2 = pilat.Pop();
				pilat.Push(pow(val2,val1));
				break;
			case '%':
				val1 = pilat.Pop();
				val2 = pilat.Pop();
				pilat.Push((int)(val1)%(int)val2);
				break;
			case 'c':
				
				aux1[0] = post.at(i + 3);
				pilat.Push(cos(atof(aux1)));
				i = i + 4;
				break;
			case 's':
				if (post.at(i + 1) == 'i') {
					aux1[0] = post.at(i + 3);
					pilat.Push(sin(atof(aux1)));
					i = i + 4;
					break;
				}
				else {
					aux1[0] = post.at(i + 4);
					pilat.Push(sqrt(atof(aux1)));
					i = i + 5;
					break;
				}
			case 't':
				aux1[0] = post.at(i + 3);
				pilat.Push(tan(atof(aux1)));
				i = i + 4;
				break;
			case 'p':
				pilat.Push(MY_PI);
				i = i + 1;
				break;

			}
		}
		
	}
	cout << pilat.Pop()<<endl;
}
