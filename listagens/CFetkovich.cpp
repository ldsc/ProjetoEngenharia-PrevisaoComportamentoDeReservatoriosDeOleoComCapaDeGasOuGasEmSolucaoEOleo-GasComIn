/* Previsão do Compartamento de Reservatórios
   de Gás e de Óleo com Influxo de Água
   
   @Autores: Carlos André Martins de Assis e Gabriel Clemente Franklin
   @file CFetkovich.cpp
*/
#include "CFetkovich.h"
#include "CGnuplot.h"

void CFetkovich::Constantes()
{
     if(geom==1) //Caso Radial
     {
                J=0.05255*ra.K()*ra.H()/(ra.U()*(log(ra.g->R()/rr.g->R())-0.75));  
                Wei=3.1416*(ra.g->R()*ra.g->R()-rr.g->R()*rr.g->R())*ra.Poro()*ra.H()*ra.Ct()*rr.Pi();
     }
     else       //Caso Linear
     {
         //J=0.30662*ra.K()*ra.H()*ra.g->W()/(ra.U()*ra.g->L()); NAO ENTENDI
         J = (ra.K()*ra.H()*ra.g->W())/(39.85*ra.U()*rr.g->L());
         Wei=ra.g->L()*ra.g->W()*ra.Poro()*ra.H()*ra.Ct()*rr.Pi();
     }
     Tempo();
}

double CFetkovich::EqSeg(double a,double b,double c)
{
     double x1=(b+sqrt(b*b-4*a*c))/(a*(-2)); //Formulas de Bhaskara
     double x2=(sqrt(b*b-4*a*c)-b)/(2*a);
    if((x1>0)&&(x1<rr.Pi())) //Uma das raizes esta entre 0 e a Pressao Inicial, a outra esta fora deste intervalo
    {
                      return x1;
    }
    else
    {
        return x2;
    }
}


void CFetkovich::SolverGas()
{
     Constantes();
     vector<double> pm(n+1,0.0); //pressão média no aquifero
   double D=Wei*(1-exp((-1)*J*rr.Pi()*dt/Wei))/rr.Pi(); //Constante simplificadora
   P[0]=pm[0]=rr.Pi();
   double zi=fluido->BrillZ(P[0]);
   //primeira iteracao
   double z=zi;
   //Define-se os coeficientes da Equacao do Segundo Grau
   double c1=(-1)*z*rr.Pi()*(fluido->V()-rr.Q()*t[1])/zi;
   double b1=fluido->V()-D*(pm[0]-P[0]/2)/fluido->B(P[0]);
   double a1=D/(fluido->B(P[0])*2);
   //Solucao da Equacao
   P[1]=EqSeg(a1,b1,c1);
   double pk; //Salva a pressao da ultima iteracao
   do
   {
       pk=P[1]; 
       z=fluido->BrillZ(P[1]);
       c1=(-1)*z*rr.Pi()*(fluido->V()-rr.Q()*t[1])/zi;
       P[1]=EqSeg(a1,b1,c1);
   }while(fabs(P[1]-pk)>0.001);
   Wen[1]=Wen[0]+D*(pm[0]-(P[0]+P[1])/2);
   pm[1]=rr.Pi()*(1-Wen[1]/Wei);
   //Iteracoes restantes
   for(int i=2;i<=n;i++)
   {
         z=fluido->BrillZ(P[i-1]);
         c1=(-1)*z*rr.Pi()*(fluido->V()-rr.Q()*t[i])/zi;
         b1=fluido->V()-(Wen[i-1]/fluido->B(P[i-1]))-D*(pm[i-1]-P[i-1]/2)/fluido->B(P[i-1]);
         a1=D/(fluido->B(P[i-1])*2);
         P[i]=EqSeg(a1,b1,c1);
         do
         {
          pk=P[i];
          z=fluido->BrillZ(P[i]);
          c1=(-1)*z*rr.Pi()*(fluido->V()-rr.Q()*t[i])/zi;
           P[i]=EqSeg(a1,b1,c1);
       }while(fabs(P[i]-pk)>0.001);
       Wen[i]=Wen[i-1]+D*(pm[i-1]-(P[i-1]+P[i])/2);
       pm[i]=rr.Pi()*(1-Wen[i]/Wei);
   }
}

void CFetkovich::SolverOleo()
{
    Constantes();
    vector<double> pm(n+1,0.0); //pressão média no aquifero
   double D=Wei*(1-exp((-1)*J*rr.Pi()*dt/Wei))/rr.Pi(); //Constante simplificadora
   P[0]=pm[0]=rr.Pi();
   for(int i=1;i<=n;i++)
   {
           double N=rr.Q()*t[i];
           P[i]=(N*fluido->B()+(N*fluido->Co()-fluido->V()*fluido->Ceo())*fluido->B()*P[0]-Wen[i-1]-D*(pm[i-1]-P[i-1]/2))
           /(fluido->B()*(N*fluido->Co()-fluido->V()*fluido->Ceo())-D/2); //equacao explicita
           Wen[i]=Wen[i-1]+D*(pm[i-1]-(P[i-1]+P[i])/2);
           pm[i]=rr.Pi()*(1-Wen[i]/Wei);
   }
}

