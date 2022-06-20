#include <iostream>
#include "Transformacion.cpp"

int main()
{
	Transformacion* tran = new Transformacion();
	string expresion, post, pref;
	ingresoDatos ing;
	float resultado = 0.0;
	int op = 0;
	do
	{
		do {
			system("cls");
			cout << "Escoja: ";
			cout << "\n 1) Convertir infijo a posfijo " << endl;
			cout << "\n 2) Convertir infijo a prefijo " << endl;
			cout << "\n 3) Realizar el calculo " << endl;
			cout << "\n 4) Finalizar programa " << endl;
			op = ing.ingresar_Datosenteros();
		} while (op < 1 || op >4);
		system("cls");
		if (op == 1) {
			system("cls");
			expresion = ing.ingresoTransformacion();
			post = tran->postFix(expresion);
			cout << "\n";
			cout << "\n Expresion postfija: " << post << endl;
			cout << "\nPresione Enter para continuar...";
			getchar();
			getchar();
		}
		else if (op == 2) {
			system("cls");
			expresion = ing.ingresoTransformacion();
			if(tran->validarString(expresion)){
			pref = tran->preFix(expresion);
			}
			cout << "\n";
			cout << "\n Expresion prefija:" <<pref << endl;
			pref ="";
			cout << "\nPresione Enter para continuar...";
			getchar();
			getchar();
		}
		else if (op == 3) {
			system("cls");
			resultado = tran->calcular(expresion, post);
			cout << "El resultado es el siguiente:"<<resultado<<endl;
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
	return 0;
}

