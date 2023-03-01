#ifndef CMuskat_h
#define CMuskat_h

#include<iostream>	
#include<cstdlib> 
#include<fstream>
#include<functional> 
#include<algorithm> 
#include<vector> 
#include<string> 
#include<iterator>
#include "CGnuplot.h" 
#include<utility>
#include<cmath>
#include<iomanip>
#include "CSimuladorCGGS.h"
#include "CDataProd.h"

class CMuskat: protected CSimuladorCGGS //implementar método para devolução da string da Eq. de Muskat

{
	protected:
	std::vector<double> eta; ///Parâmetro Eta da Eq. de Muskat
	std::vector<double> alfa; ///Parâmetro Alfa da Eq. de Muskat
	std::vector<double> lambda; ///Parâmetro Lambda da Eq. de Muskat
	std::vector<double> psi; ///Parâmetro Psi da Eq. de Muskat
	std::vector<double> xi; ///Parâmetro Xi da Eq. de Muskat
	std::vector<double> r; ///Parâmetro R da Eq. de Muskat
	std::vector<double> muskeq; ///Vetor que contém os valores de dSo/dp
	std::vector<double> so; ///Vetor de saída da saturação de óleo
	std::vector<double> np; ///Vetor de saída para a produção acumulada de óleo
	std::vector<double> gp; ///Vetor de saída para a produção acumulada de gás
	std::vector<double> psim; ///Vetor de saída para as pressões de simulação
	CDataProd* dprod; /// Ponteiro de linkagem para a classe CDataProd
	int ic=0; ///variável de controle auxiliar	
	public: 
	CMuskat(CDataProd& obj2){
		dprod=&obj2;
		r.push_back(dprod->RGOINST());
		np.push_back(dprod->NPI());	
		//Eta(); Alfa(); Lambda(); Xi();
	}; ///Construtor Default - Recebe objeto CDataProd por referência
	CMuskat(std::string abcde,CDataProd& obj2):CSimuladorCGGS(abcde){
		dprod=&obj2;
		//std::cout<<"Qual o razão M da capa de gás?" <<'\n';
		//std::cin>>m;
		//std::cout<<"Qual a razão de ciclagem C"<<'\n';
		//std::cin>>cicl;
		r.push_back(dprod->RGOINST());
		np.push_back(dprod->NPI());
		Eta(); Alfa(); Lambda(); Xi();
	}; ///Construtor Padrão da Classe para entrada em arquivo de disco
             
	//~CMuskat();
	void Eta(); ///Método para cálculo do Parâmetro Eta
	void Alfa(); ///Método para cálculo do Parâmetro Alfa
	void Lambda(); ///Método para cálculo do Parâmetro Lambda
	void Psi(); ///Método para cálculo do Parâmetro Psi
	void Xi(); ///Método para cálculo do Parâmetro Xi
	void R(); ///Método para cálculo do Parâmetro R
	void Output_NP(double _np){np.push_back(_np);} ///Método para preencher os vetores de saída
	void Output_GP(double _gp){gp.push_back(_gp);} ///Método para preencher os vetores de saída
	void Output_Psim(std::vector<double> _xj){psim=_xj;} ///Método para preencher os vetores de saída
	double muskequation(double p, double satoleo); ///Método que contém a equação de Muskat
	void Grafico(); ///Método Gráfico Gnuplot da Classe
	void Entrada(){	
		CSimuladorCGGS::Entrada();	
		//std::cout<<"Qual o razão M da capa de gás? ......... ";
		//std::cin>>m;
		//std::cout<<"\n";
		//std::cout<<"Qual a razão de ciclagem C? ......... ";
		//std::cin>>cicl;
		std::cout<<"\n";
		Eta(); Alfa(); Lambda(); Xi();
	}; ///Método de Entrada
	void Saida(std::ostream& os); ///Método de Saída para a Tela
	void SaidaDisco(std::ofstream& fout); ///Método de Saída para o Disco
	double curvakgko(double soleo); ///Método que contém a curva de permeabilidade
	void SaidaResumida(); ///Método para a saída condensada dos resultados de interesse da simulação (exclui variáveis de cálculo)
	void GP0(double _p){
		int i=pos_pressao(_p);
		double aux=dprod->N()*(((bo[i]*invbg[i])-rs[i])*(1-(dprod->NPI()/dprod->N()))-((dprod->BOI()*invbg[i])-dprod->RSI()));
		gp.push_back(aux);
	} ///Método para calcular a produção acumulada para a pressão inicial de análise
	friend class CRK4; 
	
};
#endif
