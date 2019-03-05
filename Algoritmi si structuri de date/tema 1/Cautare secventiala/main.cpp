#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");

int main()
{
    int n,i,v[50],a;

    f>>n;
    for(i=0; i<n; i++)
        f>>v[i];

    cin>>a;
    i=0;
    while(v[i]!=a and i!=n)
        i++;

    if(i==n)
        cout<<"NU EXISTA";
    else
        cout<<"DA";
}
