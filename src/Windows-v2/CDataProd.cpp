#include "CDataProd.h"


double CDataProd::GP(double boMAX, double invbgMAX,double rsMAX, double _np){
		double aux= n*(((boMAX*invbgMAX-rsMAX)*(1-(_np/n)))-((boi*invbgMAX)-rsi)); 
		gp.push_back(aux);
		return aux;
		}///Método que calcula a Produção Acumulada de Gás (GP)
double CDataProd::NP(double soMAX, double boMAX){
		double aux= n*(1-((soMAX/(1-swi))*(boi/boMAX)));
		np.push_back(aux);
		return aux;	
	}
	
void CDataProd::Entrada(){
	   	std::cout <<"Entre com a pressão inicial pi em kgf/cm^2."<<'\n';
        std::cin>>pi; std::cin.get();     
        std::cout <<"Entre com a produção acumulada inicial de óleo Npi em m^3 std."<<'\n';
        std::cin>>Npi; std::cin.get();     
        std::cout <<"Entre com o Volume Original de Óleo N em m^3 std."<<'\n';
        std::cin>>n; std::cin.get();     
        std::cout <<"Entre com a Razão Gás Óleo Instantânea RGOinst em m^3 std/m^3 std."<<'\n';
        std::cin>>RGOinst; std::cin.get();   
        std::cout <<"Entre com a Saturação de Água Irredutível swi"<<'\n';
        std::cin>>swi; std::cin.get();
        std::cout <<"Entre com a Rs inicial Rsi em m^3 std/m^3 std."<<'\n';
        std::cin>>rsi; std::cin.get();
        std::cin>>boi; std::cin.get();
        std::cout <<"Entre com Bo na pressão de bolha em m^3 std/m^3 std."<<'\n';
        std::cin>>bob; std::cin.get();
	} 
void CDataProd::SaidaDisco(std::ofstream& fout){
		//ofstream fout(s.c_str())
		fout<<"A seguir os dados de produção do reservatório:"<<'\n';
		fout<<"-------------------------------------------------------------------------------------------------"<<'\n';
        fout<<"A pressão inicial de análise é: " << PI() << " kgf/cm^2." <<'\n';
        fout<<"O volume original de óleo é: " << N() << " m^3 std." <<'\n';
        fout<<"A razão gás-óleo instantânea é de: "<<RGOINST()<<" m^3 std/m^3 std."<<'\n';
        fout<<"A produção de óleo acumulada para a pressão inicial de análise é de: " <<NPI()<< " m^3 std."<<'\n';
        fout<<"A saturação de água irredutível é de: "<<SWI()<<"%"<<'\n';
        fout<<"A razão de solubilidade inicial é de: "<<RSI()<<"m^3 std/m^3 std"<<'\n';
        fout<<"O fator volume-formação inicial do óleo é de: "<<BOI()<<"m^3 std/m^3 std"<<'\n';
        fout<<"O fator volume-formação do óleo na pressão de bolha é de: "<<BOB()<<"m^3 std/m^3 std"<<'\n';
        fout<<"A produção de gás acumulada para a pressão prevista foi de: "<<gp.back()<<" m^3 std"<<'\n';
        fout<<"A produção de óleo acumulada para a pressão prevista é de: "<<np.back()<<" m^3 std."<<'\n';
		fout<<"-------------------------------------------------------------------------------------------------"<<'\n';	
        fout<<'\n';
	} ///Método para salvar em disco
void CDataProd::Saida(std::ostream& os)
    {
    	 os<<"A seguir os dados de produção do reservatório:"<<'\n';
		 os<<"-------------------------------------------------------------------------------------------------"<<'\n';
         os<<"Gerando a saída de dados da classe CDataProd: "<<'\n';
         os<<"A pressão inicial de análise é: " << PI() << " kgf/cm^2." <<'\n';
         os<<"O volume original de óleo é: " << N() << " m^3 std." <<'\n';
         os<<"A razão gás-óleo instantânea é de: "<<RGOINST()<<" m^3 std/m^3 std."<<'\n';
         os<<"A produção de óleo acumulada para a pressão inicial de análise é de: " <<NPI()<< " m^3 std."<<'\n';
         os<<"A saturação de água irredutível é de: "<<SWI()<<"%"<<'\n';
         os<<"A razão de solubilidade inicial é de: "<<RSI()<<"m^3 std/m^3 std"<<'\n';
         os<<"O fator volume-formação inicial do óleo é de: "<<BOI()<<"m^3 std/m^3 std"<<'\n';
         os<<"O fator volume-formação do óleo na pressão de bolha é de: "<<BOB()<<"m^3 std/m^3 std"<<'\n';
         os<<"A produção de gás acumulada para a pressão prevista foi de: "<<gp.back()<<"m^3 std"<<'\n';
         os<<"A produção de óleo acumulada para a pressão prevista é de: "<<np.back()<<"m^3 std."<<'\n';
         os<<"-------------------------------------------------------------------------------------------------"<<'\n';
}///Método para saída na tela
