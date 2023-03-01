/** Previsao do Compartamento de Reservatorios
   de Gas e de Oleo com Influxo de Agua
    @author Carlos Andre Martins de Assis e Gabriel Clemente Franklin
   @file CGeometria.h
*/



/** @brief Classe abstrata para uma geometria.
    *Classe abstrata herdada pelas geometrias radiais e lineares
    @class CGeometria
*/
#ifndef CGeometria_h
#define CGeometria_h

#include <iostream>

  ///@brief enumeracao para tipo de geometria
  enum {eradial=1, elinear=2};

class CGeometria
{
      public:
             ///@brief Metodos de Entrada e Saida padrao, diferenciados para arquivo
             virtual void Entrada( std :: ostream & os , std :: istream & is)=0;
             virtual void Entrada(std :: ifstream & is)=0;
             virtual void Saida( std :: ostream & os )=0;
             ///@brief Metodos das classes herdeiras
             virtual double R(){return 0;};
             virtual double L(){return 0;};
             virtual double W(){return 0;};
             ///@brief Destrutor
             virtual ~CGeometria(){};
};

#endif
                
