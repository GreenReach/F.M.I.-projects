#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");

struct stiva
{
    int info;
    stiva *next;
};

stiva *prim,*ajutor,*curent;


void push(int a)
{
    curent=new stiva;
    curent->next=prim;
    curent->info=a;

    prim=curent;

    while(curent->next!=NULL)
    {
        cout<<curent->info<<" ";
        curent=curent->next;
    }
}

int pop()
{
    ajutor=prim;
    curent=prim->next;
    prim=curent;
    return ajutor->info;

}

int peek()
{
    return prim->info;
}

bool empty()
{
    if(prim->next==NULL)
        return 0;
    return 1;
}

int search(int a)
{
    int nr=0;
    curent=prim;

    while(curent->next!=NULL)
    {
        if(curent->info==a)
            return nr;
        nr++;
        curent=curent->next;
    }

    return -1;

}

void afiseaza()
{
    curent=prim;
    while(curent->next!=NULL)
    {
        cout<<curent->info<<" ";
        curent=curent->next;
    }
}
int main()
{
    int n,i,x;
    f>>n;

    ajutor=new stiva;
    ajutor->next=NULL;
    prim=new stiva;
    prim->next=ajutor;
    curent=prim;

    for(i=0; i<n; i++)
    {
        f>>curent->info;
        ajutor=new stiva;
        ajutor->next=curent;
        curent=ajutor;

    }
    prim=curent->next;


    cout<<"STIVA ACTUALA ESTE: ";

    curent=prim;
    while(curent->next!=NULL)
    {
        cout<<curent->info<<" ";
        curent=curent->next;
    }

    cout<<endl;
    cout<<"ADAUG UN ELEMENT IN VARFUL LISTEI: ";
    cin>>x;
    push(x);
    cout<<endl;

    cout<<"ELEMENTUL DIN VARFUL STIVEI A FOST SCOS SI ESTE: "<<pop();
    cout<<endl;

    cout<<"ELEMENTUL DIN VARFUL STIVEI ESTE: "<<peek();
    cout<<endl;

    cout<<"VERIFIC DACA STIVA ESTE VIDA: ";
    if(empty())
        cout<<"NU ESTE VIDA";
    else
        cout<<"ESTE VIDA";
    cout<<endl;

    cout<<"INTRODUCETI VALOAREA CE TREBUIE CAUTATA: ";
    cin>>x;
    if(search(x)>=0)
        cout<<"VALOAREA SE AFLA PE POZITIA "<<search(x);
    else
        cout<<"VALOAREA NU SE AFLA IN STIVA";
    cout<<endl;

    cout<<"STIVA ESTE: ";
    afiseaza();
}
