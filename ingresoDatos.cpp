/*UFA-ESPE
* Deber 2 Parcial 2
* Autores: Armas Daniel - Iza Christopher - Rea Denise - Rivadeneira Ricardo
* Fecha de creación 15/06/2022
* Fecha de modificación 17/06/2022
* Grupo 15 - 20
* github del grupo @dnrea@espe.edu.ec @cdiza5@espe.edu.ec daarmas10@espe.edu.ec rxrivadeneira1@espe.edu.ec
*/
#include "ingresoDatos.h"
//#include <conio.h>
using namespace std;


int  ingresoDatos::ingresar_Datosenteros()
{
    	char *dato=new char[10],c;
	int i=0;
	printf("Seleccione una opcion: ");
	while((c=_getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
				}
		else if(c==8||c==127){
			printf("\b \b");
			dato[i--]=0;
		}
	}
	dato[i]='\0';
	return atoi(dato);
}

string ingresoDatos::ingresoTransformacion()
{
	char c;
	string expresion = "";
	cout << "----------------------------------------------" << endl;
	cout << "seno -> sin()		coseno-> cos()" << endl;
	cout << "tangente-> tan()	raiz cuadrada-> sqrt()" << endl;
	cout << "pi -> pi" << endl;
	cout << "-----------------------------------------------" << endl;
	printf("Ingrese la expresion:  ");
	
	while ((c = _getch()) != 13) {
		if ((c >= 40 && c <= 57)||c==97||c==99|| (c >= 110 && c <= 116) ||c ==105|| c==94|| c==37) {
			printf("%c", c);
			expresion.push_back(c);
		}
		else if (c == 8 || c == 127) {
			printf("\b \b");
			expresion.pop_back();
		}
	}
		
	return expresion;
	
}
