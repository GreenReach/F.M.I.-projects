#include <iostream>
#include<fstream>
using namespace std;
ifstream f("test.in");

int main()
{
    int n,i,j,v[50];

    f>>n;
    for(i=0; i<n; i++)
        f>>v[i];


    for(i=0; i<n-1; i++)
        for( j=n-1; j>i; j--)
            if(v[j-1]>v[j])
                swap(v[j-1],v[j]);

    for(i=0; i<n; i++)
        cout<<v[i]<<" ";
}
