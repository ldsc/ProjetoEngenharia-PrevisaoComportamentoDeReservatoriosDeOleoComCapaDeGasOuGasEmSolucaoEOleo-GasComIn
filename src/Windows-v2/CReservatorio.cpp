/* Previsão do Compartamento de Reservatórios
   de Gás e de Óleo com Influxo de Água
   
   @Autores: Carlos André Martins de Assis e Gabriel Clemente Franklin
   @file CReservatorio.cpp
*/

#include "CReservatorio.h"

using namespace std;

void CReservatorio::Entrada(ostream & os ,istream & is)
{
     os<<"\t----------\n\tCReservatorio\n\t----------"<<endl;
        CRocha::Entrada(os,is);
        os<<"Entre com a Saturacao da Agua (fracao):";
        is>>sw;
        os<<"Entre com o Vazao (m3 std/d):";
        is>>q;
}

void CReservatorio::Entrada(ifstream & is)
{   
     CRocha::Entrada(is);
     is.ignore(100,':');
     is>>sw;
     is.ignore(100,':');
     is>>q; 
}

void CReservatorio::Saida(ostream & os)
{
        os<<"\t----------\n\tPropriedades do Reservatorio\n\t----------"<<endl;
        CRocha::Saida(os);
        os<<"Saturacao da Agua (fracao): "<<sw<<endl;
        os<<"Vazao (m3 std/d): "<<q<<endl;
}
