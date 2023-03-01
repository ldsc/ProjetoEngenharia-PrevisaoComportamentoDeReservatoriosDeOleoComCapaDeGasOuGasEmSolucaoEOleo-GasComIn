#include "CSimuladorCGGS.h"

//----------------------------CSimuladorCGGS---------------------------------------
void CSimuladorCGGS::SalvaGraf(CGnuplot& graf){
	std::cout<<"Deseja salvar o grafico? 1-SIM 2-NAO"<<'\n';
	int op;
	std::cin>>op; std::cin.get();
	if(op==1){
	std::cout<<"Qual o nome desejado para o grafico?"<<'\n';
	std::string nome;
	getline(std::cin, nome);
	std::string salvar="set out \""+nome+".png\"\n";
	graf << salvar;
	graf <<"set term png\n";
	graf.Replot(); std::cout<<"Pressione ENTER para continuar"<<'\n';
	std::cin.get();}
}
void CSimuladorCGGS::Grafico_Sim(){   
    int opc,opcx;
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__)
    Gnuplot::set_GNUPlotPath("C:/PROGRA~1/gnuplot/bin");
    #elif defined(unix) || defined(__unix) || defined(__unix__) || defined(__APPLE__)
    Gnuplot::set_GNUPlotPath("/usr/bin/");
    #endif
    std::cout<<"Qual grafico das propriedades dos fluidos de reservatório desejas plotar?" <<'\n';
    std::cout<<"1- Bo contra P" <<'\n';
    std::cout<<"2- Rs contra P" <<'\n';
    std::cout<<"3- Inverso de Bg contra P" <<'\n';
    std::cout<<"4- Curva de Permeabilidade Kg contra Ko" <<'\n';
    std::cout<<"5- Nenhum"<<'\n';
    std::cin>>opc; std::cin.get(); std::cout<<"Pressione ENTER para continuar"<<'\n'; std::cin.get();
    
    	if(opc==1){
    	CGnuplot grafico(p,bo,"Bo contra P","linespoints","Pressão","Fator Volume-Formação do Óleo"); SalvaGraf(grafico); std::cin.get();}
        if(opc==2){
		CGnuplot grafico(p,rs,"Rs contra P","linespoints","Pressão","Razão de solubilidade");SalvaGraf(grafico); std::cin.get();}
    	if(opc==3){
    	CGnuplot grafico(p,bo,"1/Bg contra P","linespoints","Pressão","Inverso do Fator Volume-Formação do Gás"); SalvaGraf(grafico); std::cin.get();}
    	if(opc==4){
        CGnuplot grafico(ko,kg,"Kg contra Ko","linespoints","Ko","Kg"); SalvaGraf(grafico); std::cin.get();} 
    if(opc<=4 && opc>0){
    std::cout<<"Deseja ver outro gráfico dentre os quatro aqui apresentados? 1-SIM 2-NAO"<<'\n';
    std::cin>>opcx; std::cin.get();
    if (opcx==1){CSimuladorCGGS::Grafico_Sim();}}
}
void CSimuladorCGGS::Resultados(std::ostream& os){
	os<<"A seguir os dados da simulacao:"<<'\n';
	os<<"-------------------------------------------------------------------------------------------------"<<'\n';      
os << "Pressao" << std::setw(12) << "Bo" << std::setw(12) << "dBo/dP" << std::setw(12) << "1/Bg" <<std::setw(12) << "d(1/Bg)/dP" <<std::setw(12) << "Rs" <<std::setw(12) << "dRs/dP" <<std::setw(12) << "uo/ug" <<std::endl;
os << "kgf/cm^2" << std::setw(12) << "m^3/m^3 std" << std::setw(12) << "1/kgf/cm^2" << std::setw(12) << "m^3std/m" <<std::setw(12) << "1/kgf/cm^2" <<std::setw(12) << "m^3std/m^3std" <<std::setw(12) << "1/kgf/cm^2" <<std::setw(12) << "cp/cp" <<std::endl;  
   for(int j=0; j<p.size(); j++)
   {        
   os <<std::showpoint<<std::setprecision(7)<< p[j] <<std::setw(12)<<std::setprecision(7)<< bo[j] <<std::setw(12)<<std::setprecision(7)<<dbodp[j] <<std::setw(12)<<std::setprecision(7)<<invbg[j] <<std::setw(12)<<std::setprecision(7)<<dinvbgdp[j]<<std::setw(12)<<std::setprecision(7)<<rs[j]<<std::setw(12)<<std::setprecision(7)<<drsdp[j]<<std::setw(12)<<std::setprecision(7)<<mio_mig[j]<<std::setw(12)<<std::setprecision(7)<<std::endl;
   } //chamar Saída Tabela de CMuskat e CRunge
} //tabela resultados
void CSimuladorCGGS::SaidaDisco(std::ofstream& fout){
	fout<<"A seguir os dados da simulacao:"<<'\n';
	fout<<"-------------------------------------------------------------------------------------------------"<<'\n';
	fout << "Pressao" << std::setw(12) << "Bo" << std::setw(12) << "dBo/dP" << std::setw(12) << "1/Bg" <<std::setw(12) << "d(1/Bg)/dP" <<std::setw(12) << "Rs" <<std::setw(12) << "dRs/dP" <<std::setw(12) << "uo/ug" <<std::endl;
    fout << "kgf/cm^2" << std::setw(12) << "m^3/m^3 std" << std::setw(12) << "1/kgf/cm^2" << std::setw(12) << "m^3std/m" <<std::setw(12) << "1/kgf/cm^2" <<std::setw(12) << "m^3std/m^3std" <<std::setw(12) << "1/kgf/cm^2" <<std::setw(12) << "cp/cp" <<std::endl;  
    for(int j=0; j<p.size(); j++)
    {        
     fout<<std::showpoint<<std::setprecision(7)<< p[j] <<std::setw(12)<<std::setprecision(7)<< bo[j] <<std::setw(12)<<std::setprecision(7)<<dbodp[j] <<std::setw(12)<<std::setprecision(7)<<invbg[j] <<std::setw(12)<<std::setprecision(7)<<dinvbgdp[j]<<std::setw(12)<<std::setprecision(7)<<rs[j]<<std::setw(12)<<std::setprecision(7)<<drsdp[j]<<std::setw(12)<<std::setprecision(7)<<mio_mig[j]<<std::setw(12)<<std::setprecision(7)<<std::endl;
    }			
}
void CSimuladorCGGS::P(){      
       double pressure;
       std::cout <<"Entre com os dados da pressoes medidas de reservatorio! Digite um valor menor que 0 para sair do loop (visto que não há pressões negativas no reservatório)"<<'\n';
       do{
         std::cout <<"Digite a pressao em kgf/cm^2"<<'\n';
         std::cin>>pressure; std::cin.get(); 
         p.push_back(pressure);
	   }while(pressure>0); 
       std::cout <<"Entrada terminada!" <<'\n'; 
       p.pop_back();
       var_ctrl=p.size(); //recebe tamanho do vetor para definir a variável de controle de cálculo
       MostraVetor(p);
}
void CSimuladorCGGS::BO(){
       double bo_aux; 
       std::cout <<"Entre com os valores de Bo referentes a cada pressao preenchida por voce anteriormente neste programa." <<'\n';
       for(int i=0;i<var_ctrl;i++){
          std::cout << "Digite o valor de Bo para a pressao de "<< p[i]<<" kgf/cm^2"<< '\n';
          std::cin>>bo_aux; std::cin.get();
          bo.push_back(bo_aux);
        }   
       //incluir depois condição para invalidar entrada se o tamanho de bo passar do tamanho de P
        std::cout <<"Entrada terminada BO()!" <<'\n';
        MostraVetor(bo);
}     
void CSimuladorCGGS::DBODP(){      
  double varaux; dbodp.resize(var_ctrl);
  // if bo.size() < 4 and pressao.size() < 4, do something else.
  for(int i=0;i<var_ctrl-2;i++){dbodp[i+1]=(bo[i]-bo[i+2])/(p[i]-p[i+2]);}
  double diff=dbodp[1]-dbodp[2]; 
  varaux=var_ctrl-1;
  dbodp[0]=dbodp[1]+diff;
  dbodp[varaux]=dbodp[varaux-1]-diff;   
  std::cout <<"Entrada terminada DBODP()!" <<'\n';
  MostraVetor(dbodp);   
}
void CSimuladorCGGS::INVBG(){
       double bg_aux, invbgaux; int i=0;
       std::cout <<"Entre com os valores de Bg referentes a cada pressao preenchida por voce anteriormente neste programa." <<'\n';
       for(int i=0;i<var_ctrl;i++){
          std::cout << "Digite o valor de Bg para a pressao de "<< p[i]<<" kgf/cm^2"<< '\n';
          std::cin >>bg_aux; std::cin.get(); 
          bg.push_back(bg_aux);
          invbgaux=1/bg_aux;
          invbg.push_back(invbgaux);
          i++;
        }    
        std::cout <<"Entrada terminada! INVBG()" <<'\n';
        MostraVetor(invbg);
       }      
