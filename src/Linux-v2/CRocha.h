/** Previsao do Compartamento de Reservatorios
   de Gas e de Oleo com Influxo de Agua
    @author Carlos Andre Martins de Assis e Gabriel Clemente Franklin
   @file CRocha.h
*/
/** @brief Classe abstrata que representa uma rocha porosa (aquifero ou reservatorio)
    @class CRocha
    */

#ifndef CRocha_h
#define CRocha_h

#include <iostream>
#include <fstream>
#include "CLinear.h"
#include "CRadial.h"

class CRocha
{
      protected:
                double pi; ///< pressao inicial
                double poro; ///< porosidade
                double h; ///< espessuta média
      public:
             ///@brief Geometria da Rocha, Linear ou Radial
             CGeometria *g; 
             ///@brief Construtor default, define a CGeometria
             CRocha(int geom);
              ///@brief Construtor default e sobrecarregado
             CRocha(double _pi,double _poro, double _h,double _r)
                           :pi(_pi),poro(_poro),h(_h) {g=new CRadial(_r);};
             CRocha(double _pi,double _poro, double _h,double _l,double _w)
                           :pi(_pi),poro(_poro),h(_h) {g=new CLinear(_l,_w);};             
              ///@brief Construtor sobrecarregado de copia
             CRocha(const CRocha &o):pi(o.pi),poro(o.poro),h(o.h),g(o.g){};
             ///@brief Metodos de Entrada e Saida padrao, diferenciados para arquivo
             virtual void Entrada( std :: ostream & os , std :: istream & is);
             virtual void Entrada(std :: ifstream & is);
             virtual void Saida( std :: ostream & os );
             ///@brief Membros publicos que retornam os parametros
             double Pi(){return pi;};
             double Poro(){return poro;};
             double H(){return h;};
             ///@brief Destrutor
             virtual ~CRocha(){if (g!=NULL) delete g;};
};

#endif
