/** Previsao do Compartamento de Reservatorios
   de Gas e de Oleo com Influxo de Agua
    @author Carlos Andre Martins de Assis e Gabriel Clemente Franklin
   @file CHurst.h
*/


/** @brief Classe para o metodo de Van Everdingen and Hurst
    ///Implemente o metodo de van Everdigen & Hurst para gas e oleo
    @class CHurst
*/


#ifndef CHurst_h
#define CHurst_h

#include "CSimulador.h"



using namespace std;

class CHurst: public CSimulador

{
      protected:
                double U; ///< Constante de influxo de agua do aquifero
                vector<double>td; ///< tempo adimensional
      
       public:
             

             ///@brief Construtor para o caso gás
             CHurst(int _n,int _op,double _dt,double _pi,double _poro,
                    double _h,double _sw,double _Q,double _T,double _ro,double _d,
                    double _v,double _B,double _Tpc, double _Ppc,double _z,double a_pi,
                    double a_poro, double a_h,double _k,double _ct,double _u,double _re)
               :CSimulador (_n,_op,_dt,_pi,_poro,_h,_sw,_Q,_T,_ro,_d,_v,
                            _B,_Tpc,_Ppc,_z,a_pi,a_poro,a_h,_k,_ct,_u,_re),td(_n+1)
             {SolverGas(); titulo = "Hurst";}

             ///@brief construtor para o caso óleo
             CHurst(int _n,int _op,double _dt,double _pi,double _poro,
                    double _h,double _sw,double _Q,double _ro,double _d,
                    double _v,double _B,double _ceo, double _co,double a_pi,double a_poro,
                    double a_h,double _k,double _ct,double _u,double _re)
                  :CSimulador (_n,_op,_dt,_pi,_poro,_h,_sw,_Q,_ro,_d,_v,
                            _B,_ceo,_co,a_pi,a_poro,a_h,_k,_ct,_u,_re),td(_n+1)
             {SolverOleo(); titulo = "Hurst";}
             
             ///@brief  construtor usado no arquivo da interface              
            CHurst(int size): CSimulador(size)
             { titulo = "Hurst";}
             
             ///@brief construtor para arquivo do prompt
             CHurst(int _n,int _op,double _dt,int _geom):CSimulador(_n,_op,_dt,_geom),td(_n+1)
             {titulo = "Hurst";}
             
                                            
        ///@brief  calcula Wd, usando as classes ClaplaceWd e CStefehst             
        double InfluxoWd(double t);
        ///@brief Calcula o vetor tempo adimensional e tempo
        virtual void Tempo();
         ///@brief  Inicializa as constantes para caso Radial ou Linear
         virtual    void Constantes();    
         ///@brief  Resolve o problema para o caso do gas
         virtual void SolverGas();
         ///@brief  Resolve o problema para o caso do oleo
         virtual void SolverOleo();
         ///@brief  Destrutor
         virtual   ~CHurst(){}
      
      
      };
#endif
