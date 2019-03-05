#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");

void form_A(int v[64][64],int i,int j)
{
    v[i][j]=1;
    v[i][j+1]=1;
    v[i+1][j]=1;
}

void form_B(int v[64][64],int i,int j)
{
    v[i][j]=2;
    v[i][j-1]=2;
    v[i+1][j]=2;
}

void form_C(int v[64][64],int i,int j)
{
    v[i][j]=3;
    v[i-1][j]=3;
    v[i][j-1]=3;
}

void form_D(int v[64][64],int i,int j)
{
    v[i][j]=4;
    v[i-1][j]=4;
    v[i][j+1]=4;
}


void acopera(int rt, int ct, int rl, int cl,int lungime, int v[64][64])
{

    int ro=lungime/2 + rt ;
    int co=lungime/2 + ct ;

    if(ro>rl && co>cl)
        form_C(v,ro,co);
    else if(ro>rl && co<=cl)
        form_D(v,ro,co-1);
    else if(ro<=rl && co<=cl)
        form_A(v,ro-1,co-1);
    else if(ro<=rl && co>cl)
        form_B(v,ro-1,co);

    if(lungime>2)
    {
        if(ro>rl && co>cl)
            acopera(rt,ct,rl,cl,lungime/2,v);
        else
            acopera(rt,ct,(lungime/2)-1 +rt,(lungime/2)-1 +ct,lungime/2,v);

        if(ro>rl && co<=cl)
            acopera(rt,lungime/2 + ct,rl,cl,lungime/2,v);
        else
            acopera(rt,lungime/2 + ct,(lungime/2)-1 + rt,lungime/2 + ct,lungime/2,v);

        if(ro<=rl && co>cl)
            acopera(lungime/2 + rt,ct,rl,cl,lungime/2,v);
        else
            acopera(lungime/2 + rt,ct,lungime/2 + rt,(lungime/2)-1 + ct,lungime/2,v);

        if(ro<=rl && co<=cl)
            acopera(lungime/2 + rt,lungime/2 + ct,rl,cl,lungime/2,v);
        else
            acopera(lungime/2 + rt,lungime/2 + ct,lungime/2 + rt,lungime/2 + ct,lungime/2,v);
    }
}

int main()
{
    int k,v[64][64],i,n=1,j,cl,rl;
    f>>k;
    f>>rl>>cl;

    for(i=0; i<k; i++)
        n*=2;

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            v[i][j]=0;

    v[rl][cl]=5;

    acopera(0,0,rl,cl,n,v);

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }

}
