#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");

struct nod
{
    int info;
    nod *next;
};

nod *prim,*curent,*ajutor;

void medie(int x)
{
    curent=new nod;
    curent->info=x;
    curent->next=ajutor->next;
    ajutor->next=curent;
}

int main()
{
    int i,n;
    f>>n;
    prim=new nod;
    curent=prim;

    for(i=0; i<n; i++)
    {
        f>>curent->info;
        ajutor=new nod;
        curent->next=ajutor;
        curent=curent->next;
    }
    curent->next=NULL;

    ajutor=prim;
    curent=prim->next;

    while(curent->next!=NULL)
    {
        medie((curent->info+ajutor->info)/2);
        curent=curent->next;
        ajutor=curent;
        curent=curent->next;
    }

    curent=prim;
    while(curent->next!=NULL)
    {
        cout<<curent->info<<" ";
        curent=curent->next;
    }
}
