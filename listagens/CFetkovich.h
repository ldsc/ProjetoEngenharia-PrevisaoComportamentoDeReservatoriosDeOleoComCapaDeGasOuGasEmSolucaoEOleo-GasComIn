/** Previsao do Compartamento de Reservatorios
   de Gas e de Oleo com Influxo de Agua
    @author Carlos Andre Martins de Assis e Gabriel Clemente Franklin
   @file CFetkovich.h
*/

/** @brief Classe que implementa o metdo de Fetkovich
    @class CFetkovich
*/
#ifndef CFetkovich_h
#define CFetkovich_h

#include "CSimulador.h"



using namespace std;

class CFetkovich: public CSimulador

{
      protected:
                double J; ///< Indice de produtividade do Aquifero
                double Wei;  ///< Influxo Maximo
               
       public:


             ///@brief Construtor para o caso gas
             CFetkovich(int _n,int _op,double _dt,double _pi,double _poro,
                    double _h,double _sw,double _Q,double _T,double _ro,double _d,
                    double _v,double _B,double _Tpc, double _Ppc,double _z,double a_pi,
                    double a_poro, double a_h,double _k,double _ct,double _u,double _re)
               :CSimulador (_n,_op,_dt,_pi,_poro,_h,_sw,_Q,_T,_ro,_d,_v,
                            _B,_Tpc,_Ppc,_z,a_pi,a_poro,a_h,_k,_ct,_u,_re)
             {SolverGas(); titulo = "Fetkovich";}

             ///@brief construtor para o caso oleo
             CFetkovich(int _n,int _op,double _dt,double _pi,double _poro,
                    double _h,double _sw,double _Q,double _ro,double _d,
                    double _v,double _B,double _ceo, double _co,double a_pi,double a_poro,
                    double a_h,double _k,double _ct,double _u,double _re)
                  :CSimulador (_n,_op,_dt,_pi,_poro,_h,_sw,_Q,_ro,_d,_v,
                            _B,_ceo,_co,a_pi,a_poro,a_h,_k,_ct,_u,_re)
             {SolverOleo(); titulo = "Fetkovich";}
             ///@brief construtor para os vetores
            CFetkovich(int size): CSimulador(size)
             { titulo = "Fetkovich";}
            
            ///@brief construtor sobrecarregado
            ///Usado na classe CInterface para a versao do programa modo texto.
            CFetkovich(int _n,int _op,double _dt,int _geom):CSimulador(_n,_op,_dt,_geom)
              {titulo = "Fetkovich";}

         ///@briefresolve uma equacao do segundo grau 
            double EqSeg (double,double,double);
         ///@briefInicializa as constantes para caso Radial ou Linear
         virtual void Constantes();
         
         ///@brief Resolve o problema para o caso do gas
         virtual void SolverGas();
         ///@brief Resolve o problema para o caso do oleo
         virtual void SolverOleo();
         ///@brief Destrutor
         virtual   ~CFetkovich(){}
      };

#endif
