/** Previsao do Compartamento de Reservatorios
   de Gas e de Oleo com Influxo de Agua
    @author Carlos Andre Martins de Assis e Gabriel Clemente Franklin
   @file CInterface.h
*/

/** @brief Classe de interface em modo texto.
    @class CInterface
*/
#ifndef CInterface_h
#define CInterface_h

#include <string>
#include "CSimulador.h"

enum {ehurst =0, fet = 1};

class CInterface
{
      private:
              
              string linha;
              string erro;
              string nomeArq; ///< Pega do teclado o nome do arquivo
              int p;          ///< Atributo que controla o menu
              int tipo;       ///< Tipo de fluido, Gas(1) ou Oleo(2)
              int geom;       ///< Tipo de Geometria, Radial(1) ou Linear(2)
              int metodo;     ///< Metodo de calculo, Hurst(1) ou Fetkovich(2)
              ifstream *fin;  ///< arquivo de entrada
              CSimulador *Sim1; ///< Necessario para o polimorfismo, ponteiro para a base CSimulador
              
              //Estes proximos objetos sao criados apenas para usar seus metodos de entrada;
              CReservatorio *rr; ///< rocha reservatorio
              CFluido *fluido; ///< fluido que satura a rocha reservatorio
              CAquifero *ra; ///< rocha aquifero
              
              
      public:
             
             ///@brief Construtor
             CInterface():linha("\n---------------------------------\n"),erro("\n\tOpcao invalida. Tente novamente!"),
                          p(0),tipo(0),geom(0),fin(NULL),rr(NULL),ra(NULL),fluido(NULL){Inicio();};
             
             ///@brief Inicia a interacao com o usuario.
             void Inicio();
             ///@brief Pergunta ao usuario o que ele deseja fazer com os dados simulados
             void MostrarResultados();
             ///@brief Pergunta o tipo de grafico a ser gerado
             void Comparacao();
             ///@brief Seta os dados de simulacao e executa a simulacao
             void Set();
             ///@brief Salva os dados fornecidos pelo usuario via teclado
             void SalvarDados();
             ///@brief Salva os resultados da simulacao
             void SalvarSimulacao();
             ///@brief Valida a entrada do usuario via teclado
             void ValidaEntrada( int &opcao,int min,int max=200);
             ////@brief Destrutor
             ~CInterface();
      
};

#endif
