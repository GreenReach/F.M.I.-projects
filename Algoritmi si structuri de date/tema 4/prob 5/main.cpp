#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");

struct frecventa
{

    int valoare,aparitii;

};

int main()
{
    int *v,n,i,j,nr=0,ok=1;
    frecventa *frecv;

    f>>n;
    v=new int[n];
    frecv=new frecventa[n];

    for(i=0; i<n; i++)
    {
        f>>v[i];

        ok=1;
        for(j=0; j<nr; j++)
            if(frecv[j].valoare==v[i])
            {
                frecv[j].aparitii++;
                ok=0;
            }

        if(ok==1)
        {
            frecv[nr].aparitii=1;
            frecv[nr].valoare=v[i];
            nr++;
        }

    }


    for(i=0; i<nr; i++)
        if(frecv[i].aparitii >= n/2+1 )
            cout<<frecv[i].valoare;


}
