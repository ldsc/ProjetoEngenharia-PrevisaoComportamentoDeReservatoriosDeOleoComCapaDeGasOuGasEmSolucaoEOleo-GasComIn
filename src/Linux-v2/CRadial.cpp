/* Previsão do Compartamento de Reservatórios
   de Gás e de Óleo com Influxo de Água
   
   @Autores: Carlos André Martins de Assis e Gabriel Clemente Franklin
   @file CRadial.cpp
*/

#include "CRadial.h"
#include <iostream>
#include <fstream>

using namespace std;

void CRadial::Entrada(ostream & os ,istream & is)
{
        os<<"Entre com o Raio (m):";
        is>>r; is.get();
}

void CRadial::Saida(ostream & os)
{
        os<<"Raio (m): "<<r<<endl;
}

void CRadial::Entrada(ifstream & is)
{    is.ignore(100,':');
     is>>r;
}
