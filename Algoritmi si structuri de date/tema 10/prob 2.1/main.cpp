#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");

int conex(int v[50][50],int n,int ns)
{
    int prim, ultim, c[20]={0}, a[20]={0}, i, nr=0;
    a[ns]=1;

    cout<<ns<<" ";
    prim=ultim=1;
    c[ultim]=ns;

    while(prim<=ultim)
    {
        for( i=1; i<=n; i++)
            if(v[c[prim]][i]==1)
            {
                v[c[prim]][i]=v[c[prim]][0]=0;

                if(a[i]==0)
                {
                    nr++;
                    ultim++;
                    c[ultim]=i;
                    cout<<i<<" ";
                    a[i]=1;
                }
            }

        prim++;
    }
    cout<<endl;
    return nr;
}

int main()
{
    int i,j,v[50][50]= {0},n;
    f>>n;
    while(f>>i>>j)
        v[i][j]=v[j][i]=1;

    for(i=1; i<=n; i++)
        conex(v,n,i);

}
