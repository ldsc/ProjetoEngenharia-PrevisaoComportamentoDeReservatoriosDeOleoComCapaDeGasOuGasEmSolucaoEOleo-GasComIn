/** Previsao do Compartamento de Reservatorios
   de Gas e de Oleo com Influxo de Agua
    @author Carlos Andre Martins de Assis e Gabriel Clemente Franklin
   @file COleo.h
*/
/**      @brief Classe que represeta um Oleo
         @class COleo
*/

#ifndef COleo_h
#define COleo_h

#include "CFluido.h"
#include <iostream>

class COleo: public CFluido
{
      protected:
                double ceo; ///< compressibilidade efetiva do oleo
                double co;  ///< compressibilidade do oleo
      public:
             ///@brief Construtor default e sobrecarregado
             COleo(double _d=0.0,double _v=0.0,double _B=0.0,double _ceo=0.0,double _co=0.0)
                          :CFluido(_d,_v,_B),ceo(_ceo),co(_co){};
             ///@brief Construtor sobrecarregado de copia
             COleo(const COleo &o):CFluido(o),ceo(o.ceo),co(o.co){};
             ///@brief Calcula Ceo
             double Ceo(double,double,double); 
             ///@brief Membros publicos que retornam os parametros
             double Ceo(){return ceo;};
             double Co(){return co;};
             ///@brief Metodos de Entrada e Saida padrao, diferenciados para arquivo
             virtual void Entrada( std :: ostream & os , std :: istream & is);
             virtual void Entrada(std :: ifstream & is);
             virtual void Saida( std :: ostream & os );
             ///@brief Destrutor
             virtual ~COleo(){};
};

#endif
             
