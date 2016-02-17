#include "Data.h"
#include <iostream>

using namespace std;

Data::Data(int day, int month, int year)
{
    dia = day;
    mes = month;
    ano = year;
}

Data::~Data()
{
}

void Data::print() const
{
    cout << "\n>> DATE OF CREATION = " << dia << "//" << mes << "//" << ano;
}

void Data::setDate(int day, int month, int year)
{
    ano = year;
    mes = month;
    dia = checarDia(day);
}

int Data::checarDia(int dia) const
{
    static const int diasPorMes[13] = {0, 31, 28, 31, 30, 30, 31, 31, 30, 31, 30, 31};
    
    if (dia > 0 && dia <= diasPorMes[mes])
    {
        return dia;
    }
    
    if (mes == 2 && dia == 29 && (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0)))
    {
        return dia;
    }
    
    cout << "\n Dia inválido";
    
    return 1;
}

