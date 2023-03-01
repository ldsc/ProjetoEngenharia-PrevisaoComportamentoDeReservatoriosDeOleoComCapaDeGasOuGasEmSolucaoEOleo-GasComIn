/* Previsão do Compartamento de Reservatórios
   de Gás e de Óleo com Influxo de Água
   
   @Autores: Carlos André Martins de Assis e Gabriel Clemente Franklin
   @file CInterface.cpp
*/

#include "CInterface.h"
#include "CGnuplot.h"
#include "CHurst.h"
#include "CFetkovich.h"


using namespace std;

void CInterface::Inicio()
{
  
     cout<<linha<<"\tComo sera a entrada de dados de poco?:"<<linha
     <<"1)Via arquivo de disco;\n2)Via teclado;"<<endl;
     ValidaEntrada(p,1, 2);
     switch(p)
     {
     case 1:
          {
              cout<<"\nDigite o nome do arquivo:"<<endl;
              cin>>nomeArq; cin.get();
              fin=new ifstream(nomeArq.c_str());
              while(!fin->is_open())
              {
                                    cout<<"\nArquivo inexistente!\nDigite o nome do arquivo:"<<endl;
                                    cin>>nomeArq; cin.get();
                                    fin->open(nomeArq.c_str()); 
              } 
              
              break;
          }
     case 2:
          {
              cout<<linha<<"\tQual a geometria das rochas?:"<<linha
              <<"1)Radial;\n2)Linear;"<<endl;
              ValidaEntrada( geom,1, 2);
              cout<<linha<<"\tQual o fluido que preenche o reservatorio?:"<<linha
              <<"1)Gas;\n2)Oleo;"<<endl;
              ValidaEntrada(tipo,egas,eoleo);
              if(tipo==egas){fluido=new CGas;}
              else {fluido=new COleo;}
              rr=new CReservatorio(geom); //rocha reservatorio
              ra=new CAquifero(geom); //rocha aquifero
              rr->Entrada(cout,cin);
              fluido->Entrada(cout,cin);
              ra->Entrada(cout,cin);
              cin.get();
              SalvarDados();
              fin=new ifstream(nomeArq.c_str());
              break;
          }
     }
   
     Set();
}

void CInterface::Set()
{
     int n,op=3,f;
     
     cout<<linha<<"Escolha os parametros da simulacao::"<<linha<<endl;
     cout<<"\nEntre com n (numero de anos):";
     ValidaEntrada(n,0);
     cout<<"\nQue fracao de ano sera o passo? (ex.:1=1 ano, 4= 1/4 de ano...):";
     ValidaEntrada(f,1);
     cout<<"\nEntre com o metodo:\n0-Hurst\n1-Fetkovich:";
     ValidaEntrada(metodo,0,1);
     //cria o objeto de simulação de acordo com o método
     (*fin)>>geom;
     if (metodo == ehurst)
     {             
              Sim1=new CHurst(f*n,op,365/f,geom);
     }else if (metodo == fet)
          {
              Sim1 = new CFetkovich (f*n,op,365/f,geom);
          }
              
       (*fin)>>(*Sim1);
       
        fin->close();
        
        if ( metodo == ehurst && Sim1->Tipo() == egas)
     {
     cout<<"\nEntre com o fluxo:\n1-Infinito\n2-Realimentado\n3-Selado:";
     ValidaEntrada(op,1,3);   
     }
     
        Sim1->SetInfluxo(op);
       //chama o solver de acordo com o fluido
        if (Sim1->Tipo() == egas) 
        {
            Sim1->SolverGas();       
        }else
         {
            Sim1->SolverOleo();
         }   
      
     
    MostrarResultados();
}

void CInterface::MostrarResultados()
{
     while(p)
     {
              //system("clear");
              cout<<linha<<"\t-Menu-\nEscolha uma das opcoes:"<<linha
              <<"1)Mostrar Simulacao\n2)Grafico da solucao\n3)Exportar simulacao como txt\n4)Dados da Simulacao"<<endl
              <<"0) Sair\nO que deseja fazer?"<<endl;
              ValidaEntrada(p,0,4);
              switch(p)
              {
                case 0:
                    break;
                case 1:
                   Sim1->Resultados(cout);
                   Pause(); break;
                case 2:
                   Comparacao(); break;
                case 3:
                   SalvarSimulacao(); break;
                case 4:
                    cout<<*Sim1;
                    Pause(); break;
                }
     }
}

void CInterface::Pause()
{
cout<<endl<<"Pressione enter para continuar..."<<endl<<endl; cin.get();
}


void CInterface::Comparacao()
{
     int tipo=4;
     cout<<endl<<"Escolha o tipo de grafico:"<<endl;
     cout<<"0)Pressao no contato x Tempo (dias)"<<endl<<"1)Influxo acumulado x Tempo (dias)"
     <<endl<<"2)Influxo acumulado x Pressao no contato"<<endl;
     ValidaEntrada(tipo,0,2);
     Sim1->Grafico(tipo);
}

void CInterface::SalvarDados()
{
     cout<<"\nOs dados de poco serao salvos em disco para uso posterior. Digite o nome do arquivo:"<<endl;
     getline(cin,nomeArq);
     ofstream fout(nomeArq.c_str());
     fout<<geom<<endl;
     fout<<tipo<<endl;
     rr->Saida(fout);
     fluido->Saida(fout);
     ra->Saida(fout);
     fout.close();
}

void CInterface::SalvarSimulacao()
{
     cout<<"\n\nEntre com o nome do arquivo:";
     getline(cin,nomeArq);
     ofstream fout(nomeArq.c_str()); 
     Sim1->Resultados(fout);
     fout.close();
     cout<<"\n\nSimulacao Exportada com sucesso!"<<endl;
     Pause();
}


void CInterface::ValidaEntrada(int &opcao,int min, int max)
{
     while (true)
              { 
                    cin>>opcao;
                    
                    if((opcao>=min) && (opcao<=max) && cin.good())
                    {     cin.get();        
                          break;
                          }else
                          {    cin.clear();
                               string entrada;
                               getline(cin,entrada);
                               cout<<erro<<endl;
                              
                           }             
                    }
 }

CInterface::~CInterface()
{
     if(fin!=NULL)  delete fin;
     if(rr!=NULL) delete rr;
     if(ra!=NULL) delete ra;
     if(fluido!=NULL) delete fluido;
     if(Sim1!=NULL) delete Sim1;  
}

