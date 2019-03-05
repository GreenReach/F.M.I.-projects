#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");
struct nod
{
    int info,poz;
    nod *next;
};

nod *prim1,*prim2,*curent,*ajutor,*curent1,*ajutor1;


void suma(int n,int m)
{
    int pozm,i;

    if(n>m)
        pozm=n;
    else
        pozm=m;

    curent=prim1;
    curent1=prim2;

    for(i=0; i<pozm; i++)
    {
        if(curent->poz==i && curent1->poz==i)
        {
            cout<<curent->info+curent1->info<<" ";
            curent=curent->next;
            curent1=curent1->next;
        }
        else if(curent->poz==i)
        {
            cout<<curent->info<<" ";
            curent=curent->next;
        }
        else if(curent1->poz==i)
        {
            cout<<curent1->info<<" ";
            curent1=curent1->next;
        }
        else
            cout<<"0 ";
    }
}

void produs(int n,int m)
{
    int pozm,i,prod=0;

    if(n>m)
        pozm=n;
    else
        pozm=m;

    curent=prim1;
    curent1=prim2;

    for(i=0; i<pozm; i++)
    {
        if(curent->poz==i && curent1->poz==i)
        {
            prod+=curent->info *curent1->info;
            curent=curent->next;
            curent1=curent1->next;
        }
        else if(curent->poz==i)
        {
            curent=curent->next;
        }
        else if(curent1->poz==i)
        {
            curent1=curent1->next;
        }
    }

    cout<<endl<<prod;

}
int main()
{
    int n,i,x,m;
    f>>n>>m;

    prim1=new nod;
    curent=prim1;

    for(i=0; i<n; i++)
    {
        f>>x;

        if(x!=0)
        {
            curent->info=x;
            curent->poz=i;
            ajutor=new nod;
            curent->next=ajutor;
            curent=ajutor;
        }
    }
    curent->next=NULL;

    prim2=new nod;
    curent1=prim2;
    for(i=0; i<m; i++)
    {
        f>>x;
        if(x!=0)
        {
            curent1->info=x;
            curent1->poz=i;
            ajutor=new nod;
            curent1->next=ajutor;
            curent1=ajutor;
        }
    }
    curent1->next=NULL;

    curent=prim1;
    cout<<"Suma vectorilor este"<<endl;
    suma(n,m);

    cout<<"Produsul vecotrilor este "<<endl;
    produs(n,m);


}
