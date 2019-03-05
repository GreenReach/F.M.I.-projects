#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");

struct stiva
{
    int info;
    stiva *next;
};

stiva *prim,*ajutor,*curent;

void adaug(int x)
{
    ajutor=new stiva;
    ajutor->info=x;
    ajutor->next=prim;
    prim=ajutor;
}

void sterg()
{
    prim=prim->next;
}

int main()
{
    int n,i,x;
    f>>n;

    prim=new stiva;
    prim->next=NULL;

    curent=new stiva;
    f>>curent->info;
    curent->next=prim;

    prim=curent;
    for(i=1; i<n; i++)
    {
        f>>x;
        if(prim->info==x)
            sterg();
        else
            adaug(x);

    }

    if(prim->next==NULL)
        cout<<"PINII POT FII CONECTATI";
    else
        cout<<"PINII NU SE POT CONECTA";

}
