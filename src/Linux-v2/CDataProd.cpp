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
	} 
void CDataProd::SaidaDisco(std::ofstream& fout){
		//ofstream fout(s.c_str())
		fout<<"A seguir os dados de producao do reservatorio:"<<'\n';
		fout<<"-------------------------------------------------------------------------------------------------"<<'\n';
        fout<<"A pressao inicial de analise e: " << PI() << " kgf/cm^2." <<'\n';
        fout<<"O volume original de oleo �: " << N() << " m^3 std." <<'\n';
        fout<<"A razao gas-oleo instantanea � de: "<<RGOINST()<<" m^3 std/m^3 std."<<'\n';
        fout<<"A producao de oleo acumulada para a press�o inicial de analise e de: " <<NPI()<< " m^3 std."<<'\n';
        fout<<"A satura��o de �gua irredut�vel e de: "<<SWI()<<"%"<<'\n';
        fout<<"A razao de solubilidade inicial � de: "<<RSI()<<"m^3 std/m^3 std"<<'\n';
        fout<<"O fator volume-formacao inicial do oleo e de: "<<BOI()<<"m^3 std/m^3 std"<<'\n';
        fout<<"O fator volume-forma��o do oleo na pressao de bolha e de: "<<BOB()<<"m^3 std/m^3 std"<<'\n';
        fout<<"A producao de gas acumulada para a pressao prevista foi de: "<<gp.back()<<" m^3 std"<<'\n';
        fout<<"A producao de oleo acumulada para a pressao prevista e de: "<<np.back()<<" m^3 std."<<'\n';
		fout<<"-------------------------------------------------------------------------------------------------"<<'\n';	
        fout<<'\n';
	} ///M�todo para salvar em disco
void CDataProd::Saida(std::ostream& os)
    {
    	 os<<"A seguir os dados de producao do reservatorio:"<<'\n';
		 os<<"-------------------------------------------------------------------------------------------------"<<'\n';
         os<<"Gerando a saida de dados da classe CDataProd: "<<'\n';
         os<<"A pressao inicial de analise e: " << PI() << " kgf/cm^2." <<'\n';
         os<<"O volume original de oleo e: " << N() << " m^3 std." <<'\n';
         os<<"A razao gas-oleo instant�nea e de: "<<RGOINST()<<" m^3 std/m^3 std."<<'\n';
         os<<"A producao de oleo acumulada para a pressao inicial de analise e de: " <<NPI()<< " m^3 std."<<'\n';
         os<<"A saturacao de agua irredutivel e de: "<<SWI()<<"%"<<'\n';
         os<<"A razao de solubilidade inicial e de: "<<RSI()<<"m^3 std/m^3 std"<<'\n';
         os<<"O fator volume-formacao inicial do oleo e de: "<<BOI()<<"m^3 std/m^3 std"<<'\n';
         os<<"O fator volume-formacao do oleo na pressao de bolha e de: "<<BOB()<<"m^3 std/m^3 std"<<'\n';
         os<<"A producao de gas acumulada para a pressao prevista foi de: "<<gp.back()<<"m^3 std"<<'\n';
         os<<"A producao de oleo acumulada para a pressao prevista e de: "<<np.back()<<"m^3 std."<<'\n';
         os<<"-------------------------------------------------------------------------------------------------"<<'\n';
}///M�todo para sa�da na tela
