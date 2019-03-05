#include <iostream>
#include<fstream>
#include<cmath>
using namespace std;
ifstream f("date.in");

struct nod
{
    int info;
    nod *st,*dr;
};

nod *radacina,*curent,*ajutor;

void creeare(nod* curent)
{
    if(ajutor->info>curent->info)
        if(curent->dr==NULL)
            curent->dr=ajutor;
        else
            creeare(curent->dr);

    if(ajutor->info<curent->info)
        if(curent->st==NULL)
            curent->st=ajutor;
        else
            creeare(curent->st);


}

void afisare(nod* curent)
{
    cout<<curent->info<<" ";

    if(curent->dr!=NULL)
        afisare(curent->dr);

    if(curent->st!=NULL)
        afisare(curent->st);
}



void SRD(nod* curent,int k1,int k2)
{
    if(curent->st!=NULL)
        SRD(curent->st,k1,k2);

    if(curent->info>=k1 && curent->info<=k2)
        cout<<curent->info<<" ";

    if(curent->dr!=NULL)
        SRD(curent->dr,k1,k2);
}


int main()
{
    int n,i,x,k1,k2;
    f>>n;
    radacina=new nod;
    f>>radacina->info;
    radacina->st=NULL;
    radacina->dr=NULL;

    cout<<"Valori citite: ";
    cout<<radacina->info<<" ";

    for(i=1; i<n; i++)
    {
        ajutor=new nod;
        ajutor->st=NULL;
        ajutor->dr=NULL;
        f>>ajutor->info;
        cout<<ajutor->info<<" ";
        creeare(radacina);
    }


    cout<<"\nIntroduceti k1 si k2: ";
    cin>>k1>>k2;

    if(k1>k2)
        swap(k1,k2);

    cout<<"Numerele din arbore din intervalul [k1,k2] sunt: ";
    SRD(radacina,k1,k2);
    cout<<endl;

}
