#ifndef CInterfaceCGGS_h
#define CInterfaceCGGS_h

#include <iostream>
#include "CSimuladorCGGS.h"
#include<cstdlib> 
#include<fstream>
#include<functional> 
#include<algorithm> 
#include<vector> 
#include<string> 
#include<iterator>
#include "CGnuplot.h" 
#include<locale.h>
#include<utility>
#include<cmath>
#include<iomanip>
#include "CDataProd.h"
#include "CMuskat.h"
#include "CRK4.h"

using namespace std;

class CInterfaceCGGS
{
	protected:
	CDataProd* cdp;
	CMuskat* mskt;
	CRK4* rk4;
	public:
	CInterfaceCGGS(){Run();}
	void Instrucoes();
	void SalvarSim();
	void Grafico();
	void Resultados();
	void Solver();
	void EntradaManual();
	void EntradaDisco();
	void Inicio();
	void Run();
};
#endif
