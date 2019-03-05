#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");

void grad(int v[50][50],int n)
{
    int x,i,nr=0;
    cout<<"Scrieti numarul nodului: ";
    cin>>x;
    x--;

    for(i=0; i<n; i++)
        if(v[x][i]==1)
            nr++;

    cout<<"Nodul "<<x+1<<" are gradul "<<nr<<endl<<endl;

}

void nrMuchii(int v[50][50],int n)
{
    int nr=0,i,j;

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            nr+=v[i][j];

    cout<<"Graful are "<<nr/2<<" muchii"<<endl<<endl;
}

void GradMax(int v[50][50],int n)
{
    int nr[100]= {0},i,j,maxi=0;

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            nr[i]+=v[i][j];

    for(i=0; i<n; i++)
        if(nr[i]>maxi)
            maxi=i;


    if(maxi==0)
        cout<<"Toate nodurile au gradul 0";
    else
    {
        cout<<"Nodul/nodurile cu gradul maxim este/sunt: ";
        for(i=0; i<n; i++)
            if(nr[i]==maxi)
                cout<<i+1<<" ";
    }
    cout<<endl<<endl;

}

int main()
{
    int v[50][50],n,i,j;
    f>>n;

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            f>>v[i][j];

    grad(v,n);
    nrMuchii(v,n);
    GradMax(v,n);
}
