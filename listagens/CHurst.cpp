/* Previsão do Compartamento de Reservatórios
   de Gás e de Óleo com Influxo de Água
   
   @Autores: Carlos André Martins de Assis e Gabriel Clemente Franklin
   @file CHurst.cpp
*/

#include "CHurst.h"
#include "CGnuplot.h"

void CHurst::Constantes()
{
     if(geom==1)  //Caso Radial
     {
                U=ra.Poro()*ra.Ct()*ra.H()*2*3.1416*rr.g->R()*rr.g->R();
     }
     else  //Caso Linear
     {
         U=ra.Poro()*ra.Ct()*ra.H()*ra.g->W()*ra.g->L();
     }
     Tempo();
}

double CHurst::InfluxoWd(double t)
{  
      CStehfest ob;
      if(geom==1) //Caso Radial
      {
               
       switch(op)
       {
        case 1:
                return ob.Inversao(CLaplaceWd::RadInf,t); break;
        case 2:
                return ob.Inversao(CLaplaceWd::RadRea,ra.g->R(),rr.g->R(),t); break;
        case 3:
             
                return ob.Inversao(CLaplaceWd::RadSel,ra.g->R(),rr.g->R(),t); break;
                
        default:                                         //CASO PADRAO!!!!
                
                return ob.Inversao(CLaplaceWd::RadInf,t);  break;
        }
       }
       else //Caso Linear
       {
        switch(op)
        {
        case 1:
                return CLaplaceWd::LinInf(t); break;
        case 2:
                return ob.Inversao(CLaplaceWd::LinRea,t); break;
        case 3:
                return ob.Inversao(CLaplaceWd::LinSel,t); break;
        default:                                         //CASO PADRAO!!!!
                return CLaplaceWd::LinInf(t); break;
        }
       }
}

void CHurst::Tempo()
{   
     CSimulador::Tempo();
     double r2; //Constante que depende da geometria
     if(geom==1)
     {
                r2=rr.g->R()*rr.g->R();
     }
     else
     {
         r2=ra.g->L()*ra.g->L();
     }
     td[0]=0.;
     double a=0.008362;
         for (int i=1;i<=n;i++)
     {
         td[i]=(ra.K()*dt*a*i)/(ra.Poro()*ra.U()*ra.Ct()*r2);
        
         }
     
     }

void CHurst::SolverGas()
{
    Constantes();
    P[0]=rr.Pi();
    double zi=fluido->BrillZ(P[0]);
    double soma=0.;
    double z=zi;
    vector<double> dp(n);

    Wen[0]=0.; //lebrando que P[0]=pi

    double pk=0.; // Pn da iteração anterior para comparacao

   //Inicio da Primeira iteração

    P[1]=P[0]*z*(1-(rr.Q()*dt)/fluido->V())/(zi*(1-U*soma/(fluido->V()*fluido->B(P[0]))));
    do
   {
    //passo 3)
    soma=((P[0]-P[1])/2)*InfluxoWd(td[1]);
    Wen[1]=U*soma;
    z=fluido->BrillZ(P[1]);
    pk=P[1];
    P[1]=P[0]*z*(1-((rr.Q()*dt)/fluido->V()))/(zi*(1-Wen[1]/(fluido->V()*fluido->B(P[0])))); //CHECAR!
    dp[0] =(P[0]-P[1])/2;
     }while(fabs(P[1]-pk)>0.001);
   for (int i=2;i<=n;i++)
   {
       soma=0.;
       for (int j=0;j<=i-2;j++)
       {
        soma+=dp[j]*InfluxoWd(td[i]-td[j]);
       }
   //Passo 2)
   z=fluido->BrillZ(P[i-1]);
   P[i]=P[0]*z*(1-(rr.Q()*dt*i)/fluido->V())/(zi*(1-U*soma/(fluido->V()*fluido->B(P[i-1]))));

   //PASSO 3)
     do
     {
        z=fluido->BrillZ(P[i]);

        Wen[i]=U*soma+U*(P[i-2]-P[i])*InfluxoWd(td[i]-td[i-1])/2;
        pk=P[i];
        P[i]=P[0]*z*(1-(rr.Q()*dt*i)/fluido->V())/(zi*(1-Wen[i]/(fluido->V()*fluido->B(P[i]))));


        dp[i-1]=(P[i-2]-P[i])/2;

    }while (fabs(P[i]-pk)>0.001);
  }
}

void CHurst::SolverOleo()
{
    Constantes();
    op=1;//O metodo simplificado de Hurst só funciona para aquifero infinito e subsaturado (Fetkovich tambem)
    vector<double> dp(n);
    P[0]=rr.Pi();
    P[1]=(P[0]*(U*InfluxoWd(td[1])+fluido->V()*fluido->B()*fluido->Ceo())-rr.Q()*t[1]*fluido->B())
            /(fluido->V()*fluido->B()*fluido->Ceo()+U*InfluxoWd(td[1])); //Equacao explicita
    Wen[1]=rr.Q()*t[1]*fluido->B()-fluido->V()*fluido->B()*fluido->Ceo()*(P[0]-P[1]);
    dp[0] =(P[0]-P[1])/2;

    for(int i=2;i<=n;i++)
    {
            double soma=0.;
            for (int j=0;j<=i-2;j++)
            {
             soma+=U*dp[j]*InfluxoWd(td[i]-td[j]);
            }
            P[i]=(soma+U*P[i-2]*InfluxoWd(td[i]-td[i-1])/2+fluido->V()*fluido->B()*fluido->Ceo()*P[0]-rr.Q()*t[i]*fluido->B())
            /(fluido->V()*fluido->B()*fluido->Ceo()+U*InfluxoWd(td[i]-td[i-1])/2);
            Wen[i]=rr.Q()*t[i]*fluido->B()-fluido->V()*fluido->B()*fluido->Ceo()*(P[0]-P[i]);
            dp[i-1]=(P[i-2]-P[i])/2;
    }
}


