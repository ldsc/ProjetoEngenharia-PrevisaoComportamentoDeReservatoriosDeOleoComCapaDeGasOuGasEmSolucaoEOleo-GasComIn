#include "CInterfaceCGGS.h"

void CInterfaceCGGS::Instrucoes(){
		cout<<"================================================================================================="<<endl;
		cout<<"Simulador de Previsão de Comportamento de Reservatórios de Óleo com Capa de Gás ou Gás em Solução"<<endl;
		cout<<"Programação Prática 2016.2 / LENEP-UENF"<<endl;
		cout<<"Autor: Thiago Couto de Almeida Chaves"<<endl;
		cout<<"Licença GPL 2.0"<<endl;
		cout<<"================================================================================================="<<endl;
		cout<<endl;
		cout<<"=============================================INSTRUÇÕES DE USO==========================================================="<<endl;
		cout<<"Bem-vindo ao simulador, para utilizá-lo tenha em mãos os dados PVT do fluido de reservatório assim como dados de produção"<<endl;
		cout<<"& reservatório para começar. Você pode inserir tais dados pelo teclado, porém é altamente recomendado que a entrada seja "<<endl;
		cout<<"por arquivo de disco já que para uma simulação adequada muitos dados são requeridos."<<endl;
		cout<<endl;
		cout<<"Para inserir como arquivo de disco, olhe o modelo exemplo que segue com esse programa e somente EDITE os dados ali"<<endl;
		cout<<"demonstrados. Caso altere o formato do arquivo, terás que alterar o código também. Após editar os dados que queres, salve"<<endl;
		cout<<"o arquivo no mesmo diretório do programa. No programa, digite o nome do arquivo e extensão para começar a simulação."<<endl;
		cout<<endl;
		cout<<"Todos os dados, para resultar em uma simulação real e de proveito, precisarão estar no sistema PETROBRAS de unidades"<<endl;
		cout<<"========================================================================================================================="<<endl;
		cout<<endl;
	}
	void CInterfaceCGGS::SalvarSim(){
		cout<<"Deseja salvar a simulação? 1-SIM 2-NÃO"<<endl;
		int op;
		cin>>op; cin.get();
		if(op==1){
			cout<<"Qual o nome de arquivo que desejas salvar?"<<endl;
			string s;
			getline(cin,s);
			s=s+".txt";
			ofstream fout(s.c_str());
			cout<<"Cheguei aq"<<endl;
			cdp->SaidaDisco(fout);
			mskt->SaidaDisco(fout);
			rk4->SaidaDisco(fout);
		}
	};
	void CInterfaceCGGS::Grafico(){
		mskt->Grafico();
		cout<<"Mostrando agora o gráfico da Saturação de Óleo versus Pressão"<<'\n';
		rk4->Grafico();
	}
	void CInterfaceCGGS::Resultados(){
		cout<<"Deseja ver a saída completa ou resumida dos dadosx?"<<endl;
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
		cout<<"Sequência de cálculo terminada!"<<endl;
	}
	void CInterfaceCGGS::EntradaManual(){
		cout<<"Entrada Manual selecionada!"<<endl;
		cdp= new CDataProd;
		mskt= new CMuskat(*cdp);
		mskt->Entrada();
		rk4= new CRK4(*mskt);
	}
	void CInterfaceCGGS::EntradaDisco(){
		string nome;
		cout<<"Entrada por Disco selecionada!"<<endl;
		cout<<"Qual nome do arquivo + extensão (i.e. arq.txt ou arq.dat)?"<<'\n';
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
		cout<<"Como se dará a entrada de dados? Digite 1-Manual por Teclado / 2-Arquivo de Disco"<<endl;
		cin>>op; cin.get();
		if (op==1){
			EntradaManual();
		}
		if(op==2){
			EntradaDisco();
		}
		if(op!=1 && op!=2)
		{
			cout<<"Erro! Tipo de Entrada não encontrado";
			exit(0);
		}
	}
	void CInterfaceCGGS::Run(){
		Instrucoes(); Inicio(); Solver(); Resultados(); Grafico(); SalvarSim();
	}
