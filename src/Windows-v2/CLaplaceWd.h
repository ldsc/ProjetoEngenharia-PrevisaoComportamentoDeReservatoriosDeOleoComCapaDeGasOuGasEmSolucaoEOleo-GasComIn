/** Previsao do Compartamento de Reservatorios
   de Gas e de Oleo com Influxo de Agua
    @author Carlos Andre Martins de Assis e Gabriel Clemente Franklin
   @file CLaplaceWD.h
*/
/**      @brief Classe que gera influxo adimensional wd no Campo de Laplace
         Bibliografia: Previsao de Comportamento de Reservatorios
         de Petroleo. Apendices F,G e H.
         @class CLaplaceWd
         
*/

#ifndef CLaplaceWd_h
#define CLaplaceWd_h


class CLaplaceWd
{          
     public:
     ///@brief Acha a solucao no campo de Laplace para o caso Radial Infinito
     static double  RadInf(double x); 
     ///@brief Acha a solucao no campo de Laplace para o caso Radial Realimentado
     static double  RadRea(double x,double re,double ro);
     ///@brief Acha a solucao no campo de Laplace para o caso Radial Selado
     static double  RadSel(double x,double re,double ro);
     ///@brief Acha a solucao no campo de Laplace para o caso Linear Infinito
     static double  LinInf(double x);
     ///@brief Acha a solucao no campo de Laplace para o caso Linear Realimentado
     static double  LinRea(double x);
     ///@brief Acha a solucao no campo de Laplace para o caso Linear Selado
     static double  LinSel(double x);
     
      
      };





#endif
