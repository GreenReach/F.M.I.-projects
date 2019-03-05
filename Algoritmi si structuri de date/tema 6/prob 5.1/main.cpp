#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");

struct nod
{
    int info;
    nod *bck,*next;
};

nod *prim,*ajutor,*curent,*start,*ultim;

void sterg()
{
    curent=start->bck;
    curent=curent->bck;
    start->bck=curent;
    curent->next=start;

    cout<<"LISTA ACTUALA ESTE: ";
    curent=prim;
    while(curent!=start)
    {
        cout<<curent->info<<" ";
        curent=curent->next;
    }
    cout<<endl;

}

void adaug(int x)
{
    ajutor=new nod;
    ajutor->info=x;
    prim->bck=ajutor;
    ajutor->next=prim;
    ajutor->bck=start;
    start->next=ajutor;
    prim=ajutor;

    cout<<"LISTA ACTUALA ESTE: ";
    curent=prim;
    while(curent!=start)
    {
        cout<<curent->info<<" ";
        curent=curent->next;
    }
    cout<<endl;
}

int main()
{
    int n,i;
    f>>n>>i;

    prim=new nod;
    prim->info=i;
    curent=new nod;
    prim->next=curent;

    curent->bck=prim;
    for(i=1; i<n; i++)
    {
        f>>curent->info;
        ajutor=new nod;
        ajutor->bck=curent;
        curent->next=ajutor;
        curent=ajutor;
    }

    curent->next=prim;
    start=curent;

    cout<<"LISTA ACTUALA ESTE: ";
    curent=prim;
    while(curent!=start)
    {
        cout<<curent->info<<" ";
        curent=curent->next;
    }
    cout<<endl;

    int x;
    cout<<"APASATI 0 PENTRU A STERGE POZITIA , APASATI -1 PENTRU A IESI, APASATI ALTA VALOARE PT A O ADAUGA";
    cin>>x;

    while(x!=-1)
    {
        if(x==0)
            sterg();
        else
            adaug(x);

        cout<<"APASATI 0 PENTRU A STERGE POZITIA , APASATI -1 PENTRU A IESI, APASATI ALTA VALOARE PT A O ADAUGA";
        cin>>x;

    }

}
