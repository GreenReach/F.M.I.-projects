#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;
ifstream f("date.in");

struct nod
{
    int info;
    nod *next;
};

nod *prim1,*prim2,*prims,*curent1,*curent2,*curents,*ajutor1,*ajutor2,*ajutors;


int main()
{
    char n1[50],n2[50],x;
    int i,j;

    f>>n1>>n2;
    prim1=new nod;
    curent1=prim1;

    for(i=0; i<strlen(n1); i++)
    {
        ajutor1=new nod;
        curent1->info=(int)(n1[strlen(n1)-i-1]-'0');
        curent1->next=ajutor1;
        curent1=ajutor1;
    }
    curent1->next=NULL;

    prim2=new nod;
    curent2=prim2;
    for(i=0; i<strlen(n2); i++)
    {
        ajutor2=new nod;
        curent2->info=(int)(n2[strlen(n2)-i-1]-'0');
        curent2->next=ajutor2;
        curent2=ajutor2;
    }
    curent2->next=NULL;

    curent1=prim1;
    curent2=prim2;
    prims=new nod;
    curents=prims;

    i=0;
    while(curent1->next!=NULL && curent2->next!=NULL)
    {
        i=i+curent1->info + curent2->info;
        curents->info=i%10;
        i/=10;
        ajutors=new nod;
        curents->next=ajutors;
        curents=ajutors;
        curent1=curent1->next;
        curent2=curent2->next;

    }

    if(strlen(n1)>strlen(n2))
        while(curent1->next!=NULL)
        {
            i+=curent1->info;
            curents->info=i%10;
            i/=10;
            ajutors=new nod;
            curents->next=ajutors;
            curents=ajutors;
            curent1=curent1->next;
        }

    if(strlen(n2)>strlen(n1))
        while(curent2->next!=NULL)
        {
            i+=curent2->info;
            curents->info=i%10;
            i/=10;
            ajutors=new nod;
            curents->next=ajutors;
            curents=ajutors;
            curent2=curent2->next;
        }

    if(i!=0)
    {
        curents->info=i;
        ajutors=new nod;
        curents->next=ajutors;
        curents=ajutors;
    }

    curents->next=NULL;
    int afisare[100];
    i=0;
    curents=prims;
    while(curents->next!=NULL)
    {
        afisare[i]=curents->info;
        i++;
        curents=curents->next;
    }
    for(j=i-1; j>=0; j--)
        cout<<afisare[j];
}
