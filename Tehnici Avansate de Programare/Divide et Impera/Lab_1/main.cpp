#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");
int *v,n;

void citire()
{
    f>>n;
    v=new int[n];
    for(int i=0; i<n; i++)
        f>>v[i];
}

int varf(int st,int dr)
{
    int mij=(st+dr)/2;
    if(mij==st || mij==dr)
        return v[mij];

    if(v[mij]>v[mij-1] && v[mij]>v[mij+1])
        return v[mij];

    if(v[mij]<v[mij-1])
        return varf(st,mij);
    else
        return varf(mij,dr);
}

int main()
{
    citire();
    cout<<varf(0,n-1);
}
