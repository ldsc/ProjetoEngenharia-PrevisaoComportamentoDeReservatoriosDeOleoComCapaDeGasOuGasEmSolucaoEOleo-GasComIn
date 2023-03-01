/* Previsão do Compartamento de Reservatórios
   de Gás e de Óleo com Influxo de Água
   
   @Autores: Carlos André Martins de Assis e Gabriel Clemente Franklin
   @file CSimulador.cpp
*/


#include "CSimulador.h"
#include "CGnuplot.h"
#include <iostream>
#include <fstream>


//Biblioteca do Qt esta aqui para usar o comando system no Qt
//#include <QtGui>

void CSimulador::Tempo()
{
   
         for (int i=1;i<=n;i++)
     {
       
         
         t[i]=i*dt; //O vetor t é o tempo em dias
     }
}




void CSimulador::Resultados(ostream &os)
{
     os<<"\t----------\n\tMetodo de "<<titulo<<"\n\t----------"<<endl;
    
     os<<"Pressao (kgf/cm2)"<<"\tInfluxo Acumulado (m3)"<<"\tTempo (dias)"<<endl;
     for (int i=0;i<=n;i++)
     {
     
     // os<<"p["<<i<<"]="<<P[i]<<";\t\tWen["<<i<<"]="
    //  <<"\t"<<Wen[i]<<";\tt["<<i<<"]="<<"\t"<<t[i]<<endl;
      
      os<<P[i]<<"\t\t\t"<<Wen[i]<<"\t\t\t"<<t[i]<<endl;
     }
 
 
 }


  void operator>>(ifstream & is,CSimulador &obj)
  {
      is>>obj.tipo;
      if(obj.tipo==egas)
        {
                   obj.fluido=new CGas;
        }
        if(obj.tipo==eoleo)
        {
                   obj.fluido=new COleo;
        }
        
       
      obj.rr.Entrada(is);
      
      obj.fluido->Entrada(is);
      
      obj.ra.Entrada(is);
     
     
  }



void operator<<(ofstream & os,CSimulador &obj)
 {
      obj.rr.Saida(os);
      obj.fluido->Saida(os);
      obj.ra.Saida(os);
 }                       

 void operator<<(ostream & os,CSimulador &obj)
 {
      obj.rr.Saida(os);
      obj.fluido->Saida(os);
      obj.ra.Saida(os);
 }    



 
  void CSimulador::Grafico(int op)
  {
    // Gnuplot :: set_GNUPlotPath ("C://gnuplot//binary");
    // Gnuplot :: Terminal ("win");
      CGnuplot obj("lines");
      obj.Grid();


      if (op == PxT)
      {

          obj.set_ylabel("Pressão no Contato (Kgf/cm²)");
          obj.set_xlabel("Tempo (Dias)");
          obj.PlotVector(t,P,titulo);


      }else if (op == WxT)
      {
          obj.set_ylabel("Influxo Acumulado (m³)");
          obj.set_xlabel("Tempo (Dias)");
          obj.PlotVector(t,Wen,titulo);




      }else if (op == WxP)
      {
          obj.set_xlabel("Influxo Acumulado (m³)");
          obj.set_ylabel("Pressão no Contato (Kgf/cm²)");
          obj.PlotVector(Wen,P,titulo);





      }
cout<<endl<<"Pressione enter para continuar..."<<endl<<endl; cin.get();
  }
