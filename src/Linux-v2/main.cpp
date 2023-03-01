#include <iostream>
#include <locale.h>
#include "CInterface.h"
#include "CInterfaceCGGS.h"
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
	cout<<"Simulador de Parametros de Comportamento de Reservatorio"<<endl;
	cout<<"LENEP-UENF - Programacao Pratica"<<'\n';
	cout<<"Professor: Andre Duarte Bueno, Dr."<<'\n';
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"Simulador de Reservatorio de Oleo/Gas com Influxo de Agua (2010)"<<endl;
	cout<<"Autores: Gabriel Clemente Franklin e Carlos Andre Martins de Assis "<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"Simulador de Reservatorio de Oleo com capa de gas ou gas em solucao (2016)"<<endl;
	cout<<"Autor: Thiago Couto de Almeida Chaves"<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"Para comecar, escolha o mecanismo de producao do reservatorio estudado:"<<endl;
	cout<<"1-Reservatorio de Oleo/Gas com Influxo de Agua"<<endl;
	cout<<"2-Reservatorio de Oleo com capa de gas ou gas em solucao"<<endl;
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
	
	cout<<"Deseja iniciar uma nova simulacao com outro tipo de reservatorio? 1-SIM 2-NAO"<<endl;
	int op2; cin>>op2; cin.get();
	if(op2==1){main();}
	return 0;
}
