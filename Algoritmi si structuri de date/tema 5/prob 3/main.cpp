#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");

struct stiva
{
    char info;
    stiva *next;
};

stiva *prim,*ajutor,*curent;

void adaug()
{
    ajutor=new stiva;
    ajutor->next=prim;
    prim=ajutor;

}

void sterg()
{
    prim=prim->next;
}

int main()
{
    char a;
    int n,i,poz=-1;
    f>>n;

    prim=new stiva;
    prim->next=NULL;

    for(i=1; i<n; i++)
    {
        f>>a;

        if(a=='(')
            adaug();
        if(a==')')
            if(prim->next!=NULL)
                sterg();
            else
                poz=i;

    }

    if(poz>=0 || prim->next!=NULL)
        cout<<"NU ESTE PARANTEZA CORECT PE POZITIA "<<poz;
    else
        cout<<"SIRUL ESTE BINE PARANTERIZAT";

}
