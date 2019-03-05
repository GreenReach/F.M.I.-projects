#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");

void conex(int v[50][50],int n,int first,int curent,int nod[50],int ni)
{
    int i,j;
    for(i=0; i<n; i++)
        if(v[curent][i]==1)
        {
            v[curent][i]=0;
            nod[ni]=i+1;
            ni++;

            if(i==first)
            {
                for(j=0; j<ni-1; j++)
                    cout<<nod[j]<<" ";
                cout<<endl;
            }
            else if(i!=curent)
                conex(v,n,first,i,nod,ni);
        }
}

int main()
{
    int v[50][50]= {0},i,j,l,n,m,nod[50],ni;

    f>>n>>m;
    for(l=0; l<n; l++)
    {
        f>>i>>j;
        v[i][j]=v[j][i]=1;
    }

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(v[i][j]==1)
            {
                nod[0]=i+1;
                ni=1;
                v[i][j]=v[j][i]=0;
                conex(v,n,i,j,nod,ni);
            }

}
