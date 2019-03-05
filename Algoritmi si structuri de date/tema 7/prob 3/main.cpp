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

void RSD(nod* curent)
{
    cout<<curent->info<<" ";

    if(curent->st!=NULL)
        RSD(curent->st);

    if(curent->dr!=NULL)
        RSD(curent->dr);
}

void SRD(nod* curent)
{
    if(curent->st!=NULL)
        SRD(curent->st);

    cout<<curent->info<<" ";

    if(curent->dr!=NULL)
        SRD(curent->dr);
}

void SDR(nod* curent)
{
    if(curent->st!=NULL)
        SDR(curent->st);

    if(curent->dr!=NULL)
        SDR(curent->dr);

    cout<<curent->info<<" ";
}

int main()
{
    int n,i,x;
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

    cout<<"\nArborele Sortat ";
    SRD(radacina);
    cout<<endl;

}
