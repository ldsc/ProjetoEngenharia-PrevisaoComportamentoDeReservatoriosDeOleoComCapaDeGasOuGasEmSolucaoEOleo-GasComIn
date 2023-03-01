#ifndef CRK4_h
#define CRK4_h

#include<iostream>	
#include<cstdlib> 
#include<fstream>
#include<functional> 
#include<algorithm> 
#include<vector> 
#include<string> 
#include<iterator>
#include "CGnuplot.h" 
#include<locale.h>
#include<utility>
#include<cmath>
#include<iomanip>
#include "CMuskat.h"

class CRK4
{
      //yj+1=yj+(k1+2k2+2k3+k4)/6
      //k1=dxf(xj,yj)
      //k2=dxf(xj+k1/2, yj+dx/2)
      //k3=dxf(xj+k2/2,yj+h/2)
      //k4=dxf(xj+k3, yj+dx)
      public: 
                 std::vector<double> k1, k2, k3, k4, xj, yj;
                 double dx; 
                 CMuskat* cm;
                 int i;
                 double ite;
      public: 
      		CRK4(CMuskat& obj):i(0){
                 		 cm=&obj;
                         double aux; double aux2;
                         aux=obj.dprod->PI();
                         xj.push_back(aux); cm->GP0(aux);
                         std::cout << std::endl;
                         std::cout << "Entre com o passo (Se a pressão estiver caindo, entre o passo com sinal negativo): " << '\n';
                         std::cin>>dx;
                         std::cin.get();
                         std::cout <<"Até que pressão deseja prever?" << '\n';
                         std::cin>>aux2;
                         std::cin.get();
                         if(dx<0){ite=(aux-aux2)/(-dx);}
                         else{ite=(aux-aux2)/(dx);}
                         for (int p=0; p<ite; p++)
                         {   
                             double aux3= xj[p]+dx;
                             xj.push_back(aux3);
                         }
                         cm->Output_Psim(xj);
                         yj.resize(xj.size());
                         k1.resize(xj.size()); k2.resize(xj.size()); k3.resize(xj.size()); k4.resize(xj.size());
                         yj[0]=soleoinicial(obj.dprod->NPI(),obj.dprod->N(),obj.GetBo(aux),obj.dprod->BOI(),obj.dprod->SWI());
                         };
                CRK4(CRK4& obj): k1(obj.k1),k2(obj.k2),k3(obj.k3),k4(obj.k4), dx(obj.dx),xj(obj.xj),yj(obj.yj){};
                ~CRK4(){};
                 
                 void CalcK(); /// Calcula os coeficientes K
                 void YJ1(); /// Calcula vetor yj
                 void Grafico(); /// Grafica os resultados
                 void SetDx(double _dx){dx=_dx;}; /// Seta o dx
                 double GetDx(){return dx;}; ///Devolve o dx
                 void Solver(); ///Resolve a EDO
      			 double soleoinicial(double _np, double _n, double _bo, double _boi, double _swi){
      			 	double aux= ((1-(_np/_n))*(_bo/_boi)*(1-_swi)); cm->so.push_back(aux); return aux;
				   } /// Calcula Saturação Inicial - YJ[0]
                 void Saida(std::ostream& os, std::istream& cin); ///operador sobrecarregado de saída
                 void SaidaDisco(std::ofstream& fout); ///Salva em Disco
};
#endif
