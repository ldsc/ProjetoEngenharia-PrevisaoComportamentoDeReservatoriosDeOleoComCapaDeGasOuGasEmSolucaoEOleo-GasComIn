/* Previsão do Compartamento de Reservatórios
   de Gás e de Óleo com Influxo de Água
   
   @Autores: Carlos André Martins de Assis e Gabriel Clemente Franklin
   @file CLaplaceWd.cpp
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#include "specialfunctions.h" //funções de bessel-biblioteca da internet
#include "CLaplaceWd.h"

using namespace std;
using namespace alglib;



double CLaplaceWd::RadInf(double x) // Aquifero Radial Infinito
{
     
        double a=sqrt(x);
        double b=pow(a,3);
       
       return  besselk1(a)/(b*besselk0(a)); //besselk1 e besselk0 da biblioteca specialfunctions
      };
      
double CLaplaceWd::RadRea(double x,double re,double ro) //Aquifero Radial Realimentado
{
     
        
         double a=sqrt(x);
         double b=pow(a,3);
         double r=re/ro;
           
      return  ( besseli0(r*a)*besselk1(a)+besseli1(a)*besselk0(r*a) )/( b*( besselk0(a)*besseli0(r*a)-besseli0(a)*besselk0(r*a) ) );
};



double CLaplaceWd::RadSel(double x,double re,double ro) //aquifero Radial Selado
{ 
              
         double a=sqrt(x);
        double  b=pow(a,3);
        double r=re/ro;
                 
    return ( besseli1(r*a)*besselk1(a)-besseli1(a)*besselk1(r*a) )/( b*( besseli0(a)*besselk1(r*a)+besselk0(a)*besseli1(r*a) ) );
      };

double CLaplaceWd::LinInf(double x) //aquifero Linear Infinito
{
      return 2*sqrt(x/3.1416);
             };
double CLaplaceWd::LinRea(double x) //aquifero Linear Realimentado
{
    
         double a=sqrt(x);
         double b=pow(a,3);
           
       
        
    return  ( (1+exp(-2*a))/( b*( 1-exp(-2*a) ) ) );
      
      };
      
double CLaplaceWd::LinSel(double x) //Aquifero linear selado
{
         double a=sqrt(x);
        double  b=pow(a,3);
           
      
       
       
    
    return  ( (1-exp(-2*a) )/( b*( 1+exp(-2*a)) ) );
      };
