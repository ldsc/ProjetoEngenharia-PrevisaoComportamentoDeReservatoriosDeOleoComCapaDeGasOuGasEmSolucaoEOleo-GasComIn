/** Previsao do Compartamento de Reservatorios
   de Gas e de Oleo com Influxo de Agua
    @author Carlos Andre Martins de Assis e Gabriel Clemente Franklin
   @file CSimulador.h
*/

/** @brief Classe Mae para os metodos de Hurst e Fetkovich.
    @class CSimulador
    */

#ifndef CSimulador_h
#define CSimulador_h

#include "CAquifero.h"
#include "CReservatorio.h"
#include "CGas.h"
#include "COleo.h"
#include "CLaplaceWd.h"
#include "CStehfest.h"
#include <cmath>
#include <vector>
#include <string>
#include <typeinfo>




//class MainWindow;


using namespace std;

///@enum enumeração para geracao de graficos
  enum {PxT = 0, WxT = 1, WxP = 2};
  

class CSimulador

{
   // friend class MainWindow; //DEIXAR APENAS O MÉTODO QUE USAR OS VETORES COMO FRIEND!!!!
      
      protected:



               int n; ///< numero de anos a serem simulados
               int op; ///< tipo de influxo: infinito(1), realimentado(2), selado(3)
               double dt; ///< Passo em dias do vetor td (default é 365 dias)
               int tipo; ///< Tipo de fluido: Gas(1), Oleo(2)
               int geom; ///< Geometria das rochas: Radial(1), Linear(2)

               CReservatorio rr; ///< rocha reservatorio
               CAquifero ra; ///< rocha aquifero
               CFluido *fluido; ///< fluido na rocha reservatorio
              
               vector<double>P; ///< ventor de pressões no contato aquifero/reservatório
               vector<double>Wen; ///< vetor de influxo acumulado
               vector<double>t; ///< Tempo
          
               
               string titulo; ///< titulo recebe hurst ou fetkovich, inicia como padrao
       public:
            
            ///@brief Construtor Gas uso na Interface grafica
         
             CSimulador(int _n,int _op,double _dt,double _pi,double _poro, double _h,double _sw,double _Q,
               double _T,double _ro,double _d,double _v,double _B,double _Tpc, double _Ppc,double _z,
               double a_pi,double a_poro, double a_h,double _k,double _ct,double _u,double _re)
               :n(_n),op(_op),dt(_dt),t(_n+1,0.0),P(n+1),Wen(n+1)
               ,rr(_pi,_poro,_h,_sw,_Q,_ro),ra(a_pi,a_poro,a_h,_k,_ct,_u,_re)
             {fluido=new CGas(_d,_v,_B,_Tpc,_Ppc,_z,_T); titulo = "Padrao";   }
            
            
            ///@brief Construtor oleo uso na interface grafica
             CSimulador(int _n,int _op,double _dt,double _pi,double _poro, double _h,double _sw,double _Q, ///@brief Aqui nao usa mais T
                   double _ro,double _d,double _v,double _B,double _ceo, double _co,
                   double a_pi,double a_poro, double a_h,double _k,double _ct,double _u,double _re)
                   :n(_n),op(_op),dt(_dt),t(_n+1,0.0),P(n+1),Wen(n+1)
                   ,rr(_pi,_poro,_h,_sw,_Q,_ro),
                   ra(a_pi,a_poro,a_h,_k,_ct,_u,_re)
                   {fluido=new COleo(_d,_v, _B,_ceo,_co); titulo = "Padrao"; }
                                      
            ///@brief uso com Interface grafica
            CSimulador(int size):P(size),Wen(size),t(size),rr(0.0,0.0,0.0,0.0,0.0,0.0),
             ra(0.0,0.0,0.0,0.0,0.0,0.0,0.0)
             { titulo = "Padrao";}

              ///@brief uso com arquivo do prompt
             CSimulador(int _n,int _op,double _dt,int _geom):n(_n),op(_op),dt(_dt),t(_n+1,0.0),Wen(_n+1),
                            P(_n+1),rr(_geom),ra(_geom),geom(_geom)
                            {titulo = "Padrao";}
            ///@brief calcula os vetores de tempo
            virtual void Tempo();
            ///@brief Retorna o tipo de fluido
            double Tipo(){return tipo;};
            ///Metodos das classes herdeiras
            virtual void SolverGas()=0;
            virtual  void SolverOleo()=0;
            virtual void Constantes()=0;
            ///@brief Gera os graficos a partir das opcoes disponiveis
             void Grafico(int op);
           
             ///@brief Sobrecarda para receber os dados (arquivo)
             friend void operator>>(ifstream & is,CSimulador &obj); 
            ///@brief Sobrecarga para enviar os dados  (arquivo)
             friend void operator<<(ofstream & os,CSimulador &obj); 
            ///@brief Sobrecarga para enviar os dados  (tela)
            friend void operator<<(ostream & os,CSimulador &obj); 
            ///@brief Seta o  valor de op
            void SetInfluxo(int _op){ op = _op;}
            ///@brief Mostra os resultados
            void Resultados(ostream & os); 
             
            ///@brief Destrutor
             ~CSimulador(){delete fluido;}
     
      };

#endif
