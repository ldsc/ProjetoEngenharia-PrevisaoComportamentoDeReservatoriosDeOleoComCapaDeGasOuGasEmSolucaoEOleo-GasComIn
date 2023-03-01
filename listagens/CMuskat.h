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

class CMuskat: protected CSimuladorCGGS //implementar m�todo para devolu��o da string da Eq. de Muskat

{
	protected:
	std::vector<double> eta; ///Par�metro Eta da Eq. de Muskat
	std::vector<double> alfa; ///Par�metro Alfa da Eq. de Muskat
	std::vector<double> lambda; ///Par�metro Lambda da Eq. de Muskat
	std::vector<double> psi; ///Par�metro Psi da Eq. de Muskat
	std::vector<double> xi; ///Par�metro Xi da Eq. de Muskat
	std::vector<double> r; ///Par�metro R da Eq. de Muskat
	std::vector<double> muskeq; ///Vetor que cont�m os valores de dSo/dp
	std::vector<double> so; ///Vetor de sa�da da satura��o de �leo
	std::vector<double> np; ///Vetor de sa�da para a produ��o acumulada de �leo
	std::vector<double> gp; ///Vetor de sa�da para a produ��o acumulada de g�s
	std::vector<double> psim; ///Vetor de sa�da para as press�es de simula��o
	CDataProd* dprod; /// Ponteiro de linkagem para a classe CDataProd
	int ic=0; ///vari�vel de controle auxiliar	
	public: 
	CMuskat(CDataProd& obj2){
		dprod=&obj2;
		r.push_back(dprod->RGOINST());
		np.push_back(dprod->NPI());	
		//Eta(); Alfa(); Lambda(); Xi();
	}; ///Construtor Default - Recebe objeto CDataProd por refer�ncia
	CMuskat(std::string abcde,CDataProd& obj2):CSimuladorCGGS(abcde){
		dprod=&obj2;
		//std::cout<<"Qual o raz�o M da capa de g�s?" <<'\n';
		//std::cin>>m;
		//std::cout<<"Qual a raz�o de ciclagem C"<<'\n';
		//std::cin>>cicl;
		r.push_back(dprod->RGOINST());
		np.push_back(dprod->NPI());
		Eta(); Alfa(); Lambda(); Xi();
	}; ///Construtor Padr�o da Classe para entrada em arquivo de disco
             
	//~CMuskat();
	void Eta(); ///M�todo para c�lculo do Par�metro Eta
	void Alfa(); ///M�todo para c�lculo do Par�metro Alfa
	void Lambda(); ///M�todo para c�lculo do Par�metro Lambda
	void Psi(); ///M�todo para c�lculo do Par�metro Psi
	void Xi(); ///M�todo para c�lculo do Par�metro Xi
	void R(); ///M�todo para c�lculo do Par�metro R
	void Output_NP(double _np){np.push_back(_np);} ///M�todo para preencher os vetores de sa�da
	void Output_GP(double _gp){gp.push_back(_gp);} ///M�todo para preencher os vetores de sa�da
	void Output_Psim(std::vector<double> _xj){psim=_xj;} ///M�todo para preencher os vetores de sa�da
	double muskequation(double p, double satoleo); ///M�todo que cont�m a equa��o de Muskat
	void Grafico(); ///M�todo Gr�fico Gnuplot da Classe
	void Entrada(){	
		CSimuladorCGGS::Entrada();	
		//std::cout<<"Qual o raz�o M da capa de g�s? ......... ";
		//std::cin>>m;
		//std::cout<<"\n";
		//std::cout<<"Qual a raz�o de ciclagem C? ......... ";
		//std::cin>>cicl;
		std::cout<<"\n";
		Eta(); Alfa(); Lambda(); Xi();
	}; ///M�todo de Entrada
	void Saida(std::ostream& os); ///M�todo de Sa�da para a Tela
	void SaidaDisco(std::ofstream& fout); ///M�todo de Sa�da para o Disco
	double curvakgko(double soleo); ///M�todo que cont�m a curva de permeabilidade
	void SaidaResumida(); ///M�todo para a sa�da condensada dos resultados de interesse da simula��o (exclui vari�veis de c�lculo)
	void GP0(double _p){
		int i=pos_pressao(_p);
		double aux=dprod->N()*(((bo[i]*invbg[i])-rs[i])*(1-(dprod->NPI()/dprod->N()))-((dprod->BOI()*invbg[i])-dprod->RSI()));
		gp.push_back(aux);
	} ///M�todo para calcular a produ��o acumulada para a press�o inicial de an�lise
	friend class CRK4; 
	
};
#endif