void CSimuladorCGGS::DINVBGDP(){
       double varaux; dinvbgdp.resize(var_ctrl);     
  // if invbg.size() < 4 and pressao.size() < 4, do something else.
     for(int i=0;i<var_ctrl-2;i++){dinvbgdp[i+1]=(invbg[i]-invbg[i+2])/(p[i]-p[i+2]);}
     double diff=dinvbgdp[1]-dinvbgdp[2]; 
     varaux=var_ctrl-1;
     dinvbgdp[0]=dinvbgdp[1]+diff;
     dinvbgdp[varaux]=dinvbgdp[varaux-1]-diff;
	 std::cout <<"Entrada terminada DINVBGDP()!" <<'\n';
  	 MostraVetor(dinvbgdp);     
}
void CSimuladorCGGS::RS(){
       double rs_aux; int i=0;
       std::cout <<"Entre com os valores de Rs referentes a cada pressao preenchida por voce anteriormente neste programa." <<'\n';
       for(int i=0;i<var_ctrl;i++){
          std::cout << "Digite o valor de Rs para a pressao de "<< p[i]<<" kgf/cm^2"<< '\n';
          std::cin >>rs_aux; std::cin.get();
          rs.push_back(rs_aux);
        } 
       //incluir depois condição para invalidar entrada se o tamanho de rs passar do tamanho de P
        std::cout <<"Entrada terminada! RS()" <<'\n';
        MostraVetor(rs);
       }
