#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");

void mergesort(int v[50],int jos,int sus)
{
    if(sus-jos>1)
    {
        mergesort(v,jos,(jos+sus)/2);
        mergesort(v,(jos+sus)/2,sus);
    }

    int i,j,k,st[25],dr[25];

    for(i=jos; i<(jos+sus)/2; i++)
        st[i]=v[i];

    for(i=(jos+sus)/2; i<sus; i++)
        dr[i]=v[i];

    i=jos;
    j=(jos+sus)/2;
    k=jos;

    while(i < (sus+jos)/2 && j <sus)
    {
        if(st[i]<dr[j])
        {
            v[k]=st[i];
            i++;
        }
        else
        {
            v[k]=dr[j];
            j++;
        }

        k++;
    }

    while (i < (sus+jos)/2)
    {
        v[k] = st[i];
        i++;
        k++;
    }

    while (j < sus)
    {
        v[k] = dr[j];
        j++;
        k++;
    }

}

int main()
{
    int v[50],i,j,n;
    f>>n;

    for(i=0; i<n; i++)
        f>>v[i];

    mergesort(v,0,n);

    for(i=0; i<n; i++)
        cout<<v[i]<<" ";
}
