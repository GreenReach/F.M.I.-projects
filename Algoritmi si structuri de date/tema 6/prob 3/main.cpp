#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");

struct nod
{
    int info;
    nod *next,*bck;
};

nod *prim,*ajutor,*curent,*ultim;

void adaug_i()
{
    cout<<"SCRIETI ELEMENTUL: ";
    ajutor=new nod;
    cin>>ajutor->info;

    ajutor->next=prim;
    prim->bck=ajutor;
    prim=ajutor;

    cout<<"LISTA ACTUALA ESTE: ";
    curent=prim;
    while(curent->next!=NULL)
    {
        cout<<curent->info<<" ";
        curent=curent->next;
    }
    cout<<endl<<endl;
}

void adaug_s()
{
    cout<<"SCRIETI ELEMENTUL: ";
    ajutor=new nod;
    cin>>ajutor->info;

    ajutor->next=ultim->next;
    ultim->next=ajutor;
    ajutor->bck=ultim;
    ultim=ajutor;

    cout<<"LISTA ACTUALA ESTE: ";
    curent=prim;
    while(curent->next!=NULL)
    {
        cout<<curent->info<<" ";
        curent=curent->next;
    }
    cout<<endl<<endl;
}

void sterg_i()
{
    prim=prim->next;

    cout<<"LISTA ACTUALA ESTE: ";
    curent=prim;
    while(curent->next!=NULL)
    {
        cout<<curent->info<<" ";
        curent=curent->next;
    }
    cout<<endl<<endl;
}

void sterg_s()
{
    ultim->next=NULL;
    ultim=ultim->bck;

    cout<<"LISTA ACTUALA ESTE: ";
    curent=prim;
    while(curent->next!=NULL)
    {
        cout<<curent->info<<" ";
        curent=curent->next;
    }
    cout<<endl<<endl;
}

int main()
{
    int i,n;
    f>>n;
    f>>i;

    prim=new nod;
    prim->info=i;
    curent=new nod;
    prim->next=curent;
    ajutor=prim;

    for(i=0; i<n; i++)
    {
        f>>curent->info;
        curent->bck=ajutor;
        curent=new nod;
        ajutor=ajutor->next;
        ajutor->next=curent;

    }

    curent=ajutor;
    curent->next=NULL;
    ultim=curent->bck;

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
    cout<<"[3] STERGETI PRIMUL ELEMENT"<<endl;
    cout<<"[4] STERGETI ULTIMUL ELEMENT"<<endl;
    cout<<"[0] EXIT"<<endl;
    cin>>i;

    switch(i)
    {
    case 1:
        adaug_i();
        goto meniu;
    case 2:
        adaug_s();
        goto meniu;
    case 3:
        sterg_i();
        goto meniu;
    case 4:
        sterg_s();
        goto meniu;
    case 0:
        break;
    }
}
