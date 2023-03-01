#include "CDataProd.h"


double CDataProd::GP(double boMAX, double invbgMAX,double rsMAX, double _np){
		double aux= n*(((boMAX*invbgMAX-rsMAX)*(1-(_np/n)))-((boi*invbgMAX)-rsi)); 
		gp.push_back(aux);
		return aux;
		}///M�todo que calcula a Produ��o Acumulada de G�s (GP)
double CDataProd::NP(double soMAX, double boMAX){
		double aux= n*(1-((soMAX/(1-swi))*(boi/boMAX)));
		np.push_back(aux);
		return aux;	
	}
	
void CDataProd::Entrada(){
	   	std::cout <<"Entre com a press�o inicial pi em kgf/cm^2."<<'\n';
        std::cin>>pi; std::cin.get();     
        std::cout <<"Entre com a produ��o acumulada inicial de �leo Npi em m^3 std."<<'\n';
        std::cin>>Npi; std::cin.get();     
        std::cout <<"Entre com o Volume Original de �leo N em m^3 std."<<'\n';
        std::cin>>n; std::cin.get();     
        std::cout <<"Entre com a Raz�o G�s �leo Instant�nea RGOinst em m^3 std/m^3 std."<<'\n';
        std::cin>>RGOinst; std::cin.get();   
        std::cout <<"Entre com a Satura��o de �gua Irredut�vel swi"<<'\n';
        std::cin>>swi; std::cin.get();
        std::cout <<"Entre com a Rs inicial Rsi em m^3 std/m^3 std."<<'\n';
        std::cin>>rsi; std::cin.get();
        std::cin>>boi; std::cin.get();
        std::cout <<"Entre com Bo na press�o de bolha em m^3 std/m^3 std."<<'\n';
        std::cin>>bob; std::cin.get();
	} 
void CDataProd::SaidaDisco(std::ofstream& fout){
		//ofstream fout(s.c_str())
		fout<<"A seguir os dados de produ��o do reservat�rio:"<<'\n';
		fout<<"-------------------------------------------------------------------------------------------------"<<'\n';
        fout<<"A press�o inicial de an�lise �: " << PI() << " kgf/cm^2." <<'\n';
        fout<<"O volume original de �leo �: " << N() << " m^3 std." <<'\n';
        fout<<"A raz�o g�s-�leo instant�nea � de: "<<RGOINST()<<" m^3 std/m^3 std."<<'\n';
        fout<<"A produ��o de �leo acumulada para a press�o inicial de an�lise � de: " <<NPI()<< " m^3 std."<<'\n';
        fout<<"A satura��o de �gua irredut�vel � de: "<<SWI()<<"%"<<'\n';
        fout<<"A raz�o de solubilidade inicial � de: "<<RSI()<<"m^3 std/m^3 std"<<'\n';
        fout<<"O fator volume-forma��o inicial do �leo � de: "<<BOI()<<"m^3 std/m^3 std"<<'\n';
        fout<<"O fator volume-forma��o do �leo na press�o de bolha � de: "<<BOB()<<"m^3 std/m^3 std"<<'\n';
        fout<<"A produ��o de g�s acumulada para a press�o prevista foi de: "<<gp.back()<<" m^3 std"<<'\n';
        fout<<"A produ��o de �leo acumulada para a press�o prevista � de: "<<np.back()<<" m^3 std."<<'\n';
		fout<<"-------------------------------------------------------------------------------------------------"<<'\n';	
        fout<<'\n';
	} ///M�todo para salvar em disco
void CDataProd::Saida(std::ostream& os)
    {
    	 os<<"A seguir os dados de produ��o do reservat�rio:"<<'\n';
		 os<<"-------------------------------------------------------------------------------------------------"<<'\n';
         os<<"Gerando a sa�da de dados da classe CDataProd: "<<'\n';
         os<<"A press�o inicial de an�lise �: " << PI() << " kgf/cm^2." <<'\n';
         os<<"O volume original de �leo �: " << N() << " m^3 std." <<'\n';
         os<<"A raz�o g�s-�leo instant�nea � de: "<<RGOINST()<<" m^3 std/m^3 std."<<'\n';
         os<<"A produ��o de �leo acumulada para a press�o inicial de an�lise � de: " <<NPI()<< " m^3 std."<<'\n';
         os<<"A satura��o de �gua irredut�vel � de: "<<SWI()<<"%"<<'\n';
         os<<"A raz�o de solubilidade inicial � de: "<<RSI()<<"m^3 std/m^3 std"<<'\n';
         os<<"O fator volume-forma��o inicial do �leo � de: "<<BOI()<<"m^3 std/m^3 std"<<'\n';
         os<<"O fator volume-forma��o do �leo na press�o de bolha � de: "<<BOB()<<"m^3 std/m^3 std"<<'\n';
         os<<"A produ��o de g�s acumulada para a press�o prevista foi de: "<<gp.back()<<"m^3 std"<<'\n';
         os<<"A produ��o de �leo acumulada para a press�o prevista � de: "<<np.back()<<"m^3 std."<<'\n';
         os<<"-------------------------------------------------------------------------------------------------"<<'\n';
}///M�todo para sa�da na tela
