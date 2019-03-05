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

void adaug(char a)
{
    ajutor=new stiva;
    ajutor->info=a;
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
    int n,i;
    f>>n;

    prim=new stiva;
    prim->next=NULL;

    for(i=0; i<n; i++)
    {
        f>>a;
        if(a!=prim->info && prim->next!=NULL)
            sterg();
        else
            adaug(a);

    }

    if(prim->next==NULL)
        cout<<"NUMARUL DE CARACTERE ESTE ACELASI";
    else
        cout<<"NUMARUL DE CARACTERE ESTE DIFERIT";

}
