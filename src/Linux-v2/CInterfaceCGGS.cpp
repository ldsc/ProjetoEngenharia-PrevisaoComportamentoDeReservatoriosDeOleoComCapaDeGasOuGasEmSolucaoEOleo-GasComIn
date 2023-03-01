#include "CInterfaceCGGS.h"

void CInterfaceCGGS::Instrucoes(){
		cout<<"================================================================================================="<<endl;
		cout<<"Simulador de Previsao de Comportamento de Reservatórios de Oleo com Capa de Gas ou Gas em Solucao"<<endl;
		cout<<"Programação Pratica 2016.2 / LENEP-UENF"<<endl;
		cout<<"Autor: Thiago Couto de Almeida Chaves"<<endl;
		cout<<"Licença GPL 2.0"<<endl;
		cout<<"================================================================================================="<<endl;
		cout<<endl;
		cout<<"=============================================INSTRUCOES DE USO==========================================================="<<endl;
		cout<<"Bem-vindo ao simulador, para utiliza-lo tenha em maos os dados PVT do fluido de reservatorio assim como dados de producao"<<endl;
		cout<<"& reservatorio para comecar. Você pode inserir tais dados pelo teclado, porem e altamente recomendado que a entrada seja "<<endl;
		cout<<"por arquivo de disco ja que para uma simulacao adequada muitos dados sao requeridos."<<endl;
		cout<<endl;
		cout<<"Para inserir como arquivo de disco, olhe o modelo exemplo que segue com esse programa e somente EDITE os dados ali"<<endl;
		cout<<"demonstrados. Caso altere o formato do arquivo, teras que alterar o codigo tambem. Apos editar os dados que queres, salve"<<endl;
		cout<<"o arquivo no mesmo diretorio do programa. No programa, digite o nome do arquivo e extensao para comecar a simulacao."<<endl;
		cout<<endl;
		cout<<"Todos os dados, para resultar em uma simulacao real e de proveito, precisarao estar no sistema PETROBRAS de unidades"<<endl;
		cout<<"========================================================================================================================="<<endl;
		cout<<endl;
	}
	void CInterfaceCGGS::SalvarSim(){
		cout<<"Deseja salvar a simulacao? 1-SIM 2-NAO"<<endl;
		int op;
		cin>>op; cin.get();
		if(op==1){
			cout<<"Qual o nome de arquivo que desejas salvar?"<<endl;
			string s;
			getline(cin,s);
			s=s+".txt";
			ofstream fout(s.c_str());
			cdp->SaidaDisco(fout);
			mskt->SaidaDisco(fout);
			rk4->SaidaDisco(fout);
		}
	};
	void CInterfaceCGGS::Grafico(){
		mskt->Grafico();
		rk4->Grafico();
	}
	void CInterfaceCGGS::Resultados(){
		cout<<"Deseja ver a saida completa ou resumida dos dados? 1-Completa 2-Resumida"<<endl;
		int op; cin>>op; cin.get();
		if (op==1){
		mskt->Saida(cout);
		rk4->Saida(cout,cin);
		}
		if (op==2){
			mskt->SaidaResumida();
		}
	};
	void CInterfaceCGGS::Solver(){
		rk4->Solver();
		cout<<"Sequencia de calculo terminada!"<<endl;
	}
	void CInterfaceCGGS::EntradaManual(){
		cout<<"Entrada manual selecionada!"<<endl;
		cdp= new CDataProd;
		mskt= new CMuskat(*cdp);
		mskt->Entrada();
		rk4= new CRK4(*mskt);
	}
	void CInterfaceCGGS::EntradaDisco(){
		string nome;
		cout<<"Entrada por disco selecionada!"<<endl;
		cout<<"Qual nome do arquivo + extensao (i.e. arq.txt ou arq.dat)?"<<'\n';
		getline(cin,nome);
    	//CDataProd dados(nome);
    	cdp= new CDataProd(nome);
		//CMuskat obj(nome,dados);
		mskt= new CMuskat(nome,*cdp);
		//CRK4 eq(obj);
		rk4= new CRK4(*mskt);
	}
	void CInterfaceCGGS::Inicio(){
		int op;
		cout<<"Como se dara a entrada de dados? Digite 1-Manual por Teclado / 2-Arquivo de Disco"<<endl;
		cin>>op; cin.get();
		if (op==1){
			EntradaManual();
		}
		if(op==2){
			EntradaDisco();
		}
		if(op!=1 && op!=2)
		{
			cout<<"Erro! Tipo de Entrada nao encontrado";
			exit(0);
		}
	}
	void CInterfaceCGGS::Run(){
		Instrucoes(); Inicio(); Solver(); Resultados(); Grafico(); SalvarSim();
	}
