#include <iostream>
#include <fstream>
#include<cstdlib>
using namespace std;
ifstream f("date.in");

void quickSort(int v[50],int st,int dr)
{
    int i=st,j=dr,tmp;
    int pivot=rand() % (dr-st+1) + st ;

    while (i<=j)
    {
        while (v[i]<pivot)
            i++;
        while (v[j]>pivot)
            j--;
        if (i <= j)
        {
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }

    if (st<j)
        quickSort(v,st,j);

    if (i<dr)
        quickSort(v,i,dr);

}

int main()
{
    int v[50],n,i;
    f>>n;

    for(i=0; i<n; i++)
        f>>v[i];

    quickSort(v,0,n-1);

    for(i=0; i<n; i++)
        cout<<v[i]<<" ";

}
