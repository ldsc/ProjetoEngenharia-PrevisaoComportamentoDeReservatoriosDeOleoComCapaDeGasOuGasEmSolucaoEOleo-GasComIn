/** Previsao do Compartamento de Reservatorios
   de Gas e de Oleo com Influxo de Agua
    @author Carlos Andre Martins de Assis e Gabriel Clemente Franklin
   @file CReservatorio.h
*/

/** @brief Classe com as propriedade do Reservatorio
    @class CReservatorio
*/


#ifndef CReservatorio_h
#define CReservatorio_h

#include "CRocha.h"


class CReservatorio: public CRocha
{
      protected:
                double sw; ///< saturacao de agua
                double q; ///< vazao
           
      public:
             ///@brief  Construtor default
             CReservatorio(int op):CRocha(op){};
             
             ///@brief Construtor sobrecarregado(quantidade de parqmetros) RADIAL
             CReservatorio(double _pi,double _poro, double _h,double _sw,double _Q,double _ro)
                                     :CRocha(_pi,_poro,_h,_ro),sw(_sw),q(_Q){};
             ///@brief Construtor sobrecarregado(quantidade de parqmetros) LINEAR
             CReservatorio(double _pi,double _poro, double _h,double _sw,double _Q,double _l,double _w)
                                  :CRocha(_pi,_poro,_h,_l,_w),sw(_sw),q(_Q){};
             ///@brief Construtor sobrecarregado de copia                     
             CReservatorio(const CReservatorio& obj):CRocha(obj),sw(obj.sw),q(obj.q){};
             ///@brief Metodos de Entrada e Saida padrao, diferenciados para arquivo
             virtual void Entrada( std :: ostream & os , std :: istream & is);
             virtual void Entrada(std :: ifstream & is);
             virtual void Saida( std :: ostream & os );
             ///@brief Membros publicos que retornam os parametros
             double Sw(){return sw;};
             double Q(){return q;};       
             ///@brief Destrutor 
             virtual ~CReservatorio(){};
      
      };


#endif
