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

void citire(int n)
{
    int i;
    primC=new nod;
    curentC=primC;

    for(i=0; i<n; i++)
    {
        f>>curentC->info;
        ajutorC=new nod;
        curentC->next=ajutorC;
        curentC=ajutorC;
    }
    curentC->next=NULL;
}


void creeare()
{
    primA=primC;
    primB=primC->next;
    ajutorA=primA;
    ajutorB=primB;
    curentC=primB->next;

    while(curentC->next!=NULL)
    {
        if(curentC->next!=NULL)
        {
            ajutorA->next=curentC;
            ajutorA=curentC;
            curentC=curentC->next;
            ajutorA->next=NULL;
        }

        if(curentC->next!=NULL)
        {
            ajutorB->next=curentC;
            ajutorB=curentC;
            curentC=curentC->next;
            ajutorB->next=NULL;
        }
    }
}

int main()
{
    int i,j,n,m;
    f>>n;
    citire(n);
    creeare();

    cout<<"LISTA A: ";
    curentA=primA;
    while(curentA->next!=NULL)
    {
        cout<<curentA->info<<" ";
        curentA=curentA->next;
    }
    cout<<curentA->info;

    cout<<endl<<"LISTA B: ";
    curentB=primB;
    while(curentB->next!=NULL)
    {
        cout<<curentB->info<<" ";
        curentB=curentB->next;
    }
    cout<<curentB->info;

}
