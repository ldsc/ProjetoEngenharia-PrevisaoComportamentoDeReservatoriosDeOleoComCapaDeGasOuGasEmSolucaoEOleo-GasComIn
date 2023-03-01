/* Previs�o do Compartamento de Reservat�rios
   de G�s e de �leo com Influxo de �gua
   
   @Autores: Carlos Andr� Martins de Assis e Gabriel Clemente Franklin
   @file CLinear.cpp
*/

#include "CLinear.h"
#include <iostream>
#include <fstream>

using namespace std;

void CLinear::Entrada(ostream & os ,istream & is)
{
        os<<"Entre com a Largura (m):";
        is>>w;
        os<<"Entre com o Comprimento (m):";
        is>>l; is.get();

}

void CLinear::Saida(ostream & os)
{
        os<<"Largura (m): "<<w<<endl;
        os<<"Comprimento (m): "<<l<<endl;

}

void CLinear::Entrada(ifstream & is)
{
     is.ignore(100,':');
     is>>w;
     is.ignore(100,':');
     is>>l;
}
