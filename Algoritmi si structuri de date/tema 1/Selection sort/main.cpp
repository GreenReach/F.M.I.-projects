#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
int main()
{
    int n,i,j,v[50],mini=0,curent;
    f>>n;
    for(i=0; i<n; i++)
        f>>v[i];

    while(mini<n)
    {
        curent=mini;

        for(i=mini; i<n; i++)
            if(v[curent]>v[i])
                curent=i;

        swap(v[curent],v[mini]);
        mini++;
    }

    for(i=0; i<n; i++)
        cout<<v[i]<<" ";

}
