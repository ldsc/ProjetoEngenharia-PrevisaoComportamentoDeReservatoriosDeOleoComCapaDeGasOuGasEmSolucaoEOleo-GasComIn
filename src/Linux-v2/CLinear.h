/** Previsao do Compartamento de Reservatorios
   de Gas e de Oleo com Influxo de Agua
    @author Carlos Andre Martins de Assis e Gabriel Clemente Franklin
   @file CLinear.h
*/
/**      @brief Classe que representa uma geometria Linear
         @class CLinear
*/

#ifndef CLinear_h
#define CLinear_h

#include "CGeometria.h"

class CLinear: public CGeometria
{
      protected:
                double w; ///< Largura
                double l; ///< Comprimento
      public:
             ///@brief Construtor default e sobrecarregado
             CLinear(double _w=0.0, double _l=0.0):w(_w),l(_l){};
             ///@brief Construtor sobrecarregado de copia
             CLinear(const CLinear &obj):w(obj.w),l(obj.l){};
             ///@brief Metodos de Entrada e Saida padrao, diferenciados para arquivo
             virtual void Entrada( std :: ostream & os , std :: istream & is);
             virtual void Entrada(std :: ifstream & is);
             virtual void Saida( std :: ostream & os );
             ///@brief Membros publicos que retornam os parametros
             virtual double L(){return l;};
             virtual double W(){return w;};
             ///@brief Destrutor
             virtual ~CLinear(){};
};

#endif