void CSimuladorCGGS::DRSDP(){
       double varaux; drsdp.resize(var_ctrl);    
  // if invbg.size() < 4 and pressao.size() < 4, do something else.
     for(int i=0;i<var_ctrl-2;i++){drsdp[i+1]=(rs[i]-rs[i+2])/(p[i]-p[i+2]);}
     double diff=drsdp[1]-drsdp[2]; 
     varaux=var_ctrl-1;
     drsdp[0]=drsdp[1]+diff;
     drsdp[varaux]=drsdp[varaux-1]-diff;
	 
	 std::cout <<"Entrada terminada DRSDP()!" <<'\n';
  	 MostraVetor(drsdp);    
}
void CSimuladorCGGS::MIO_MIG(){
       std::cout<<"Insira os valores das viscosidades do oleo em cp" <<'\n';
       double miaux;
       for(int i=0;i<var_ctrl;i++){
              std::cout << "Digite o valor de Mio para a pressao de "<< p[i]<<" kgf/cm^2"<< '\n';
              std::cin>>miaux; std::cin.get();
              mio.push_back(miaux);
       }
       
       std::cout<<"Insira os valores das viscosidades do gas em cp" <<'\n';
       for(int j=0;j<var_ctrl;j++){
              std::cout << "Digite o valor de Mig para a pressao de "<< p[j]<<" kgf/cm^2"<< '\n';
              std::cin>>miaux; std::cin.get();
              mig.push_back(miaux);   
       }
       mio_mig.resize(var_ctrl);
       std::cout<<"Vetor mio: "; MostraVetor(mio); std::cout<<'\n';
       std::cout<<"Vetor mig: "; MostraVetor(mig); std::cout<<'\n'; 
       std::transform(mio.begin(),mio.end(),mig.begin(),mio_mig.begin(),std::divides<double>());
       std::cout<<"Vetor mio_mig: "; MostraVetor(mio_mig); std::cout<<'\n';
}       
void CSimuladorCGGS::KG_KO(){
       std::cout<<"Insira os valores das permeabilidades do oleo em cp" <<'\n';
       double koaux;
       for(int i=0;i<var_ctrl;i++){
              std::cout << "Digite o valor de Ko para a pressao de "<< p[i]<<" kgf/cm^2"<< '\n';
              std::cin>>koaux; std::cin.get();
              ko.push_back(koaux);
       }
       std::cout<<"Insira os valores das permeabilidades do gas em cp" <<'\n';
       double kgaux;
       for(int j=0;j<var_ctrl;j++){
              std::cout << "Digite o valor de Kg para a pressao de "<< p[j]<<" kgf/cm^2"<< '\n';
              std::cin>>kgaux; std::cin.get();
              kg.push_back(kgaux);
       }
       kg_ko.resize(var_ctrl);
       std::cout<<"Vetor kg: "; MostraVetor(ko); std::cout<<'\n';
       std::cout<<"Vetor ko: "; MostraVetor(kg); std::cout<<'\n'; 
       std::transform(kg.begin(),kg.end(),ko.begin(),kg_ko.begin(),std::divides<double>());
       std::cout<<"Vetor kg_ko: "; MostraVetor(kg_ko); std::cout<<'\n';
}
void CSimuladorCGGS::MostraVetor(std::vector<double> v1){
	
	std::ostream_iterator<double> output(std::cout," ");
	copy(v1.begin(),v1.end(),output);
	std::cout<<'\n';
}
std::ifstream& operator>>(std::ifstream& fin, CSimuladorCGGS& obj){
	double auxvar=0;
	fin.ignore(5000,'\n');
	fin.ignore(5000,'\n');
	fin>>obj.var_ctrl;
	fin.ignore(5000,'\n');
	fin.ignore(5000,'\n');
	for (int i=0;i<obj.var_ctrl; i++){
		fin>>auxvar;
		obj.p.push_back(auxvar);
	}
	fin.ignore(5000,'\n');
	fin.ignore(5000,'\n');
	for (int i=0;i<obj.var_ctrl; i++){
		fin>>auxvar;
		obj.bo.push_back(auxvar);
	}
	fin.ignore(5000,'\n');
	fin.ignore(5000,'\n');
	for (int i=0;i<obj.var_ctrl; i++){
		fin>>auxvar;
		obj.invbg.push_back(auxvar);
	}
	fin.ignore(5000,'\n');
	fin.ignore(5000,'\n');
	for (int i=0;i<obj.var_ctrl; i++){
		fin>>auxvar;
		obj.rs.push_back(auxvar);
	}
	fin.ignore(5000,'\n');
	fin.ignore(5000,'\n');
	for (int i=0;i<obj.var_ctrl; i++){
		fin>>auxvar;
		obj.mio_mig.push_back(auxvar);
	}
	fin.ignore(5000,'\n');
	fin.ignore(5000,'\n');
	for (int i=0;i<obj.var_ctrl; i++){
		fin>>auxvar;
		obj.dbodp.push_back(auxvar);
	}
	fin.ignore(5000,'\n');
	fin.ignore(5000,'\n');
	for (int i=0;i<obj.var_ctrl; i++){
		fin>>auxvar;
		obj.dinvbgdp.push_back(auxvar);
	}
	fin.ignore(5000,'\n');
	fin.ignore(5000,'\n');
	for (int i=0;i<obj.var_ctrl; i++){
		fin>>auxvar;
		obj.drsdp.push_back(auxvar);
	}
	fin.close();
	std::cout<<"Leitura terminada!"<<'\n';
	return fin;
}
std::ostream& operator<<(std::ostream& out, CSimuladorCGGS& obj){
	std::cout<<"Vamos mostrar os vetores ate agora:"<<'\n';
    std::cout<<"Vetor Pressao:"<<'\n';
    obj.MostraVetor(obj.p);
	std::cout<<"Vetor Bo:"<<'\n';
	obj.MostraVetor(obj.bo);
	std::cout<<"Vetor 1/Bg:"<<'\n';
	obj.MostraVetor(obj.invbg);
	std::cout<<"Vetor Rs:"<<'\n';
	obj.MostraVetor(obj.rs);
	std::cout<<"Vetor Mio_Mig:"<<'\n';
	obj.MostraVetor(obj.mio_mig);
	std::cout<<"Vetor dBo/dP:"<<'\n';
	obj.MostraVetor(obj.dbodp);
	std::cout<<"Vetor dInvBg/dP:"<<'\n';
	obj.MostraVetor(obj.dinvbgdp);
	std::cout<<"Vetor dRs/dP:"<<'\n';
	obj.MostraVetor(obj.drsdp);
	return out;
}
double CSimuladorCGGS::GetBo(double pressao){
	int i=pos_pressao(pressao);
	return bo[i];
}
