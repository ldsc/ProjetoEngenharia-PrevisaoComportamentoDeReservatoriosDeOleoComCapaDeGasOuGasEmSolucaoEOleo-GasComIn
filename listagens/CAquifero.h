/** Previsao do Compartamento de Reservatorios
   de Gas e de Oleo com Influxo de Agua
   @author Carlos Andre Martins de Assis e Gabriel Clemente Franklin
   
*/

/** @brief Classe com as propriedades do aquifero.
    

    @class CAquifero
    @file CAquifero.h
*/
#ifndef CAquifero_h
#define CAquifero_h

#include "CRocha.h"

class CAquifero: public CRocha
{
      protected:
                double k; ///< permeabilidade
                double ct; ///< compressibilidade total
                double u; ///< viscosidade da água
      public:
             
             ///@brief Construtor default
             CAquifero(int op):CRocha(op){}; 
             ///@brief Construtor sobrecarregado(quantidade de parâmetros) radial 
             CAquifero(double _pi,double _poro, double _h,double _k,double _ct,double _u,double _re)
                              :CRocha(_pi,_poro,_h,_re),k(_k),ct(_ct),u(_u){}
             ///@brief Construtor sobrecarregado(quantidade de parâmetros) linear 
             CAquifero(double _pi,double _poro, double _h,double _k,double _ct,double _u,double _l,double _w)
                                 :CRocha(_pi,_poro,_h,_l,_w),k(_k),ct(_ct),u(_u){};
             ///@brief Construtor sobrecarregado de cópia
             CAquifero(const CAquifero& obj):CRocha(obj),k(obj.k),ct(obj.ct),u(obj.u){};
             //Metodos de Entrada e Saida padrao, diferenciados para arquivo
             ///@brief Metodos de Entrada e Saida padrao, diferenciados para arquivo
             virtual void Entrada( std :: ostream & os , std :: istream & is);
             virtual void Entrada(std :: ifstream & is);
             virtual void Saida( std :: ostream & os );
             ///@brief Membros publicos que retornam os parametros
             double K(){return k;};
             double Ct(){return ct;};
             double U(){return u;};
             ///@brief Destrutor
             virtual  ~CAquifero(){};
      };

#endif
