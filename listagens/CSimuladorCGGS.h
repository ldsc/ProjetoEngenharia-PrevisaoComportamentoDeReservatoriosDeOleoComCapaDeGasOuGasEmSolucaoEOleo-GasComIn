#ifndef CSimuladorCGGS_h
#define CSimuladorCGGS_h

#include<iostream>	
#include<cstdlib> 
#include<fstream>
#include<functional> 
#include<algorithm> 
#include<vector> 
#include<string> 
#include<iterator>
#include "CGnuplot.h" 
#include<locale.h>
#include<stdlib.h>
#include<utility>
#include<cmath>
#include<iomanip>
#include "CDataProd.h"

class CSimuladorCGGS{
	protected:
	CDataProd* dprod;
	double m; ///Razão entre a capa de gás e a seção de óleo do reservatório 
	double cicl; ///Razão de Ciclagem
	std::vector<double> p; ///Pressão
	std::vector<double> bo; ///Fator Volume-Formação do Óleo
	std::vector<double> dbodp; ///Derivada de Bo com a pressão
	std::vector<double> bg; ///Fator Volume-Formação do Gás
	std::vector<double> invbg; ///Inverso do Bg
	std::vector<double> dinvbgdp; ///Derivada do Inverso do Bg com a pressão
	std::vector<double> rs; ///Razão de Solubilidade
	std::vector<double> drsdp; ///Derivada da Razão de Solubilidade com a pressão
	std::vector<double> mio; ///Viscosidade do Óleo
	std::vector<double> mig; ///Viscosidade do Gás
	std::vector<double> kg; ///Permeabilidade do Gás
	std::vector<double> ko; ///Permeabilidade do Óleo
	std::vector<double> kg_ko; ///Armazena a fração entre as permeabilidades
	std::vector<double> mio_mig; ///Armazena a fração entre as viscosidades
	std::vector<double>::iterator it;
	int var_ctrl; ///variável de controle
	
	public:
	CSimuladorCGGS(){}; ///Construtor Default
	CSimuladorCGGS(std::string nome){
		std::ifstream fin(nome.c_str());
		if(!fin.good()){
		std::cout<<"Arquivo não encontrado"<<'\n';
		exit(0);
		}
		double auxvar=0;
		std::cout<<"Lendo arqeuivo"<<'\n';
		fin.ignore(5000,'\n');
		fin.ignore(5000,'\n');
		fin.ignore(61,'\n');
		fin>>m; fin.ignore(55,'\n');
		fin.ignore(55,'\n');
		fin>>cicl; fin.ignore(55,'\n');
		
		for(int i=0;i<18;i++)
		{fin.ignore(5000,'\n');}
		var_ctrl=0;
		do{
			fin>>auxvar; std::cout<<auxvar; p.push_back(auxvar); 
			fin>>auxvar; std::cout<<auxvar;bo.push_back(auxvar); 
			fin>>auxvar; std::cout<<auxvar;invbg.push_back(auxvar); 
			fin>>auxvar; std::cout<<auxvar;rs.push_back(auxvar); 
			fin>>auxvar; std::cout<<auxvar;mio_mig.push_back(auxvar);
			fin>>auxvar; std::cout<<auxvar;if(auxvar!=0){dbodp.push_back(auxvar);}
			fin>>auxvar; std::cout<<auxvar;if(auxvar!=0){dinvbgdp.push_back(auxvar);}
			fin>>auxvar; std::cout<<auxvar;if(auxvar!=0){drsdp.push_back(auxvar);}
			fin.ignore(5000,'\n');
			var_ctrl++;
		}while(!fin.eof());
		if (dbodp.size()==0){DBODP();}
		if (dinvbgdp.size()==0){DINVBGDP();}
		if (drsdp.size()==0){DRSDP();}
		p.pop_back();
		bo.pop_back();
		invbg.pop_back();
		rs.pop_back();
		mio_mig.pop_back();
		dbodp.pop_back();
		dinvbgdp.pop_back();
		drsdp.pop_back();
		fin.close();
		std::cout<<"Leitura terminada! CSimuladorCGGS"<<'\n';
	}; ///Construtor Padrão da Classe
	//~CSimuladorCGGS();
	void Grafico(); ///Método Gráfico Gnuplot
	void Resultados(std::ostream& os); ///Mostra os Resultados
	//double MetMuskat(); //Solver?
	void P(); ///Entrada da Pressão
	void DBODP(); ///Cálculo da Derivada de Bo com a pressão
	void INVBG(); ///Entrada da Pressão
	void BO(); ///Entrada do Fator Volume-Formação do Óleo
	void DINVBGDP(); ///Cálculo da Derivada do Inverso do Bg com a pressão
	void RS(); ///Entrada da Razão de Solubilidade
	void DRSDP(); ///Cálculo da Derivada da Razão de Solubilidade com a pressão
	void MIO_MIG(); ///Entrada das Viscosidades
	void KG_KO(); ///Entrada das Permeabilidades - caso não haja uma curva
	void Entrada(){P(); BO(); RS(); DBODP(); INVBG(); DINVBGDP();DRSDP();MIO_MIG();std::cout <<"Entrada Terminada" <<'\n';} ///Método de Entrada
	int pos_pressao(double presaux){   
        it=find(p.begin(),p.end(),presaux);
        int pos = distance(p.begin(), it);
        return pos;
    } ///Método para orientação em qual posição do vetor o cálculo será baseado
	friend std::ifstream& operator>>(std::ifstream& fin, CSimuladorCGGS& obj); ///Operador Sobrecarregado para salvar em disco 
	friend std::ostream& operator<<(std::ostream& out, CSimuladorCGGS& obj); ///Operador Sobrecarregado para mostrar na tela os conteúdos dos vetores
	double GetBo(double pressao); ///Método Get para retornar o valor de Bo
	void MostraVetor(std::vector<double> v1); ///Método para mostrar o vetor na tela
	void SaidaDisco(std::ofstream& fout); ///Método para salvar no disco
	void SalvaGraf (CGnuplot& graf); ///Método para salvar o gráfico
	void Grafico_Sim(); ///Método Gráfico Gnuplot
};
#endif
