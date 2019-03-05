#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream cin("date.in");
    int n,i,j,v[50],l,r,m;

    cin>>n;
    for(i=0; i<n; i++)
        cin>>v[i];

//bouble sort
    for(i=0; i<n-1; i++)
        for( j=n-1; j>i; j--)
            if(v[j-1]>v[j])
                swap(v[j-1],v[j]);


    cin>>j;
    l=0;
    r=n;
    m=(l+r)/2;
    while(r-l>1 and v[m]!=j)
    {
        if(v[m]>j)
            r=m;
        else
            l=m;
        m=(r+l)/2;
    }

    if(v[m]==j)
        cout<<"DA";
    else
        cout<<"NU";

}
