#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");

void heapmax(int v[200], int n, int i)
{
    int maxim=i,l=2*i+1,r=2*i+2;

    if(l<n && (v[l]>v[maxim]))
        maxim=l;

    if (r<n && (v[r]>v[maxim]))
        maxim=r;

    if (maxim!=i)
    {
        swap(v[i],v[maxim]);
        heapmax(v,n,maxim);
    }
}


void heap(int v[200],int n)
{
    int i;

    for (i=n/2-1; i>=0; i--)
        heapmax(v,n,i);

    for (i=n-1; i>=0; i--)
    {
        swap(v[0],v[i]);
        heapmax(v,i,0);
    }
}


int main()
{
    int n,v[200];

    f>>n;

    for(int i=0; i<n; i++)
        f>>v[i];

    heap(v, n);

    cout<<"Vectorul sortat: ";
    for (int i=0; i<n; ++i)
        cout <<v[i]<<" ";
}
