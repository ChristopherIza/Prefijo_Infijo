/*UFA-ESPE
* Deber 2 Parcial 2
* Autores: Armas Daniel - Iza Christopher - Rea Denise - Rivadeneira Ricardo
* Fecha de creación 15/06/2022
* Fecha de modificación 17/06/2022
* Grupo 15 - 20
* github del grupo @dnrea@espe.edu.ec @cdiza5@espe.edu.ec daarmas10@espe.edu.ec rxrivadeneira1@espe.edu.ec
*/

//#include "ingresoDatos.h"
using namespace std;
#include <string>
#include "transformacion.h"


int main()
{
	
	int op = 0;
	ingresoDatos ing;
	string expresion,post,pref;
	pila pil;
	transformacion tran;

	do {
		do {
			system("cls");
			cout << "Escoja: ";
			cout << "\n 1) Posfijo " << endl;
			cout << "\n 2) Prefijo " << endl;
			cout << "\n 3) Evaluacion " << endl;
			cout << "\n 4) Finalizar programa " << endl;

			op = ing.ingresar_Datosenteros();
		} while (op < 1 || op >4);
		system("cls");
		if (op == 1) {
			system("cls");
			expresion =  ing.ingresoTransformacion() ;
			post = tran.postfijo(expresion);
			cout << "\n";
			cout << post << endl;
			cout << "\nPresione Enter para continuar...";
			getchar();
			getchar();
		}
		else if (op == 2) {
			system("cls");
			expresion = ing.ingresoTransformacion();
			post=tran.postfijo(expresion);
			pref = tran.reverso(tran.postfijo(tran.reverso(expresion)));
			cout << "\n";
			cout << pref << endl;
			cout << "\nPresione Enter para continuar...";
			getchar();
			getchar();
		}
		else if (op == 3) {
			system("cls");
			tran.calculo(post,expresion);
			
			cout << "Presione Enter para continuar...";
			getchar();
			getchar();
		}
		else if (op == 4) {
			system("cls");
			exit(1);
			cout << "Presione Enter para continuar...";
			getchar();
			getchar();
		}
	} while (op != 4);
}

