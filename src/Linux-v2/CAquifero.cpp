/* Previsão do Compartamento de Reservatórios
   de Gás e de Óleo com Influxo de Água
   
   @Autores: Carlos André Martins de Assis e Gabriel Clemente Franklin
   @file CAquifero.cpp
*/



#include "CAquifero.h"

using namespace std;

void CAquifero::Entrada(ostream & os ,istream & is)
{
     os<<"\t----------\n\tCAquifero\n\t----------"<<endl;
        CRocha::Entrada(os,is);
        os<<"Entre com a Permeabilidade (md):";
        is>>k;
        os<<"Entre com o Compressibilidade Total (cm2/kgf):";
        is>>ct;
        os<<"Entre com o Viscosidade da Agua (cp):";
        is>>u; 
}

void CAquifero::Entrada(ifstream & is)
{
     
     CRocha::Entrada(is);
     is.ignore(100,':');
     is>>k;
     is.ignore(100,':');
     is>>ct;
     is.ignore(100,':');
     is>>u;
}


void CAquifero::Saida(ostream & os)
{
        os<<"\t----------\n\tPropriedades do Aquifero\n\t----------"<<endl;
        CRocha::Saida(os);
        os<<"Permeabilidade (md): "<<k<<endl;
        os<<"Compressibilidade Total (cm2/kgf): "<<ct<<endl;
        os<<"Viscosidade da Agua (cp): "<<u<<endl;
}
