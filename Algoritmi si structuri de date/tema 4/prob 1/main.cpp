#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");
struct nod
{
    int info;
    nod *next;
};

nod *prim,*curent,*ajutor,*primB,*curentB,*ajutorB,*primNOU;

void invers_B(int n)
{
    primB=new nod;
    curentB=primB;
    int i,j;

    for(i=n-1; i>=0; i--)
    {
        curent=prim;
        for(j=0; j<i; j++)
            curent=curent->next;
        curentB->info=curent->info;
        ajutorB=new nod;
        curentB->next=ajutorB;
        curentB=ajutorB;
    }
    curentB->next=NULL;
}

void invers(int n)
{
    curent=prim;
    while(curent->next!=NULL)
        curent=curent->next;

    primNOU=curent;
    int i;
    for(i=0; i<n; i++)
    {
        curent=prim;
        ajutor=NULL;
        while(curent->next!=NULL)
        {
            ajutor=curent;
            curent=curent->next;
        }
        curent->next=ajutor;
        ajutor->next=NULL;
    }
    primNOU=primNOU->next;
    prim=primNOU;
    delete primNOU;
}


int main()
{
    int i,j,n;
    f>>n;

    prim=new nod;
    curent=prim;

    for(i=0; i<n; i++)
    {
        f>>curent->info;
        ajutor=new nod;
        curent->next=ajutor;
        curent=ajutor;
    }

    curent->next=NULL;
    cout<<"ELEMENTELE LISTEI A: ";
    curent=prim;

    while(curent->next!=NULL)
    {
        cout<<curent->info<<" ";
        curent=curent->next;
    }
    cout<<endl;

    invers_B(n);
    curentB=primB;
    cout<<"ELEMENTELE LISTEI B: ";

    while(curentB->next!=NULL)
    {
        cout<<curentB->info<<" ";
        curentB=curentB->next;
    }

    cout<<endl<<"ELEMENTELE LISTEI A DUPA INVERSARE: ";
    invers(n);
    curent=prim;

    while(curent->next!=NULL)
    {
        cout<<curent->info<<" ";
        curent=curent->next;
    }

    cout<<curent->info;


}
