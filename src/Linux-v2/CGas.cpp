/* Previsão do Compartamento de Reservatórios
   de Gás e de Óleo com Influxo de Água
   
   @Autores: Carlos André Martins de Assis e Gabriel Clemente Franklin
   @file CGas.cpp
*/
#include <cmath>
#include "CGas.h"

using namespace std;


double CGas::BrillZ(double p)
{
      double A=0.;
      double B=0.;
      double C=0.;
      double D=0.;
      double Ppr =0.,Tpr=0.;
      Ppr=p/Ppc;
      Tpr=t/Tpc;
      
      A=1.39*pow ((Tpr-0.92), 0.5 )-0.36*Tpr-0.101;
      B= (0.62-0.23*Tpr)*Ppr+( 0.066/(Tpr-0.86) -0.037 )*pow(Ppr,2)+ (0.32/(pow(10,9*(Tpr-1))))*pow(Ppr,6);
      C=0.132-0.32*log10(Tpr);
      D=pow(10,(0.3106-0.49*Tpr+0.1824*pow(Tpr,2)));
      
      z=A+((1-A)/exp(B))+C*pow(Ppr,D);
      return z;     
      }
      
double CGas::PolinomioZ(double a, double b, double c, double p)
{
      z=a*p*p+b*p+c;
      
      return z;
      
}


double CGas::B(double P)
{
    b = ((1.0335122*z*t)/(288.89*P));
    
    return b;
}
      
void CGas::Entrada(ostream & os ,istream & is)
{
     os<<"\t----------\n\tCGas\n\t----------"<<endl;
     CFluido::Entrada(os,is);
     os<<"Entre com a Temperatura Pseudo-Critica Tpc (K):";
     is>>Tpc;
     os<<"Entre com a Pressao  Pseudo-Critica Ppc (kgf/cm2):";
     is>>Ppc;
     os<<"Entre com o fator de compressibilidade z:";
     is>>z; 
     os<<"Entre com a Temperatura (K):";
     is>>t; is.get();
}

void CGas::Entrada(ifstream & is)
{
    
     CFluido::Entrada(is);
     is.ignore(100,':');
     is>>Tpc;
     is.ignore(100,':');
     is>>Ppc; 
     is.ignore(100,':');
     is>>z;
     is.ignore(100,':');
     is>>t;
}

void CGas::Saida(ostream & os)
{
        os<<"\t----------\nPropriedades do Gas\n\t----------"<<endl;
        CFluido::Saida(os);
        os<<"Temperatura Pseudo-Critica Tpc (K):"<<Tpc<<endl;
        os<<"Pressao  Pseudo-Critica Ppc (kgf/cm2):"<<Ppc<<endl;
        os<<"Fator de Compressibilidade z:"<<z<<endl;
        os<<"Temperatura (K): "<<t<<endl;
}
