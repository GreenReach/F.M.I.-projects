#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");
int *v,n,s;

void citire()
{
    f>>n;
    n--;
    v=new int[n];

    for(int i=0; i<n; i++)
        f>>v[i];

    f>>s;
}


int main()
{
    citire();

    cout<<"Schimb "<<s<<":"<<endl;
    int x;

    for(int i=n-1; i>=0; i--)
    {
        int x= s/v[i] ;
        if(x!=0)
        {
            cout<<x<<" monede de "<<v[i]<<endl;
            s-=x* v[i];
        }
    }
}
