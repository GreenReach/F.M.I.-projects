#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;
ifstream f("date.in");
/*
randaca 1-numar stari
rand 3-stare initiala
rand 5-nr stari finale
rand 7-stari finale
rand 9-lungime delat
rand 11-delta
rand 13-functia de trecere in forma 1 a 2(1 si 2 sunt noduri, 'a'e litera cu care se trece
NOTAREA NODURILOR CAND SE SCRIE "date.in" LA CITIRE INCEPE CU 1 !!!
*/
int calcul(char x[100],int stare,int** automat,int* stari,int nr_delta,char *delta,int nr_stari)
{
        if( strlen(x)==0 )
        {
            if( stari[stare] == 1 )
                cout << "CUVANT ACCEPTAT";
            else
                cout << "CUVANT NEACCEPTAT";
        }
        else
        {
         char c;
         int muchie,i;

         c=x[0];
         strcpy(x,x+1);
         int ok=0;
         for(i = 0 ;i < nr_delta; i++)
            if(delta[i] == c)
            {muchie = i;ok=1;}
            if(ok!=1){cout<<"CUVANT NEACCEPTAT";return 0;}
            if(automat[stare][muchie]==-1)
            cout<<"Cuvantul nu este acceptat";
       else

         calcul(x,automat[stare][muchie],automat,stari,nr_delta,delta,nr_stari);
}
}


int main()
{
   int  j,a,c,i,nr_stari,*stari,nr_stari_fin,stare_init,nr_delta;
   int** automat;
   char *delta,b,x[100];

   f >> nr_stari;
   stari = new int[nr_stari];


   f >> stare_init;
   f >> nr_stari_fin;
   for(i=0;i<nr_stari_fin;i++)
   {
       f >> a;
       stari[a-1] = 1;
   }

   f >> nr_delta;
   delta = new char[nr_delta];
   for(i = 0 ;i<nr_delta ;i++)
    f >> delta[i];

   automat=new int*[nr_stari];
   for(i = 0 ;i<nr_stari ;i++)
    automat[i] = new int[nr_delta];

     for(i=0;i<nr_stari;i++)
    for(j=0;j<nr_delta;j++)
        automat[i][j]=-1;

  while(f)
  {
      f >> a >> b;
      for(i = 0 ;i<nr_delta ;i++)
        if(delta[i] == b)
        c = i;
      f >> automat[a-1][c];
      automat[a-1][c]--;

  }

        cout << "Automatul a fost construit.Inserati cuvantul dorit: ";
        cin >> x;
        if(x[0]=='0')
        if(stari[stare_init-1]==1)
            cout<<"CUVANT ACCEPTAT";
        else
            cout<<"CUVANT NEACCEPTAT";
        else
        calcul(x,stare_init-1,automat,stari,nr_delta,delta,nr_stari);

}
