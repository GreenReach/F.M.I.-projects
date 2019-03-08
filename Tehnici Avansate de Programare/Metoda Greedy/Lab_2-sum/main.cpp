#include <iostream>
#include<fstream>
#include<algorithm>
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

void rasp()
{
    int i=0,j=n-1,last=v[j]+1;

    while(i<j)
    {
        while(v[j]==last && v[i]==-last)
        {
            i++;
            j--;
        }
        if(v[i]+v[j]==0)
        {
            cout<<v[i]<<" "<<v[j]<<endl;
            last=v[j];
            i++;
            j--;

        }
        else if(v[i]+v[j]<0)
            i++;

        else if(v[i]+v[j]>0)
            j--;


    }
}

int main()
{
    citire();
    rasp();
}
