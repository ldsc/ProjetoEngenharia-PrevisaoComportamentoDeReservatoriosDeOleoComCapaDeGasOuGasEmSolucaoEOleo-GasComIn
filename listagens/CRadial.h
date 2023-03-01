/** Previsao do Compartamento de Reservatorios
   de Gas e de Oleo com Influxo de Agua
    @author Carlos Andre Martins de Assis e Gabriel Clemente Franklin
   @file CRadial.h
*/
/** @brief Classe que representa uma geometria Radial
    @class CRadial
*/

#ifndef CRadial_h
#define CRadial_h

#include "CGeometria.h"

class CRadial: public CGeometria
{
      protected:
                double r; ///< Raio
      public:
             ///@brief Construtor default e sobrecarregado
             CRadial(double _r=0.0):r(_r){};
             ///@brief Construtor sobrecarregado de copia
             CRadial(const CRadial &obj):r(obj.r){};
             ///@brief Metodos de Entrada e Saida padrao, diferenciados para arquivo
             virtual void Entrada( std :: ostream & os , std :: istream & is);
             virtual void Entrada(std :: ifstream & is);
             virtual void Saida( std :: ostream & os );
             virtual double R(){return r;}; ///Retorna r
             ///@brief Destrutor
             virtual ~CRadial(){};
};

#endif
