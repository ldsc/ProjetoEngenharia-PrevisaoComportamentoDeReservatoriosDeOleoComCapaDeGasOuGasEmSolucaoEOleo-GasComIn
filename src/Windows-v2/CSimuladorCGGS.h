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
	double m; ///Raz�o entre a capa de g�s e a se��o de �leo do reservat�rio 
	double cicl; ///Raz�o de Ciclagem
	std::vector<double> p; ///Press�o
	std::vector<double> bo; ///Fator Volume-Forma��o do �leo
	std::vector<double> dbodp; ///Derivada de Bo com a press�o
	std::vector<double> bg; ///Fator Volume-Forma��o do G�s
	std::vector<double> invbg; ///Inverso do Bg
	std::vector<double> dinvbgdp; ///Derivada do Inverso do Bg com a press�o
	std::vector<double> rs; ///Raz�o de Solubilidade
	std::vector<double> drsdp; ///Derivada da Raz�o de Solubilidade com a press�o
	std::vector<double> mio; ///Viscosidade do �leo
	std::vector<double> mig; ///Viscosidade do G�s
	std::vector<double> kg; ///Permeabilidade do G�s
	std::vector<double> ko; ///Permeabilidade do �leo
	std::vector<double> kg_ko; ///Armazena a fra��o entre as permeabilidades
	std::vector<double> mio_mig; ///Armazena a fra��o entre as viscosidades
	std::vector<double>::iterator it;
	int var_ctrl; ///vari�vel de controle
	
	public:
	CSimuladorCGGS(){}; ///Construtor Default
	CSimuladorCGGS(std::string nome){
		std::ifstream fin(nome.c_str());
		if(!fin.good()){
		std::cout<<"Arquivo n�o encontrado"<<'\n';
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
	}; ///Construtor Padr�o da Classe
	//~CSimuladorCGGS();
	void Grafico(); ///M�todo Gr�fico Gnuplot
	void Resultados(std::ostream& os); ///Mostra os Resultados
	//double MetMuskat(); //Solver?
	void P(); ///Entrada da Press�o
	void DBODP(); ///C�lculo da Derivada de Bo com a press�o
	void INVBG(); ///Entrada da Press�o
	void BO(); ///Entrada do Fator Volume-Forma��o do �leo
	void DINVBGDP(); ///C�lculo da Derivada do Inverso do Bg com a press�o
	void RS(); ///Entrada da Raz�o de Solubilidade
	void DRSDP(); ///C�lculo da Derivada da Raz�o de Solubilidade com a press�o
	void MIO_MIG(); ///Entrada das Viscosidades
	void KG_KO(); ///Entrada das Permeabilidades - caso n�o haja uma curva
	void Entrada(){P(); BO(); RS(); DBODP(); INVBG(); DINVBGDP();DRSDP();MIO_MIG();std::cout <<"Entrada Terminada" <<'\n';} ///M�todo de Entrada
	int pos_pressao(double presaux){   
        it=find(p.begin(),p.end(),presaux);
        int pos = distance(p.begin(), it);
        return pos;
    } ///M�todo para orienta��o em qual posi��o do vetor o c�lculo ser� baseado
	friend std::ifstream& operator>>(std::ifstream& fin, CSimuladorCGGS& obj); ///Operador Sobrecarregado para salvar em disco 
	friend std::ostream& operator<<(std::ostream& out, CSimuladorCGGS& obj); ///Operador Sobrecarregado para mostrar na tela os conte�dos dos vetores
	double GetBo(double pressao); ///M�todo Get para retornar o valor de Bo
	void MostraVetor(std::vector<double> v1); ///M�todo para mostrar o vetor na tela
	void SaidaDisco(std::ofstream& fout); ///M�todo para salvar no disco
	void SalvaGraf (CGnuplot& graf); ///M�todo para salvar o gr�fico
	void Grafico_Sim(); ///M�todo Gr�fico Gnuplot
};
#endif
