#include <iostream>
#include "CInterfaceCGGS.cpp"
#include "CInterface.h"
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
int main() {
	setlocale(LC_ALL,"");
	int p=1;
	system("color 0F"); 
	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__)
	system("cls");
	#elif defined(unix) || defined(__unix) || defined(__unix__) || defined(__APPLE__)
	system("clear");
	#endif
	cout<<"Simulador de Parâmetros de Comportamento de Reservatório"<<endl;
	cout<<"LENEP-UENF - Programação Prática"<<'\n';
	cout<<"Professor: André Duarte Bueno, Dr."<<'\n';
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"Simulador de Reservatório de Óleo/Gás com Influxo de Água (2010)"<<endl;
	cout<<"Autores: Gabriel Clemente Franklin e Carlos Andre Martins de Assis "<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"Simulador de Reservatório de Óleo com capa de gás ou gás em solução (2016)"<<endl;
	cout<<"Autor: Thiago Couto de Almeida Chaves"<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"Para começar, escolha o mecanismo de produção do reservatório estudado:"<<endl;
	cout<<"1-Reservatório de Óleo/Gás com Influxo de Água"<<endl;
	cout<<"2-Reservatório de Óleo com capa de gás ou gás em solução"<<endl;
	int op; cin>>op; cin.get();
	
	CInterface *intface=NULL; 
	CInterfaceCGGS *intface_cggs=NULL;
	
	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__)
	system("cls");
	#elif defined(unix) || defined(__unix) || defined(__unix__) || defined(__APPLE__)
	system("clear");
	#endif
	
	if (op==1){
		while(p!=0)
		{
		#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__)
		system("color 17");
		#elif defined(unix) || defined(__unix) || defined(__unix__) || defined(__APPLE__)
		system("setterm -background blue -foreground white -store");
		#endif
		intface= new CInterface;
		system("cls");
        cout<<"\n\tDeseja iniciar uma nova simulacao?(0-nao):"<<endl;
        cin>>p; cin.get();
        delete intface;
        intface=NULL;
		}
				
	}
	
	if(op==2){
		while(p!=0)
		{
		#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__)
		system("color F0");
		#elif defined(unix) || defined(__unix) || defined(__unix__) || defined(__APPLE__)
		system("setterm -background white -foreground black -store");
		#endif
		intface_cggs= new CInterfaceCGGS;
			#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__)
			system("cls");
			#elif defined(unix) || defined(__unix) || defined(__unix__) || defined(__APPLE__)
			system("clear");
			#endif
        cout<<"\n\tDeseja iniciar uma nova simulacao?(0-nao):"<<endl;
        cin>>p; cin.get();
        delete intface_cggs;
        intface_cggs=NULL;
		}			
	}
	
	cout<<"Deseja iniciar uma nova simulação com outro tipo de reservatório? 1-SIM 2-NAO"<<endl;
	int op2; cin>>op2; cin.get();
	if(op2==1){main();}
	return 0;
}
