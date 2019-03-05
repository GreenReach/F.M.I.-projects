#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");

void servire(int n, int v[100])
{
    int i;
    for(i=1; i<n; i++)
        v[i]=v[i+1];
}

void sosire(int n, int v[100],int nr)
{
    v[n+1]=nr;
}

void inbrancire(int n,int v[100])
{
    int nr,i,j;
    f>>nr;

    for(i=1; i<=n; i++)
        if(v[i]==nr)
        {
            for(j=i; j>1; j--)
                swap(v[j],v[j-1]);
            break;
        }
}

int main()
{
    int v[100],n,k,i,j,op,nr;
    f>>n;
    f>>k;
    nr=n+1;

    for(i=1; i<=n; i++)
        v[i]=i;

    for(i=0; i<k; i++)
    {
        f>>op;
        switch(op)
        {

            case 1:
            {
                servire(n,v);
                n--;
                break;
            }
            case 2:
            {
                sosire(n,v,nr);
                nr++;
                n++;
                break;
            }
            case 3:
            {
                inbrancire(n,v);
                break;
            }

        }
    }

    g<<n<<endl;
    for(i=1; i<=n; i++)
        g<<v[i]<<" ";
}
