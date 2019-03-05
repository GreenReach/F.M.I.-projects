#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");

struct nod
{
    int info;
    nod *bck,*next;
};

nod *prim,*ajutor,*curent,*start,*ultim;

void sterg(int n)
{
    int p,x;
    cout<<"SCRIETI VALOAREA ELEMENTULUI CE VA FII STERS ";
    cin>>x;

    if(prim->info==x)
    {
        curent=prim->next;
        start->next=curent;
        curent->bck=start;
        prim=curent;
    }
    else
    {
        ajutor=start->bck;

        while(ajutor->info!=x)
        {
            ajutor->next=start->next;
            curent=start->next;
            curent->bck=ajutor;
            start->bck=ajutor->bck;
            curent=start->bck;
            curent->next=start;
            start->next=ajutor;
            ajutor->bck=start;
            ajutor=start->bck;
        }

        curent=ajutor->bck;
        ajutor=ajutor->next;
        ajutor=ajutor->next;
        curent->next=ajutor;
        ajutor->bck=curent;

        curent=prim->bck;
        curent->next=start;
        start->bck=curent;
        start->next=prim;
        prim->bck=start;
    }

    curent=prim;
    while(curent!=start)
    {
        cout<<curent->info<<" ";
        curent=curent->next;
    }
    cout<<endl;

}

void adaug()
{
    int p,x;
    cout<<"SCRIETI VALOAREA SI POZITIA PE CARE VA FI ADAUGATA ";
    cin>>x>>p;

    ajutor=new nod;
    ajutor->info=x;

    if(p==0)
    {
        prim->bck=ajutor;
        ajutor->next=prim;
        ajutor->bck=start;
        start->next=ajutor;
        prim=ajutor;
    }
    else
    {
        for(int i=0; i<p; i++)
        {
            curent=start->next;
            start->next=curent->next;
            curent->bck=start->bck;
            start->bck=curent;
            curent->next=start;
            ultim=start->next;
            ultim->bck=start;
            ultim=curent->bck;
            ultim->next=curent;
        }
        ajutor->next=start->next;
        ajutor->bck=start->bck;
        ultim=ajutor->next;
        ultim->bck=ajutor;
        ultim=ajutor->bck;
        ultim->next=ajutor;

        curent=prim->bck;
        curent->next=start;
        start->bck=curent;
        start->next=prim;
        prim->bck=start;
    }

    curent=prim;
    while(curent!=start)
    {
        cout<<curent->info<<" ";
        curent=curent->next;
    }

}

int main()
{
    int n,i;
    f>>n>>i;

    prim=new nod;
    prim->info=i;
    curent=new nod;
    prim->next=curent;
    curent->bck=prim;

    for(i=1; i<n; i++)
    {
        f>>curent->info;
        ajutor=new nod;
        ajutor->bck=curent;
        curent->next=ajutor;
        curent=ajutor;
    }
    curent->next=prim;

    start=curent;

    cout<<"LISTA ACTUALA ESTE: ";
    curent=prim;
    while(curent!=start)
    {
        cout<<curent->info<<" ";
        curent=curent->next;
    }
    cout<<endl;
    sterg(n);
    adaug();
}
