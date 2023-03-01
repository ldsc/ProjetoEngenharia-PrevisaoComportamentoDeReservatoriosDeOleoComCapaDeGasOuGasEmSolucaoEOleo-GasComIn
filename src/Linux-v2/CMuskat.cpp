#include "CMuskat.h"
#include <math.h>
//----------------------------------------CMUSKATCPP------------------------------------------
void CMuskat::Eta(){     
       double etaaux;
       for(int i=0;i<var_ctrl;i++)
       {
           etaaux=mio_mig[i]*dbodp[i]*(1/bo[i]);
           eta.push_back(etaaux);
       }
}
void CMuskat::Alfa(){    
       double alfaaux;
       for(int i=0;i<var_ctrl;i++)
       {
           alfaaux=mio_mig[i]*bo[i]*invbg[i];
           alfa.push_back(alfaaux);
       }  
}
void CMuskat::Lambda(){    
       double lambaux;
       for(int i=0;i<var_ctrl;i++)
       {
           lambaux=drsdp[i]*((1/invbg[i])/bo[i]);
           lambda.push_back(lambaux);
       }
}
void CMuskat::Psi(){    
       double psiaux;
	   for(int i=0;i<var_ctrl;i++)
       {
           psiaux=kg_ko[i];
           psi.push_back(psiaux);
       }
}
void CMuskat::Xi(){    
       double xiaux;
       for(int i=0;i<var_ctrl;i++)
       {
           xiaux=(1/invbg[i])*dinvbgdp[i];
           xi.push_back(xiaux);
       }  
}
void CMuskat::R() {
       double raux;
       for(int i=0;i<var_ctrl;i++)
       {
           raux=(kg_ko[i]*mio_mig[i]*(bo[i]*invbg[i])+rs[i]);
           r.push_back(raux);
       }  
}
double CMuskat::muskequation(double p, double satoleo){  //revisar    
	   int i=pos_pressao(p); ic++;
       double aux;
       aux=((satoleo*lambda[i]) + ((1-satoleo-dprod->SWI())*xi[i]) + (satoleo*eta[i])*(curvakgko(satoleo)-(cicl*(curvakgko(satoleo)*mio_mig[i]*bo[i]*invbg[i]+rs[i])/alfa[i]))+ (m*(1-dprod->SWI())*xi[i]))/
       (1+(mio_mig[i]*(curvakgko(satoleo)-(cicl*(curvakgko(satoleo)*mio_mig[i]*bo[i]*invbg[i]+rs[i])/alfa[i]))));
       muskeq.push_back(aux);
       if(ic%2!=1){r.push_back(curvakgko(satoleo)*mio_mig[i]*bo[i]*invbg[i]+rs[i]);so.push_back(satoleo);}
       return aux;   
}
void CMuskat::Saida(std::ostream& os){
	   	CSimuladorCGGS::Resultados(std::cout);
	   	os<<'\n';
		os<<"-------------------------------------------------------------------------------------------------"<<'\n';
		os<<"A seguir, os parametros de calculo da Eq. de Muskat:"<<'\n';
		os<<"-------------------------------------------------------------------------------------------------"<<'\n';
		os<< "Eta" << std::setw(12) << "Alfa" << std::setw(12) << "Lambda" /*<< std::setw(12) << "Psi" */<<std::setw(12) << "Xi" <<std::setw(12) << "R" <<std::endl;
    	for(int j=0; j<var_ctrl; j++)
    	{        
     	os<<std::showpoint<<std::setprecision(7)<< eta[j] <<std::setw(12)<<std::setprecision(7)<< alfa[j] <<std::setw(12)<<std::setprecision(7);
     	os<<lambda[j] /*<<std::setw(12)<<std::setprecision(7)<<psi[j]*/ <<std::setw(12)<<std::setprecision(7)<<xi[j] <<std::setw(12)<<std::setprecision(7);
     	os<<r[j]<<'\n';
		}
		os<<"-------------------------------------------------------------------------------------------------"<<'\n';
		os<<"\n";
       }   
void CMuskat::SaidaDisco(std::ofstream& fout){
	//ofstream fout(s.c_str());
	CSimuladorCGGS::SaidaDisco(fout);
	fout<<'\n';
	fout<<"-------------------------------------------------------------------------------------------------"<<'\n';
	fout<<"A seguir, os parametros de calculo da Eq. de Muskat:"<<'\n';
	fout<<"-------------------------------------------------------------------------------------------------"<<'\n';
	fout << "Eta" << std::setw(12) << "Alfa" << std::setw(12) << "Lambda" /*<< std::setw(12) << "Psi" */<<std::setw(12) << "Xi" <<std::setw(12) << "R" <<std::endl;
    for(int j=0; j<var_ctrl; j++)
    {        
     fout<<std::showpoint<<std::setprecision(7)<< eta[j] <<std::setw(12)<<std::setprecision(7)<< alfa[j] <<std::setw(12)<<std::setprecision(7);
     fout<<lambda[j] /*<<std::setw(12)<<std::setprecision(7)<<psi[j]*/ <<std::setw(12)<<std::setprecision(7)<<xi[j] <<std::setw(12)<<std::setprecision(7);
     fout<<r[j]<<'\n';
	}
	fout<<"-------------------------------------------------------------------------------------------------"<<'\n';
	fout<<"\n";
}
void CMuskat::Grafico(){
	std::cout<<'\n';
	CSimuladorCGGS::Grafico_Sim();}	
double CMuskat::curvakgko(double soleo){ //log(kg/ko)=-6,1484Sl+3,5070 para 0,2<Sl<0.95
	double sl=soleo+dprod->SWI();
	//if(sl>0.2 && sl<0.95){
	double aux=((-6.1484*(sl))+3.5070);
	double aux2=pow(10,aux);
	kg_ko.push_back(aux2);
	return aux2;	
}
void CMuskat::SaidaResumida(){
	using namespace std;
	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__)
	system("cls");
	#elif defined(unix) || defined(__unix) || defined(__unix__) || defined(__APPLE__)
	system("clear");
	#endif
	cout<<"A tabela a seguir contem os resultados resumidos de maior interesse para o usuário do programa"<<'\n';
	cout<<"Pressão "<<"  "<<"Saturação de Óleo"<<"  "<<"Produção Acumulada de Óleo"<<"  "<<"Produção Acumulada de Gás"<<"  "<<"Razão Gás-Óleo Instantânea"<<'\n';
	cout<<"kgf/cm^2"<<"  "<<"   adimensional  "<<"  "<<"          m^3std         "<<"  "<<"          m^3std          "<<"  "<<"       m^3std/m^3std      "<<'\n';
	cout<<"-------------------------------------------------------------------------------------------------------------"<<'\n';
	for (int i=0;i<psim.size();i++){
	cout<<right<<psim[i]<<"  "<<right<<setw(17)<<setprecision(8)<<so[i+1]<<"  ";
	cout<<right<<setw(26)<<setprecision(8)<<np[i]<<"  "<<right<<setw(25)<<setprecision(8)<<gp[i]<<"  "<<right<<setw(26)<<setprecision(8)<<r[i]<<endl;
	}
}
