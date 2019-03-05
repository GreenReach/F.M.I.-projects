#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");
struct nod
{
    int info;
    nod *next;
};

nod *primA,*curentA,*ajutorA,*primB,*curentB,*ajutorB,*primC,*curentC,*ajutorC;

void citire(nod *&curent,nod *&prim,nod *&ajutor,int n)
{
    int i;
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
}


void creeare(int n,int m)
{
    curentA=primA;
    curentB=primB;

    while(curentB->info<primA->info && curentB->next!=NULL)
    {
        ajutorB=curentB->next;
        curentB->next=primA;
        primA=curentB;
        curentB=ajutorB;
    }

    ajutorA=curentA;
    curentA=curentA->next;

    while(curentA->next!=NULL && curentB->next!=NULL)
        if(curentA->info>curentB->info)
        {
            ajutorB=curentB->next;
            ajutorA->next=curentB;
            curentB->next=curentA;
            curentB=ajutorB;
            curentA=ajutorA;
            curentA=curentA->next;
        }
        else
        {
            ajutorA=curentA;
            curentA=curentA->next;
        }


    while(curentB->next!=NULL)
    {
        curentA->next=curentB;
        curentB=curentB->next;
        curentA=curentA->next;
    }


}

int main()
{
    int i,j,n,m;
    f>>n>>m;

    citire(curentA,primA,ajutorA,n);
    citire(curentB,primB,ajutorB,m);

    creeare(n,m);

    curentA=primA;
    while(curentA->next!=NULL)
    {
        cout<<curentA->info<<" ";
        curentA=curentA->next;
    }

}
