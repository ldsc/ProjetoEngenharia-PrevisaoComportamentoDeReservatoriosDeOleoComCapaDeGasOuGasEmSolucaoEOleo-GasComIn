/** Previsao do Compartamento de Reservatorios
   de Gas e de Oleo com Influxo de Agua
   @author Carlos Andre Martins de Assis e Gabriel Clemente Franklin
   @file CFluido.h
*/

/** @brief Classe com as propriedades basicas de um fluido.
    Esta classe e herdada pela classe CGas e COleo 
    @class CFluido
*/

#ifndef CFluido_h
#define CFluido_h
#include <iostream>
#include <fstream>

  
      //! Enumeracao com os tipos de fluidos
        enum {egas=1, eoleo=2};

class CFluido
{
       protected:
             double d; ///< densidade
             double v; ///< volume total
             double b; ///< fator volume formacao
        public:     
             ///@brief Construtor default e sobrecarregado
             CFluido(double _d=0.0,double _v=0.0,double _b=0.0):d(_d),v(_v),b(_b){};
             ///@brief Construtor sobrecarregado de copia
             CFluido(const CFluido& obj):d(obj.d),v(obj.v),b(obj.b){};
             ///@brief Metodos de Entrada e Saida padrao, diferenciados para arquivo
             virtual void Entrada(std :: ostream & os , std :: istream & is);
             virtual void Entrada(std :: ifstream & is);
             virtual void Saida( std :: ostream & os );
             ///Retorna densidade
             double  D() {return d;};
             ///Retorna volume total
             double  V() {return v;};
             ///Retorna valor volume formacao
             double  B() {return b;};
             ///Calcula o fator de compressibilidade Z na classe CGas
             virtual double BrillZ(double p){};
             ///Retorna o fator volume formacao
             virtual double B(double P){};
             ///Retorna a compressibilidade efetiva do oleo na classe herdeira COleo
             virtual double Ceo(){};
             ///Retorna a compressibilidade do oleo na classe herdeira COleo
             virtual double Co(){};
             ///@brief Destrutor
             virtual ~CFluido(){};
             
             
      
      };


#endif
