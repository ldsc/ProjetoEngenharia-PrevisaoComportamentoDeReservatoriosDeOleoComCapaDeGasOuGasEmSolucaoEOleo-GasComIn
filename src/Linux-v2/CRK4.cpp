#include "CRK4.h"

void CRK4::Saida(std::ostream& os, std::istream& cin)
{      
       using namespace std;
       ostream_iterator<double> output(os," ");
       cm->dprod->Saida(os);
       os<<"Qual vetor queres que sejas mostrado? 1-Pressao 2-Saturacao de oleo 3-K1 4-K2 5-K3 6-K4 7-Todos" << std::endl;
       int op;
       cin>>op;
       os << "Mostrando os resultados numericos..." << std::endl;
       switch(op)
       {
       case 1: 
       {    
       os<< "XJ: " << '\n';
       copy(xj.begin(),xj.end(),output); os<<std::endl; break;
       }
       case 2: 
       {    
       os<< "YJ: " << '\n';
       copy(yj.begin(),yj.end(),output); os<<std::endl; break;
       }
       case 3: 
       {    
       os<< "K1: " << '\n';
       copy(k1.begin(),k1.end(),output); os<<std::endl; break;
       } 
       case 4: 
       {    
       os<< "K2: " << '\n';
       copy(k2.begin(),k2.end(),output); os<<std::endl; break;
       }
       case 5: 
       {    
       os<< "K3: " << '\n';
       copy(k3.begin(),k3.end(),output); os<<std::endl; break;
       }
       case 6: 
       {    
       os<< "K4: " << '\n';
       copy(k4.begin(),k4.end(),output); os<<std::endl; break;
       }
       case 7:
       {
       os << "P" << std::setw(16) << "So" << std::setw(16) << "K1" << std::setw(16) << "K2" <<std::setw(16) << "K3" <<std::setw(16) << "K4" << std::endl;
       os << setprecision(15) << showpoint;  
          for(int j=0; j<xj.size(); j++)
          {        
          os << xj[j] <<" "<< yj[j] <<" "<<k1[j] <<" "<<k2[j] <<" "<< k3[j]<<" "<< k4[j] <<std::endl;
          }
       break;
       }
   }

}

void CRK4::SaidaDisco(std::ofstream& fout){
	fout<<"-------------------------------------------------------------------------------------------------"<<'\n';
	fout<<"A seguir os dados provenientes da integracao da EDO de Muskat: "<<'\n';
	fout<<"-------------------------------------------------------------------------------------------------"<<'\n';     
    fout << "P" << std::setw(16) << "So" << std::setw(16) << "K1" << std::setw(16) << "K2" <<std::setw(16) << "K3" <<std::setw(16) << "K4" << std::endl;
    fout << std::setprecision(15) << std::showpoint;  
    for(int j=0; j<xj.size(); j++)
    {        
    	fout << xj[j] <<" "<< yj[j] <<" "<<k1[j] <<" "<<k2[j] <<" "<< k3[j]<<" "<< k4[j] <<std::endl;
    }
    fout.close();
}
void CRK4::CalcK(){
     k1[i]=dx*(cm->muskequation(xj[i-1],yj[i-1]));
     k2[i]=dx*(cm->muskequation(xj[i-1]+(dx/2), yj[i-1]+(k1[i]/2)));
     k3[i]=dx*(cm->muskequation(xj[i-1]+(dx/2), yj[i-1]+(k2[i]/2)));
     k4[i]=dx*(cm->muskequation(xj[i-1]+dx,yj[i-1]+k3[i]));
}
void CRK4::YJ1(){
     yj[i]=yj[i-1]+(k1[i]+2*k2[i]+2*k3[i]+k4[i])/6;
     int j=cm->pos_pressao(xj[i]);
     double aux=cm->dprod->NP(yj[i],cm->bo[j]);
     double aux2=cm->dprod->GP(cm->bo[j],cm->invbg[j],cm->rs[j],aux);
     cm->Output_NP(aux); cm->Output_GP(aux2);
}     
void CRK4::Solver(){
     std::cout<<"Resolvendo a Equacao Diferencial Ordinaria de Muskat: " << '\n';
     for (int s=0; s<ite; s++)
     {   i++;
         CalcK();
         YJ1();
     }
     std::cout<<"Calculo Terminado!" << '\n';
}
void CRK4::Grafico(){
	std::cout<<"Deseja ver o grafico da saturacao de oleo versus pressao do reservatório? 1-SIM 2-NAO"<<'\n';
	int op; std::cin>>op; std::cin.get();
	if (op==1){
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__)
    Gnuplot::set_GNUPlotPath("C:/PROGRA~1/gnuplot/bin");
    #elif defined(unix) || defined(__unix) || defined(__unix__) || defined(__APPLE__)
    Gnuplot::set_GNUPlotPath("/usr/bin/");
    #endif
	CGnuplot grafico(xj,yj,"Saturacao de oleo contra pressao do reservatorio","linespoints","Pressao","Saturacao de oleo"); 
	std::cout<<"Pressione ENTER para continuar" <<'\n'; std::cin.get();
	std::cout<<"Deseja salvar o grafico? 1-SIM 2-NAO"<<'\n';
	std::cin>>op; std::cin.get();
	if(op==1){
	std::cout<<"Qual o nome desejado para o grafico?"<<'\n';
	std::string nome;
	getline(std::cin, nome);
	std::string salvar="set out \""+nome+".png\"\n";
	grafico << salvar;
	grafico <<"set term png\n";
	grafico.Replot(); std::cout<<"Pressione ENTER para continuar"<<'\n';
	std::cin.get();
	grafico << "exit";}}
}

