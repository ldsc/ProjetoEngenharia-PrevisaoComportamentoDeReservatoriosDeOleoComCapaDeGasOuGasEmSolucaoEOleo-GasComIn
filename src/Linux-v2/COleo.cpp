/* Previsão do Compartamento de Reservatórios
   de Gás e de Óleo com Influxo de Água
   
   @Autores: Carlos André Martins de Assis e Gabriel Clemente Franklin
   @file COleo.cpp
*/

#include "COleo.h"
#include <iostream>

using namespace std;

double COleo::Ceo(double sw,double cw,double cf)
{
       //Calcula ceo a partir da Saturacao de Agua(sw), Comp. da formacao(cf) e Comp. da Agua(cw)
       ceo=co+(cw*sw+cf)/(1-sw);
       return ceo;
}

void COleo::Entrada(ostream & os ,istream & is)
{
     os<<"\t----------\n\tCOleo\n\t----------"<<endl;
     CFluido::Entrada(os,is);
     os<<"Entre com a Compressibilidade do Oleo (cm2/kgf):";
     is>>co; is.get();
     os<<"Entre com a Compressibilidade Efetiva do Oleo (cm2/kgf):";
     is>>ceo; is.get();
}

void COleo::Entrada(ifstream & is)
{   
     CFluido::Entrada(is);
     
     is.ignore(100,':');
     is>>co;
     is.ignore(100,':');
     is>>ceo; 
}

void COleo::Saida(ostream & os)
{
        os<<"\t----------\n\tPropriedades do Oleo\n\t----------"<<endl;
        CFluido::Saida(os);
        os<<"Compressibilidade do Oleo (cm2/kgf):"<<co<<endl;
        os<<"Compressibilidade Efetiva do Oleo (cm2/kgf):"<<ceo<<endl;
}
