#include "CInterfaceCGGS.h"

void CInterfaceCGGS::Instrucoes(){
		cout<<"================================================================================================="<<endl;
		cout<<"Simulador de Previs�o de Comportamento de Reservat�rios de �leo com Capa de G�s ou G�s em Solu��o"<<endl;
		cout<<"Programa��o Pr�tica 2016.2 / LENEP-UENF"<<endl;
		cout<<"Autor: Thiago Couto de Almeida Chaves"<<endl;
		cout<<"Licen�a GPL 2.0"<<endl;
		cout<<"================================================================================================="<<endl;
		cout<<endl;
		cout<<"=============================================INSTRU��ES DE USO==========================================================="<<endl;
		cout<<"Bem-vindo ao simulador, para utiliz�-lo tenha em m�os os dados PVT do fluido de reservat�rio assim como dados de produ��o"<<endl;
		cout<<"& reservat�rio para come�ar. Voc� pode inserir tais dados pelo teclado, por�m � altamente recomendado que a entrada seja "<<endl;
		cout<<"por arquivo de disco j� que para uma simula��o adequada muitos dados s�o requeridos."<<endl;
		cout<<endl;
		cout<<"Para inserir como arquivo de disco, olhe o modelo exemplo que segue com esse programa e somente EDITE os dados ali"<<endl;
		cout<<"demonstrados. Caso altere o formato do arquivo, ter�s que alterar o c�digo tamb�m. Ap�s editar os dados que queres, salve"<<endl;
		cout<<"o arquivo no mesmo diret�rio do programa. No programa, digite o nome do arquivo e extens�o para come�ar a simula��o."<<endl;
		cout<<endl;
		cout<<"Todos os dados, para resultar em uma simula��o real e de proveito, precisar�o estar no sistema PETROBRAS de unidades"<<endl;
		cout<<"========================================================================================================================="<<endl;
		cout<<endl;
	}
	void CInterfaceCGGS::SalvarSim(){
		cout<<"Deseja salvar a simula��o? 1-SIM 2-N�O"<<endl;
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
		cout<<"Mostrando agora o gr�fico da Satura��o de �leo versus Press�o"<<'\n';
		rk4->Grafico();
	}
	void CInterfaceCGGS::Resultados(){
		cout<<"Deseja ver a sa�da completa ou resumida dos dadosx?"<<endl;
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
		cout<<"Sequ�ncia de c�lculo terminada!"<<endl;
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
		cout<<"Qual nome do arquivo + extens�o (i.e. arq.txt ou arq.dat)?"<<'\n';
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
		cout<<"Como se dar� a entrada de dados? Digite 1-Manual por Teclado / 2-Arquivo de Disco"<<endl;
		cin>>op; cin.get();
		if (op==1){
			EntradaManual();
		}
		if(op==2){
			EntradaDisco();
		}
		if(op!=1 && op!=2)
		{
			cout<<"Erro! Tipo de Entrada n�o encontrado";
			exit(0);
		}
	}
	void CInterfaceCGGS::Run(){
		Instrucoes(); Inicio(); Solver(); Resultados(); Grafico(); SalvarSim();
	}
