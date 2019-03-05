#include <iostream>
#include <fstream>
using namespace std;
fstream f("date.in");

struct nod
{
    int cheie,prioritate;
    nod *next;
};

nod *prim,*curent,*ajutor,*ultim,*ajutor2;

void sterg()
{
    int x;
    cout<<endl<<"ELEMENTUL CE TREBUIE STERS ";
    cin>>x;

    if(prim->cheie==x)
        prim=prim->next;
    else
    {
        ajutor=prim->next;
        ajutor2=prim;

        while(ajutor->cheie!=x && ajutor->next!=NULL)
        {
            ajutor=ajutor->next;
            ajutor2=ajutor2->next;
        }

        if(ajutor->next==NULL)
            cout<<"ELEMENTUL NU APARE IN LISTA";
        else
            ajutor2->next=ajutor->next;
    }

    curent=prim;
    while(curent->next!=NULL)
    {
        cout<<curent->cheie<<"("<<curent->prioritate<<") ";
        curent=curent->next;
    }

}

void adaug(int n)
{
    cout<<endl<<"CHEIA SI PRIORITATEA ELEMENTULUI: ";
    curent=new nod;
    cin>>curent->cheie;
    cin>>curent->prioritate;

    if(curent->prioritate<prim->prioritate)
    {
        curent->next=prim;
        prim=curent;
    }
    else
    {
        ajutor=prim->next;
        ajutor2=prim;

        while(ajutor->prioritate<=curent->prioritate && ajutor->next!=NULL)
        {
            ajutor=ajutor->next;
            ajutor2=ajutor2->next;
        }


        if(ajutor->next==NULL)
        {
            ajutor2->next=curent;
            curent->next=ajutor;
            ultim=curent;
        }
        else
        {
            ajutor2->next=curent;
            curent->next=ajutor;
        }
    }

    curent=prim;
    while(curent->next!=NULL)
    {
        cout<<curent->cheie<<"("<<curent->prioritate<<") ";
        curent=curent->next;
    }
}

int main()
{
    int i,n;
    prim=new nod;

    f>>n;
    f>>prim->cheie;
    f>>prim->prioritate;

    ultim=new nod;
    ultim->next=NULL;
    prim->next=ultim;
    ultim=prim;

    for(i=1; i<n; i++)
    {
        curent=new nod;
        f>>curent->cheie;
        f>>curent->prioritate;

        if(curent->prioritate<prim->prioritate)
        {
            curent->next=prim;
            prim=curent;
        }
        else
        {
            ajutor=prim->next;
            ajutor2=prim;

            while(ajutor->prioritate<=curent->prioritate && ajutor->next!=NULL)
            {
                ajutor=ajutor->next;
                ajutor2=ajutor2->next;
            }


            if(ajutor->next==NULL)
            {
                ajutor2->next=curent;
                curent->next=ajutor;
                ultim=curent;
            }
            else
            {
                ajutor2->next=curent;
                curent->next=ajutor;
            }
        }
    }

    curent=prim;
    while(curent->next!=NULL)
    {
        cout<<curent->cheie<<"("<<curent->prioritate<<") ";
        curent=curent->next;
    }

    sterg();
    adaug(n);

}
