/* Previsão do Compartamento de Reservatórios
   de Gás e de Óleo com Influxo de Água
   
   @Autores: Carlos André Martins de Assis e Gabriel Clemente Franklin
   @file CFluido.cpp
*/

#include "CFluido.h"
#include <iostream>
#include <fstream>

using namespace std;

void CFluido::Entrada(ostream & os ,istream & is)
{
        os<<"Entre com a densidade:";
        is>>d;
        os<<"Entre com o volume inicial (m3 std):";
        is>>v;
        os<<"Entre com o fator Volume-Formacao (m3/m3 std):";
        is>>b; is.get();
}

void CFluido::Entrada(ifstream & is)
{    
     is.ignore(100,':');
     is>>d;
     is.ignore(100,':');
     is>>v;
     is.ignore(100,':');
     is>>b;
}

void CFluido::Saida(ostream & os)
{
        os<<"Densidade: "<<d<<endl;
        os<<"Volume inicial (m3 std): "<<v<<endl;
        os<<"Fator Volume-Formacao (m3/m3 std): "<<b<<endl;   
}
