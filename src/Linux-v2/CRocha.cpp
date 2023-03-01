/* Previsão do Compartamento de Reservatórios
   de Gás e de Óleo com Influxo de Água
   
   @Autores: Carlos André Martins de Assis e Gabriel Clemente Franklin
   @file CRocha.cpp
*/

#include "CRocha.h"

using namespace std;

CRocha::CRocha(int geom)
{
     if(geom==eradial)
     {
              g=new CRadial;
     }
     if(geom==elinear)
     {
              g=new CLinear;
     }                         
}

void CRocha::Entrada(ostream & os ,istream & is)
{
        os<<"Entre com a Pressao Inicial(kgf/cm2):";
        is>>pi;
        os<<"Entre com o Porosidade (fracao):";
        is>>poro;
        os<<"Entre com o Espessura Media (m):";
        is>>h; is.get();
        g->Entrada(os,is);
}

void CRocha::Entrada(ifstream & is)
{    is.ignore(100,':');
     is>>pi;
     is.ignore(100,':');
     is>>poro;
     is.ignore(100,':');
     is>>h; 
     g->Entrada(is);
   
}

void CRocha::Saida(ostream & os)
{
        os<<"Pressao Inicial (kgf/cm2): "<<pi<<endl;
        os<<"Porosidade(fracao): "<<poro<<endl;
        os<<"Espessura Media (m): "<<h<<endl;   
        g->Saida(os);
}

