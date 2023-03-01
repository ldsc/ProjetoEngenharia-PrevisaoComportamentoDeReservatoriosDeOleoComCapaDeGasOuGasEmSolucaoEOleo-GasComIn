/** Previsao do Compartamento de Reservatorios
   de Gas e de Oleo com Influxo de Agua
    @author Carlos Andre Martins de Assis e Gabriel Clemente Franklin
   @file CGas.h
*/

/** @brief Classe com as propriedade de um gas
    //Herda as propriedade basicas de umfluido da classe CFluido
    @class CGas
*/
#ifndef CGas_h
#define CGas_h

#include "CFluido.h"

class CGas: public CFluido
{
      private:
              double Tpc;///< temperatura pseudocritica (é uma mistura)
              double Ppc;///< temperatura pseudocritica (é uma mistura)
              double z; ///< fator de compressibilidade
              double t; ///< Temperatura do gás (mesma do reservatorio, aproximadamente constante na produção)
              
  
      public:
             ///@brief Construtor default e sobrecarregado
             CGas(double _d=0.0,double _v=0.0,double _B=0.0,double _Tpc=0., double _Ppc=0.,double _z=0.,double _t=0.)
                         :CFluido(_d,_v,_B),Tpc(_Tpc),Ppc(_Ppc),z(_z),t(_t){};
             ///@brief Construtor sobrecarregado de cópia
             CGas(const CGas& obj):CFluido(obj),Tpc(obj.Tpc),Ppc(obj.Ppc),z(obj.z),t(obj.t){};
             
             
             ///@brief retorna o fator de compressibilidade
             double  Z() {return z;};
             ///@brief método polinomial para calculo de z 
             double  PolinomioZ(double a, double b, double c, double p);
             ///@brief método de Brill &Begges para calculo de z 
             virtual double  BrillZ(double p);
             ///@brief Calcula B para gás seco 
             virtual double B(double P); 
             ///@brief Metodos de Entrada e Saida padrao, diferenciados para arquivo
             virtual void Entrada( std :: ostream & os , std :: istream & is);
             virtual void Entrada(std :: ifstream & is);
             virtual void Saida( std :: ostream & os );
              ///@brief Destrutor
             virtual ~CGas(){};
             
      };






#endif
