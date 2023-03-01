/* Previsão do Compartamento de Reservatórios
   de Gás e de Óleo com Influxo de Água
   
   @Autores: Carlos André Martins de Assis e Gabriel Clemente Franklin
   @file CStehfest.cpp
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "specialfunctions.h"
#include "CStehfest.h"

using namespace std;
using namespace alglib;


double CStehfest::Fatorial(int N)
{
     double x = 1; 
        if (N > 1) 
        { 
            for (int i = 2; i <= N; i++) 
                x = i * x; 
        } 
        return x; 
     
 }
 
void CStehfest::SetV() //indices começam em zero
{
     
        int N2 = n/ 2; 
        int NV = 2 * N2; 
        int sign = 1; 
        if ((N2 % 2) != 0) 
            sign = -1; 
        for (int i = 0; i < n; i++) 
        { 
            int kmin = (i + 2) / 2; 
            int kmax = i + 1; 
            if (kmax > N2) 
                kmax = N2; 
            v[i] = 0; 
            sign = -sign; 
            for (int k = kmin; k <= kmax; k++) 
            {   double y=k;
                v[i] = v[i] + (pow(y, N2) / Fatorial(k)) * (Fatorial(2 * k) 
                     / Fatorial(2 * k - i - 1)) / Fatorial(N2 - k) 
                     / Fatorial(k - 1) / Fatorial(i + 1 - k); 
            } 
            v[i] = sign * v[i];
        } 
 }


double CStehfest::Inversao(double (*f)(double),double x)

{   
      
      double u=0.;
      double l=0.;
      double soma=0.;
      u=log(2)/x;
      l=1.;
      
      for (int i=0;i<n;i++)
      {
          soma+=v[i]*f(u*l);
          l++;
      } 
      
      return u*soma;
      }
double CStehfest::Inversao(double (*f)(double,double,double),double re,double ro,double x)

{   
      
      double u=0.;
      double l=0.;
      double soma=0.;
      u=log(2)/x;
      l=1.;
      
      for (int i=0;i<n;i++)
      {
          soma+=v[i]*f(u*l,re,ro);
          l++;
      } 
      
      return u*soma;
      }
