ere#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");

struct nod{
int info;
nod *next,*bck;};

nod *prim,*ajutor,*curent;

void adaug_i()
{
    cout<<"SCRIETI ELEMENTUL ";
    curent=new nod;
    cin>>curent->info;
    curent->next=prim;
    prim->bck=curent;
    prim=curent;
    cout<<endl<<endl;
}

void adaug_s()
{cout<<"SCRIETI ELEMENTUL ";
    curent=prim;
    while(curent->next!=NULL)
        curent=curent->next;
    ajutor=new nod;
    cin>>curent->info;
    ajutor->bck=curent;
    curent->next=ajutor;
    ajutor->next=NULL;
    cout<<endl<<endl;
}

void adaug_p()
{
    int x,p;
    cout<<"INSERATI POZITIA SI NR: ";
    cin>>p>>x;
    curent=prim;
    while(p!=0 && curent->next!=NULL)
      {curent=curent->next;p--;}
        if(curent->next==NULL)
            cout<<"POZITIE INCORECTA";
            else
            {
                ajutor=new nod;
                ajutor->info=x;
                ajutor->next=curent;
                if(curent==prim)
                    prim=ajutor;
                    else
                      {
                    ajutor->bck=curent->bck;
                    curent=curent->bck;
                    curent->next=ajutor;}
            }
            cout<<endl<<endl;
}

void afis_o()
{
    cout<<"LISTA ACTUALA ESTE: ";
   curent=prim;
   while(curent->next!=NULL)
   {
       cout<<curent->info<<" ";
      curent=curent->next;
   }
   cout<<endl<<endl;
}

void afis_i()
{cout<<"LISTA INVERSATA ESTE: ";
    curent=prim;
    while(curent->next!=NULL)
        curent=curent->next;
        curent=curent->bck;
    while(curent!=prim)
    {
        cout<<curent->info<<" ";
        curent=curent->bck;
    }
    cout<<curent->info;

    cout<<endl<<endl;
}

void sterg_v()
{
    cout<<"Scrieti valoarea elementului ";
    int x;
    cin>>x;
    curent=prim;
    while(curent->info!=x && curent->next!=NULL)
        curent=curent->next;
    if(curent->next==NULL)
        cout<<"ELEMENTUL NU A FOST GASIT";
    else
    {
     if(curent==prim)
            prim=prim->next;
     else
     {
         ajutor=curent->bck;
         ajutor->next=curent->next;
     }
    }
    cout<<endl<<endl;
}

void sterg_p()
{int p;
    cout<<"SCRIETI POZITIA ELEMENTULUI ";
    cin>>p;
    if(p==0)
        prim=prim->next;
        curent=prim;
    while(p!=0 && curent->next!=NULL)
        {curent=curent->next;p--;}
        if(curent->next==NULL)
            cout<<"POZITIA NU SE AFLA IN LISTA";
            else
       {
        ajutor=curent->bck;
        ajutor->next=curent->next;}
        cout<<endl<<endl;
}

int main()
{
   int i,n;
   f>>n;f>>i;
   prim=new nod;prim->info=i;
   curent=new nod;prim->next=curent;ajutor=prim;
   for(i=0;i<n;i++)
   {
       f>>curent->info;
       curent->bck=ajutor;
       curent=new nod;
       ajutor=ajutor->next;
       ajutor->next=curent;

   }
   curent=ajutor;
   curent->next=NULL;


meniu:
   cout<<"LISTA ACTUALA ESTE: ";
   curent=prim;
   while(curent->next!=NULL)
   {
       cout<<curent->info<<" ";
      curent=curent->next;
   }
   cout<<endl<<"[1] ADAUGATI UN ELEMENT LA INCEPUT"<<endl;
   cout<<"[2] ADAUGATI UN ELEMENT LA FINAL"<<endl;
   cout<<"[3] ADAUGATI UN ELEMENT IN INTERIORUL LISTEI"<<endl;
   cout<<"[4] AFISAREA LISTEI IN ORIDNEA INTRODUCERII"<<endl;
   cout<<"[5] AFISAREA LISTEI IN ORDINE INVERSA"<<endl;
   cout<<"[6] STERGEREA UNUI ELEMENT DIN LISTA DUPA VALOARE"<<endl;
   cout<<"[7] STERGEREA UNUI ELEMENT DIN LISTA DUPA POZITIE"<<endl;
   cout<<"[0] EXIT"<<endl;
   cin>>i;
   switch(i){
       case 1: adaug_i();goto meniu;
       case 2: adaug_s();goto meniu;
       case 3: adaug_p();goto meniu;
       case 4: afis_o();goto meniu;
       case 5: afis_i();goto meniu;
       case 6: sterg_v();goto meniu;
       case 7: sterg_p();goto meniu;
       case 0: break;
   }
}
