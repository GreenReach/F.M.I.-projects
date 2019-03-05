#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");

struct nod
{
    int info;
    nod *next,*bck;
};

nod *prim,*ajutor,*curent,*start;

void sterg()
{
    cout<<"INSERATI VALOAREA CE TREBUIE STEARSA";
    int x;
    cin>>x;

    curent=start->next;
    while(curent->info!=x)
        curent=curent->next;

    ajutor=curent->bck;
    ajutor->next=curent->next;

    cout<<endl;
}

int main()
{
    int n,x,i;
    f>>n>>i;

    prim=new nod;
    prim->info=i;
    curent=new nod;
    curent->bck=prim;
    prim->next=curent;

    for(i=1; i<n; i++)
    {
        f>>curent->info;
        ajutor=new nod;
        curent->next=ajutor;
        ajutor->bck=curent;
        curent=ajutor;

    }
    curent->next=prim;

    start=curent;
    prim->bck=start;

    curent=start->next;
    while(curent!=start)
    {
        cout<<curent->info<<" ";
        curent=curent->next;
    }

    cout<<endl<<"INSERATI VALOAREA SI POZITIA PENTRU ADAUGARE: ";
    int p;
    cin>>x>>p;

    curent=start->next;
    for(i=0; i<p; i++)
        curent=curent->next;

    ajutor= new nod;
    ajutor->info=x;
    ajutor->bck=curent->bck;
    ajutor->next=curent;

    curent->bck=ajutor;
    curent=curent->bck;
    ajutor=ajutor->bck;
    ajutor->next=curent;

    curent=start->next;
    while(curent!=start)
    {
        cout<<curent->info<<" ";
        curent=curent->next;
    }
    cout<<endl;

    sterg();

    curent=start->next;
    while(curent!=start)
    {
        cout<<curent->info<<" ";
        curent=curent->next;
    }


}
