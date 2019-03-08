#include <iostream>
#include<fstream>
#include<math.h>
using namespace std;
ifstream f("date.in");
int **v,n,nr=1;

void citeste()
{
    f>>n;
    n=pow(2,n);
    v=new int*[n];
    for(int i=0;i<n;i++)
        v[i]=new int[i];
}

void make(int L,int i,int j)
{
    if(L==1)
    {
        v[i][j]=nr;
        nr++;
    }
    else
    {
        L/=2;
        make(L,i,j+L);
        make(L,i+L,j);
        make(L,i,j);
        make(L,i+L,j+L);
    }
}

void afis()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<v[i][j]<<" ";
    cout<<endl;
    }

}

int main()
{
   citeste();
   make(n,0,0);
   afis();
}
