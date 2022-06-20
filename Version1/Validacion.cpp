/*UFA-ESPE
* Deber 2 Parcial 2
* Autores: Armas Daniel - Iza Christopher - Rea Denise - Rivadeneira Ricardo
* Fecha de creación 15/06/2022
* Fecha de modificación 17/06/2022
* Grupo 15 - 20
* github del grupo @dnrea@espe.edu.ec @cdiza5@espe.edu.ec daarmas10@espe.edu.ec rxrivadeneira1@espe.edu.ec
*/
#include "Validacion.h"
#include <iostream>
#include <conio.h>
string Validacion::texto(string cadena, int i)
{
    string t = "";
    t = cadena[i];
    t += cadena[i + 1];
    t += cadena[i + 2];
    t += cadena[i + 3];
    return t;
}

string Validacion::textoCos(string cadena, int i)
{
    string t = "";
    t = cadena[i - 2];
    t += cadena[i - 1];
    t += cadena[i];
    return t;
}

bool Validacion::validar_Sen(string cadena)
{
    string sin = "sin(";
    string cos = "";
    string sqr = "sqrt(";
    string cadenita = "";
    bool val = true;
    bool sqt = true;
    bool cc = false;
    for (int i = 0; i < cadena.size(); i++)
    {
        if (cadena[i] == 115)
        {
            cadenita = this->texto(cadena, i);
            if (cadena[i + 1] == 105) {
                if (sin == cadenita) {
                    val = true;
                }
                else
                {
                    val = false;
                }
            }

            else if (cadena[i + 1] == 113) {
                cadenita += cadena[i + 4];
                if (sqr == cadenita) {
                    sqt = true;
                }
                else
                {
                    sqt = false;
                }
            }

            else
            {
                cos = this->textoCos(cadena, i);
                if (cos == "cos")
                {
                    val = true;
                }
                else
                {
                    val = false;
                }
            }

        }
    }
    if (val && sqt)
    {
        cc = true;
    }
    else
    {
        cc = false;
    }
    return cc;
}

bool Validacion::validar_Cos(string cadena)
{
    string cos = "cos(";
    string cadenita = "";
    int count = 0;
    bool val = true;
    for (int i = 0; i < cadena.size(); i++)
    {
        if (cadena[i] == 99)
        {
            count++;
            cadenita = this->texto(cadena, i);
            if (cos == cadenita) {
                val = true;
            }
            else
            {
                val = false;
            }
        }
        else if (count == 0)
        {
            val = false;
        }
    }
    return val;
}

bool Validacion::validar_Tan(string cadena)
{
    string tan = "tan(";
    string cadenita = "";
    bool val = true;
    for (int i = 0; i < cadena.size(); i++)
    {
        if (cadena[i] == 116 && cadena[i + 1] == 97)
        {
            cadenita = this->texto(cadena, i);
            if (tan == cadenita) {
                val = true;
            }
            else
            {
                val = false;
            }
        }
    }
    return val;
}


bool Validacion::vaidar_Escritura(string cadena)
{
    bool valid = false;
    bool seno = this->validar_Sen(cadena);
    bool coseno = this->validar_Cos(cadena);
    if (this->validar_Cos(cadena) && this->validar_Sen(cadena) && this->validar_Tan(cadena) && this->validar_Pi(cadena))
    {
        valid = true;
    }
    return valid;
}

bool Validacion::validar_Pi(string cadena)
{
    string pi = "pi";
    string cadenita = "";
    bool val = true;
    for (int i = 0; i < cadena.size(); i++)
    {
        if (cadena[i] == 112)
        {
            cadenita = cadena[i];
            cadenita += cadena[i + 1];
            if (pi == cadenita) {
                val = true;
            }
            else
            {
                val = false;
            }
        }
    }
    return val;
}