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


void numere()
{
    int par=0,impar=0,nr_impar=0;
    curent=prim;

    while(curent->next!=NULL)
    {
        if(curent->info%2==0)
            par++;
        else
        {
            impar+=curent->info;
            nr_impar++;
        }
        curent=curent->next;
    }

    cout<<"Numere pare: "<<par<<endl;

    if(nr_impar>0)
        cout<<"Media aritmetica a numerelor impare este: "<<impar/nr_impar;
    else
        cout<<"Nu exista numere impare";
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

    numere();
}
