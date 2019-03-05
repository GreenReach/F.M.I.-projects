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

int cautare(nod* curent,int x)
{
    if(curent->info==x)
        return 1;

    if(curent->info>x && curent->st!=NULL)
        return cautare(curent->st,x);
    else if(curent->dr!=NULL)
        return cautare(curent->dr,x);

    return 0;
}

void element_max(nod* curent)
{
    while(curent->dr!=NULL)
        curent=curent->dr;
    cout<<"Elementul maxim este "<<curent->info<<endl;
}

void cauta(nod* curent,nod* ajutor)
{
    if(curent->info!=ajutor->info)
    {
        if(curent->info>ajutor->info)
            cauta(curent,ajutor->dr);

        if(curent->info<ajutor->info)
            cauta(curent,ajutor->st);
    }
}

void delete1(nod* curent)
{
    cauta(curent,radacina);

    if(ajutor->st==curent)
        ajutor->st=NULL;
    else
        ajutor->dr=NULL;
}

void sterg(nod* curent)
{
    if(curent->st==NULL && curent->dr==NULL)
        delete1(curent);
}

void element_x(nod* curent,int x)
{
    if(curent->info==x)
    {
        sterg(curent);
    }
    else
    {
        if(curent->st!=NULL)
            element_x(curent->st,x);

        if(curent->dr!=NULL)
            element_x(curent->dr,x);
    }

}


int main()
{
    int n,i,x;
    f>>n;

    radacina=new nod;
    f>>radacina->info;
    radacina->st=NULL;
    radacina->dr=NULL;

    for(i=1; i<n; i++)
    {
        ajutor=new nod;
        ajutor->st=NULL;
        ajutor->dr=NULL;
        f>>ajutor->info;
        creeare(radacina);
    }

    cout<<"RSD: ";
    RSD(radacina);
    cout<<endl;

    cout<<"SRD: ";
    SRD(radacina);
    cout<<endl;

    cout<<"SDR: ";
    SDR(radacina);
    cout<<endl;

    cout<<"Elementul ce il doriti inserat:";
    ajutor=new nod;
    ajutor->st=NULL;
    ajutor->dr=NULL;
    cin>>ajutor->info;
    creeare(radacina);

    cout<<"RSD: ";
    RSD(radacina);
    cout<<endl;

    cout<<"SRD: ";
    SRD(radacina);
    cout<<endl;

    cout<<"SDR: ";
    SDR(radacina);
    cout<<endl;

    cout<<"Elementul ce trebuie cautat:";
    cin>>x;
    if(cautare(radacina,x)==1)
        cout<<"ELEMENTUL SE AFLA IN ARBORE";
    else
        cout<<"ELEMENTUL NU SE AFLA IN ARBORE";
    cout<<endl;

    element_max(radacina);

    cout<<"Elementul ce trebuie sters ";
    cin>>x;
    element_x(radacina,x);

    cout<<"RSD: ";
    RSD(radacina);
    cout<<endl;

    cout<<"SRD: ";
    SRD(radacina);
    cout<<endl;

    cout<<"SDR: ";
    SDR(radacina);
    cout<<endl;

    cout<<endl;
}
