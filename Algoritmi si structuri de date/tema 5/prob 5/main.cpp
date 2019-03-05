#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");

struct coada
{
    int info;
    coada *next;
};

coada *prim,*ajutor,*curent,*ultim;

void push(int a)
{
    ajutor=new coada;
    ajutor->info=a;
    ajutor->next=prim;
    prim=ajutor;

    cout<<"COADA ESTE: ";

    curent=prim;
    ajutor=ultim;

    cout<<ultim->info<<" ";

    while(ajutor!=prim)
    {
        curent=prim;
        while(curent->next!=ajutor)
            curent=curent->next;
        cout<<curent->info<<" ";
        ajutor=curent;
    }

    cout<<endl;
}


int pop()
{
    curent=prim;
    while(curent->next!=ultim)
        curent=curent->next;

    ajutor=ultim;
    ajutor->next=NULL;
    ultim=curent;

    return ajutor->info;
}


bool search()
{
    if(prim->next==NULL)
        return 0;
    return 1;
}


int empty(int a)
{
    ajutor=ultim;
    int nr=0;

    while(ajutor!=prim)
    {
        if(ajutor->info==a)
            return nr;

        nr++;
        curent=prim;

        while(curent->next!=ajutor)
            curent=curent->next;

        ajutor=curent;

    }

    if(curent->info==a)
        return nr;

    return -1;
}


int main()
{
    int n,i,x;
    f>>n;

    ultim=new coada;
    curent=new coada;
    curent->next=NULL;
    ultim->next=curent;
    prim=ultim;

    for(i=0; i<n; i++)
    {
        f>>prim->info;
        ajutor=new coada;
        ajutor->next=prim;
        prim=ajutor;

    }
    prim=prim->next;

    cout<<"COADA ACTUALA ESTE: ";
    curent=prim;
    ajutor=ultim;
    cout<<ultim->info<<" ";

    while(ajutor!=prim)
    {
        curent=prim;

        while(curent->next!=ajutor)
            curent=curent->next;

        cout<<curent->info<<" ";
        ajutor=curent;
    }
    cout<<endl;

    cout<<"ELEMENTUL VA FI ADAUGAT IN COADA: ";
    cin>>x;
    push(x);

    cout<<"PRIMUL ELEMENT AL COZII CE A FOST SI SCOS ESTE: "<<pop()<<endl;

    cout<<"PRIMUL ELEMENT DIN COADA ESTE: "<<ultim->info<<endl;
    if(search())
        cout<<"COADA NU ESTE VIDA";
    else
        cout<<"COADA ESTE VIDA";
    cout<<endl;

    cout<<"ELEMENTUL CAUTAT ESTE: ";
    cin>>x;
    if(empty(x)>=0)
        cout<<"ELEMENTUL A FOST GASIT SI SE AFLA PE POZITIA: "<<empty(x);
    else
        cout<<"ELEMENTUL NU A FOST GASIT";
    cout<<endl;

    cout<<"LISTA ACTUALA ESTE: ";
    curent=prim;
    ajutor=ultim;
    cout<<ultim->info<<" ";

    while(ajutor!=prim)
    {
        curent=prim;

        while(curent->next!=ajutor)
            curent=curent->next;

        cout<<curent->info<<" ";
        ajutor=curent;
    }
}
