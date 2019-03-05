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

void adaugare(nod* curent,int x)
{
    while(curent->st != NULL)
        curent=curent->st;

    ajutor=new nod;
    ajutor->st=NULL;
    ajutor->dr=NULL;
    ajutor->info=x;
    curent->st=ajutor;
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
    radacina->st=NULL;
    radacina->dr=NULL;

    curent=radacina;
    for(i=0; i<=n/2; i++)
    {
        f>>curent->info;
        ajutor=new nod;
        ajutor->st=NULL;
        ajutor->dr=NULL;
        curent->st=ajutor;
        ajutor=curent;
        curent=curent->st;
    }
    ajutor->st=NULL;

    curent=new nod;
    curent->dr=NULL;
    curent->st=NULL;

    radacina->dr=curent;
    for(i=n/2+1; i<n; i++)
    {
        f>>curent->info;
        ajutor=new nod;
        ajutor->st=NULL;
        ajutor->dr=NULL;
        curent->dr=ajutor;
        ajutor=curent;
        curent=curent->dr;
    }
    ajutor->dr=NULL;

    cout<<"RSD: ";
    RSD(radacina);
    cout<<endl;

    cout<<"SRD: ";
    SRD(radacina);
    cout<<endl;

    cout<<"SDR: ";
    SDR(radacina);
    cout<<endl;

    cout<<"\nElementul ce trebuie adaugat ";
    cin>>x;
    adaugare(radacina,x);

    cout<<"RSD: ";
    RSD(radacina);
    cout<<endl;

    cout<<"SRD: ";
    SRD(radacina);
    cout<<endl;

    cout<<"SDR: ";
    SDR(radacina);
    cout<<endl;

}
