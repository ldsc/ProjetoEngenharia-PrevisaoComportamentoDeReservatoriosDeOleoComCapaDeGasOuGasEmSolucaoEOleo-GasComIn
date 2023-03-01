/** Previsao do Compartamento de Reservatorios
   de Gas e de Oleo com Influxo de Agua
    @author Carlos Andre Martins de Assis e Gabriel Clemente Franklin
   @file CStehfest.h
  
   */
   
   /** @brief Algoritmo de Stehfest para inversao numerica do campo de Laplace, Apendice H.
       @Class CStehfest
   
   */

#ifndef CStehfest_h
#define CStehfest_h

#include <vector>
class CStehfest  
{
      public:
             
             int n; ///< numero de iteracoes
             std::vector<double>v; ///< vetor v do algoritmo de Stehfest
             
      public:
             ///@brief Construtor default e sobrecarregado que inicializa v 
            CStehfest(int _n=10):n(_n),v(_n)
            {SetV();}; 
             ///@brief Construtor de copia
            CStehfest(const CStehfest& obj):v(obj.v),n(obj.n){};
            ///@brief Metodo que calcula o fatorial de N
            double Fatorial(int N);
            ///@brief Define o vetor V
            void  SetV();
            ///@Inverte a solucao do campo de Laplace para o campo real
            double Inversao(double (*f)(double),double x);
            ///@Inverte a solucao do campo de Laplace para o campo real (sobrecarga)
            double Inversao(double (*f)(double,double,double),double re,double ro,double x);
            ///@brief Destrutor
            ~CStehfest(){};
      
      };



#endif
