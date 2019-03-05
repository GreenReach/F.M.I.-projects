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

void adaug_inceput(int x)
{
    ajutor=new nod;
    ajutor->info=x;
    ajutor->next=curent;
    prim=ajutor;
}

void adaug_final(int x)
{
    ajutor=new nod;
    ajutor->next=NULL;
    curent->info=x;
    curent->next=ajutor;
}

void adaug_intre(int x)
{
    curent=new nod;
    curent->info=x;
    curent->next=ajutor->next;
    ajutor->next=curent;
}

int main()
{
    int n,i,x;
    f>>n;
    prim=new nod;
    f>>prim->info;

    curent=new nod;
    prim->next=curent;

    curent->next=NULL;

    for(i=0; i<n-1; i++)
    {
        curent=prim;
        ajutor=NULL;
        f>>x;

        while(x>curent->info && curent->next!=NULL)
        {
            ajutor=curent;
            curent=curent->next;
        }

        if(ajutor==NULL)
            adaug_inceput(x);
        else if(curent->next==NULL)
            adaug_final(x);
        else
            adaug_intre(x);
    }


    curent=prim;
    while(curent->next!=NULL)
    {
        cout<<curent->info<<" ";
        curent=curent->next;
    }

}
