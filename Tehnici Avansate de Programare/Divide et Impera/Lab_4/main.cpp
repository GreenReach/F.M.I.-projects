#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");

struct nod
{
    int val;
    nod *st,*dr;
};

nod *tree,*a,*b;
int *preordine,*postordine,*inordine1,*postordine1,*inordine,n,*poz;
int i=0;

void citeste()
{
    f>>n;

    for(int i=0; i<n; i++)
        f>>postordine[i];

    for(int i=0; i<n; i++)
        f>>inordine[i];
}

void umple(int nr)
{
    for(int i=0; i<n; i++)
        if(inordine[i]==nr)
            poz[nr]=i;

}

void make_tree()
{
    for(int i=n-2; i>=0; i--)
    {
        umple(postordine[i]);
        a=tree;

        while(a->val!=-1)
        {
            if(poz[postordine[i]] > poz[a->val])
                a=a->dr;
            else
                a=a->st;
        }
        a->val=postordine[i];
        a->st=new nod;
        a->dr=new nod;
        a->st->val=-1;
        a->dr->val=-1;
    }
}

void ppreordine(nod *p)
{
    if(p->val!=-1)
    {
        cout<<p->val<<" ";
        ppreordine(p->st);
        ppreordine(p->dr);
    }
}

int iinordien(nod *p)
{
    if(p->val!=-1)
    {
        iinordien(p->st);
        inordine1[i]=p->val;
        i++;
        iinordien(p->dr);
    }
    return 0;
}

int ppostordine(nod *p)
{
    if(p->val!=-1)
    {
        ppostordine(p->st);
        ppostordine(p->dr);
        postordine1[i]=p->val;
        i++;
    }
}

int main()
{
    preordine=new int[n];
    postordine=new int[n];
    inordine=new int[n];
    postordine1=new int[n];
    inordine1=new int[n];
    poz=new int[n];

    citeste();

    tree=new nod;
    tree->val=postordine[n-1];
    a=tree;
    a->st=new nod;
    a->dr=new nod;
    a->st->val=-1;
    a->dr->val=-1;
    umple(postordine[n-1]);

    make_tree();

    i=0;
    iinordien(tree);

    i=0;
    ppostordine(tree);

    for(int i=0; i<n; i++)
        if(inordine1[i]!=inordine[i] || postordine1[i]!=postordine[i])
        {
            cout<<"NU";
            return 0;
        }

    ppreordine(tree);
    cout<<endl;

    for(int i=0; i<n; i++)
        cout<<inordine1[i]<<" ";

    cout<<endl;

    for(int i=0; i<n; i++)
        cout<<postordine1[i]<<" ";
}
