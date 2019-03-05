#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");

int main()
{
    int i,j,v[50],n,curent;
    f>>n;
    for(i=0; i<n; i++)
        f>>v[i];


    for(i=1; i<n; i++)
        if(v[i]<v[i-1])
        {
            curent=v[i];
            j=i;
            while(j>0 && v[j-1]>curent)
            {
                v[j]=v[j-1];
                j--;
            }
            v[j]=curent;

        }

    for(i=0; i<n; i++)
        cout<<v[i]<<" ";
}



