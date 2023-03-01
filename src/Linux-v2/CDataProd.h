#ifndef CDataProd_h
#define CDataProd_h

#include<iostream>	
#include<cstdlib> 
#include<fstream>
#include<functional> 
#include<algorithm> 
#include<vector> 
#include<string> 
#include "CGnuplot.h" 
#include<utility>
#include<cmath>
#include<iomanip>

class CDataProd{
	protected:
	double p;
	double pi; ///pressão inicial (pi < pi_res) - Pressão CRK4 inicio
	double Npi; ///Produção de Óleo Acumulada até So|p=pi
	std::vector<double> gp; ///Produção Acumulada de Gás GP
	double RGOinst; ///Razão Gás-Óleo Inst
	double n; ///Volume Original de Óleo
	double swi; ///Saturação de Água Irredutível
	double rsi; ///Rs inicial em pi_res
	double boi; ///Bo inicial do óleo em pi_res
	double bob; ///Bo na pressão de bolha
	std::vector<double> np; ///Vetor de Armazenamento dos valores da Produção Acumulada de Óleo
	public:
	CDataProd()
    { 
           std:: cout <<"Entre com a pressao inicial de analise pi em kgf/cm^2."<<'\n';
           std::cin>>pi; std::cin.get();     
           std::cout <<"Entre com a producao acumulada inicial de oleo Npi em m^3 std."<<'\n';
           std::cin>>Npi; std::cin.get(); np.push_back(Npi);     
           std::cout <<"Entre com o volume original de oleo N em m^3 std."<<'\n';
           std::cin>>n; std::cin.get();     
           std::cout <<"Entre com a razão gas oleo instantânea RGOinst em m^3 std/m^3 std."<<'\n';
           std::cin>>RGOinst; std::cin.get();   
           std::cout <<"Entre com a saturacao de agua irredutivel swi"<<'\n';
           std::cin>>swi; std::cin.get();
           std::cout <<"Entre com a Rs inicial Rsi em m^3 std/m^3 std."<<'\n';
           std::cin>>rsi; std::cin.get();
           std::cout <<"Entre com Bo inicial do óleo em pi_res em m^3 std/m^3 std."<<'\n';
           std::cin>>boi; std::cin.get();
           std::cout <<"Entre com Bo na pressão de bolha em m^3 std/m^3 std."<<'\n';
           std::cin>>bob; std::cin.get();                 
    }; ///Construtor Default - Entrada Manual
	CDataProd(const CDataProd& obj): p(obj.p), pi(obj.pi), Npi(obj.Npi), gp(obj.gp), RGOinst(obj.RGOinst){}; ///Construtor de Cópia
	CDataProd(double _p, double _pi, double _Npi, double _gp, double _RGOinst): p(_p), pi(_pi), Npi(_Npi), gp(_gp), RGOinst(_RGOinst){}; ///Construtor Sobrecarregado
	CDataProd(std::string nomearq){
		std::ifstream fin(nomearq.c_str());
		if(!fin.good()){
		std::cout<<"Arquivo nao encontrado"<<'\n';
		exit(0);
		}
		double auxvar=0;
		fin.ignore(5000,'\n');
		fin.ignore(5000,'\n');
		fin.ignore(5000,'\n');
		fin.ignore(5000,'\n');
		fin.ignore(55,'\n');
		fin>>n; fin.ignore(55,'\n'); 
		fin.ignore(55,'\n');
		fin>>swi;fin.ignore(55,'\n');  
		fin.ignore(55,'\n');
		fin>>rsi;fin.ignore(55,'\n');  
		fin.ignore(55,'\n');
		fin>>boi;fin.ignore(55,'\n'); 
		fin.ignore(55,'\n');
		fin>>bob;fin.ignore(55,'\n');  
		fin.ignore(55,'\n');
		fin>>Npi;fin.ignore(55,'\n'); 
		fin.ignore(55,'\n');
		fin>>RGOinst;fin.ignore(55,'\n');  
		fin.ignore(55,'\n');
		fin>>pi;fin.ignore(55,'\n');  
		fin.close();
	} ///Construtor Default para Entrada em Arquivo de Disco
	//~CDataProd();
	
	double PI(){return pi;} ///Retorna a Pressão Inicial de Análise
	double NPI(){return Npi;} ///Retorna a Produção Acumulada de Óleo avaliada na pressão inicial de análise
	double N(){return n;} ///Retorna o Volume Original de Óleo no Reservatório
	double GP(double boMAX, double invbgMAX,double rsMAX, double _np);///Método que calcula a Produção Acumulada de Gás (GP)
	double NP(double soMAX, double boMAX);///Método que calcula a Produção Acumulada de Óleo (NP)
	double RGOINST(){return RGOinst;} ///Retorna a Razão Gás Óleo Instantânea
	double SWI(){return swi;} ///Retorna a Saturação de Água inicial
	double RSI(){return rsi;} ///Retorna a Razão de Solubilidade Inicial 
	double BOI(){return boi;} ///Retorna BO inicial
	double BOB(){return bob;} ///Retorna BO inicial no ponto de bolha

	void Entrada(); ///Método de Entrada Manual
	void SaidaDisco(std::ofstream& fout); ///Método para salvar em disco
	void Saida(std::ostream& os); ///Método para saída na tela
};
#endif
