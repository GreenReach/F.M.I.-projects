
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

void afisare()
{
    curent=prim;
    while(curent->next!=NULL)
    {
        cout<<curent->info<<" ";
        curent=curent->next;
    }
}

//citensc pana ajung la ultimul nod si , ajutandu-ma de "ajutor",creez un nou nod
int inserare_final(int x)
{
    curent=prim;
    while(curent->next!=NULL)
        curent=curent->next;

    ajutor=new nod;
    curent->info=x;
    curent->next=ajutor;
    ajutor->next=NULL;
}

int inserare_inceput(int x)
{
    curent=new nod;
    curent->info=x;
    curent->next=prim;
    prim=curent;
}

//inserarea unei valorii x dupa valoarea val
int inserare_dupa(int x,int val)
{
    curent=prim;
    while(curent->info!=val && curent->next!=NULL)
        curent=curent->next;
    if(curent->next==NULL)
        cout<<"Valoarea nu se afla in lista";
    else
    {
        ajutor=new nod;
        ajutor->info=x;
        ajutor->next=curent->next;
        curent->next=ajutor;
    }
}

//cautarea unei valori in lista
int caut_val(int x)
{
    curent=prim;
    while(curent->info!=x && curent->next!=NULL)
        curent=curent->next;
    if(curent->info==x)
        cout<<"Valoarea se afla in lista";
    else
        cout<<"Valoarea nu se afla in lista";
}

//cautarea pozitiei unei valori date
int caut_poz(int x)
{
    curent=prim;
    x--;
    while(x!=0 && curent->next!=NULL)
    {
        curent=curent->next;
        x--;
    }
    if(curent->next!=NULL)
        cout<<"Elementul a fost gasit si este "<<curent->info;
    else
        cout<<"Elementul nu a fost gasit";
}

//stergerea unei valori date
int sterg_val(int x)
{
    curent=prim;
    ajutor=NULL;

    while(curent->info!=x && curent->next!=NULL)
    {
        ajutor=curent;
        curent=curent->next;
    }
    if(curent->info==NULL)
        cout<<endl<<"Valoarea nu se afla in lista"<<endl;
    else
    {
        if(ajutor==NULL)
            prim=prim->next;
        else if(curent->info==x)
        {
            ajutor->next=curent->next;
        }
    }
}

//Stergerea unei valori dupa pozitia sa
int sterg_poz(int x)
{
    curent=prim;
    ajutor=NULL;
    x--;
    while(x!=0 && curent->next!=NULL)
    {
        ajutor=curent;
        curent=curent->next;
        x--;
    }
    if(curent->next==NULL)
        cout<<endl<<"Pozitia nu se afla in lista";
    else
    {
        if(ajutor==NULL)
            prim=prim->next;
        else if(x==0)
        {
            ajutor->next=curent->next;
        }
    }
}

//stergerea intregii liste
void sterg()
{
    curent=prim;

    while(curent->next!=NULL)
    {
        ajutor=curent;
        curent=curent->next;
        delete ajutor;
    }
}

int main()
{
    int i,n,val;
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
    afisare();
    cout<<endl;
    //adaugare la final
    f>>i;
    cout<<"Adaug 4 la sfarsitul listei"<<endl;
    inserare_final(i);
    afisare();
    cout<<endl;
    //adaugare la inceput
    f>>i;
    cout<<"Adaug 20 la inceputul liste"<<endl;
    inserare_inceput(i);
    afisare();
    cout<<endl;
    //adaugare dupa o anumita valoare

    cout<<"Adaug valoarea i dupa valoarea val";
    cin>>i>>val;
    inserare_dupa(i,val);

    afisare();
    cout<<endl;
    //cautarea unui elem dupa val

    cout<<"Cautam elemuentul i si afiseaza un mesaj corespunzator"<<endl;
    cin>>i;
    caut_val(i);
    cout<<endl;

    //cautarea unui elem dupa pozitie
    cout<<"Cauta pozitia unui element si afisez un mesaj corespunzator"<<endl;
    cin>>i;
    caut_poz(i);

    cout<<endl;
    //stergerea unui element dupa val


    cout<<"Stergerea elementului dupa valoarea sa";
    cin>>i;
    sterg_val(i);
    afisare();

    //stergerea unui element dupa poz
    cout<<endl;
    cout<<"Stergerea unui element dupa pozitia sa";
    cin>>i;
    sterg_poz(i);
    afisare();

    //sterge list
    sterg();

}
