#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;
ifstream f("date.in");
/*
Model date de intrare in fisierul "date.in"
rand 1-numar stari
rand 3-stare initiala
rand 5-numari stari finale
rand 7-stari finale
rand 9-lungime alfabet (delta)
rand 11-elemente alfabet (delta)
rand 13-functia de trecere in forma "1 a 2"(1 si 2 sunt noduri, 'a'este litera cu care se trece din starea 1 in starea 2)
Obs: numerotarea nodurilor se incepe de la 1
*/

//Transmit toti parametrii automatului determinist finit ce se afla in starea "stare" pentru a verifica daca cuvantul "x" este acceptat
int calcul(char x[100],int stare,int** automat,int* stari,int nr_delta,char *delta,int nr_stari)
{
        //Verific daca s-a ajuns la finalul cuvantului si afisez un mesaj corespunzator
        if( strlen(x)==0 )
        {
            if( stari[stare] == 1 )
                cout << "CUVANT ACCEPTAT";
            else
                cout << "CUVANT NEACCEPTAT";
        }
        else
        {
         //daca cuvantul nu este nul calculez urmatorea configuratoe a automatului la procesarea urmatoarei liteer din cuvant
         char c;
         int muchie, i, ok=0 ;
                
         c=x[0];
         strcpy(x,x+1);
        
         for(i = 0 ;i < nr_delta; i++)
            if(delta[i] == c)
                 {muchie = i;ok=1;}
            if(ok!=1)
                {
                    //daca starea nu exista cuvantul nu este acceptat
                    cout<<"CUVANT NEACCEPTAT";
                    return 0;
                }
            if(automat[stare][muchie]==-1)
            cout<<"Cuvantul nu este acceptat";
       else
         calcul(x,automat[stare][muchie],automat,stari,nr_delta,delta,nr_stari);
                
        }
}


int main()
{
   int  j,a,c,i,nr_stari,*stari,nr_stari_fin,stare_init,nr_delta;
   int **automat;
   char *delta,b,x[100];

   //citesc numarul de stari si creez un vector de aceeasi dimensiune
   f >> nr_stari;
   stari = new int[nr_stari];

   //notez cu 1 starile finale din automat 
   f >> stare_init;
   f >> nr_stari_fin;
   for(i=0;i<nr_stari_fin;i++)
   {
       f >> a;
       stari[a-1] = 1;
   }

   //creez un vector unde salvez literele din alfabet dupa ce le citesc 
   f >> nr_delta;
   delta = new char[nr_delta];
   for(i = 0 ;i<nr_delta ;i++)
    f >> delta[i];

   //creez matricea automatului unde fiecare coloana reprezinta o stare si fiecaer linie o litera din alfabet
   automat=new int*[nr_stari];
   for(i = 0 ;i<nr_stari ;i++)
    automat[i] = new int[nr_delta];

   for(i=0;i<nr_stari;i++)
    for(j=0;j<nr_delta;j++)
        automat[i][j]=-1;

   //completez matricea cu funtia de tranzitie lasand -1 pentru valoriile din care nu se mai poate deplasa
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
        
        //citesc cunvatul ce trebuie acceptat de automat si afisez un mesaj corespunzator
        if(x[0]=='0')
                if(stari[stare_init-1]==1)
                    cout<<"CUVANT ACCEPTAT";
                else
                    cout<<"CUVANT NEACCEPTAT";
        else
          calcul(x,stare_init-1,automat,stari,nr_delta,delta,nr_stari);

}
