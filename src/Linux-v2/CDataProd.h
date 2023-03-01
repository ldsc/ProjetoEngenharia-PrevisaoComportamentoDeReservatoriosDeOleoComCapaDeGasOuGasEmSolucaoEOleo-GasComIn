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
	double pi; ///press�o inicial (pi < pi_res) - Press�o CRK4 inicio
	double Npi; ///Produ��o de �leo Acumulada at� So|p=pi
	std::vector<double> gp; ///Produ��o Acumulada de G�s GP
	double RGOinst; ///Raz�o G�s-�leo Inst
	double n; ///Volume Original de �leo
	double swi; ///Satura��o de �gua Irredut�vel
	double rsi; ///Rs inicial em pi_res
	double boi; ///Bo inicial do �leo em pi_res
	double bob; ///Bo na press�o de bolha
	std::vector<double> np; ///Vetor de Armazenamento dos valores da Produ��o Acumulada de �leo
	public:
	CDataProd()
    { 
           std:: cout <<"Entre com a pressao inicial de analise pi em kgf/cm^2."<<'\n';
           std::cin>>pi; std::cin.get();     
           std::cout <<"Entre com a producao acumulada inicial de oleo Npi em m^3 std."<<'\n';
           std::cin>>Npi; std::cin.get(); np.push_back(Npi);     
           std::cout <<"Entre com o volume original de oleo N em m^3 std."<<'\n';
           std::cin>>n; std::cin.get();     
           std::cout <<"Entre com a raz�o gas oleo instant�nea RGOinst em m^3 std/m^3 std."<<'\n';
           std::cin>>RGOinst; std::cin.get();   
           std::cout <<"Entre com a saturacao de agua irredutivel swi"<<'\n';
           std::cin>>swi; std::cin.get();
           std::cout <<"Entre com a Rs inicial Rsi em m^3 std/m^3 std."<<'\n';
           std::cin>>rsi; std::cin.get();
           std::cout <<"Entre com Bo inicial do �leo em pi_res em m^3 std/m^3 std."<<'\n';
           std::cin>>boi; std::cin.get();
           std::cout <<"Entre com Bo na press�o de bolha em m^3 std/m^3 std."<<'\n';
           std::cin>>bob; std::cin.get();                 
    }; ///Construtor Default - Entrada Manual
	CDataProd(const CDataProd& obj): p(obj.p), pi(obj.pi), Npi(obj.Npi), gp(obj.gp), RGOinst(obj.RGOinst){}; ///Construtor de C�pia
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
	
	double PI(){return pi;} ///Retorna a Press�o Inicial de An�lise
	double NPI(){return Npi;} ///Retorna a Produ��o Acumulada de �leo avaliada na press�o inicial de an�lise
	double N(){return n;} ///Retorna o Volume Original de �leo no Reservat�rio
	double GP(double boMAX, double invbgMAX,double rsMAX, double _np);///M�todo que calcula a Produ��o Acumulada de G�s (GP)
	double NP(double soMAX, double boMAX);///M�todo que calcula a Produ��o Acumulada de �leo (NP)
	double RGOINST(){return RGOinst;} ///Retorna a Raz�o G�s �leo Instant�nea
	double SWI(){return swi;} ///Retorna a Satura��o de �gua inicial
	double RSI(){return rsi;} ///Retorna a Raz�o de Solubilidade Inicial 
	double BOI(){return boi;} ///Retorna BO inicial
	double BOB(){return bob;} ///Retorna BO inicial no ponto de bolha

	void Entrada(); ///M�todo de Entrada Manual
	void SaidaDisco(std::ofstream& fout); ///M�todo para salvar em disco
	void Saida(std::ostream& os); ///M�todo para sa�da na tela
};
#endif
