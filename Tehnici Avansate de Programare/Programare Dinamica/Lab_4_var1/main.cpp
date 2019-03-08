#include <iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
ifstream f("date.in");
vector<int> *v,curent[2];
int n,k;


void citeste()
{
    int i,j;
    int a,n1;
    f>>n>>k;

    v=new vector<int>[n];


    for(i=0; i<n; i++)
    {
        f>>n1;
        for(j=0; j<n1; j++)
        {
            f>>a;
            v[i].push_back(a);
        }

    }

    for(i=0; i<n; i++)
        curent[0].push_back(0);

}

void rezolva()
{
    int i,j,c,s,l;

    for(i=0; i<=k; i++)
    {

        for(j=0; j<n; j++)
            if(curent[j]<curent[mi])
                curent[j]=mi
                          for(j=0; j<n; j++)
                {
                    c=1000;
                    for(l=0; l<v[j].size(); l++)
                    {
                        if(v[j][l]>curent[j] && v[j][l]<c)
                        {

                            c=v[j][l];
                        }


                    }
                    curent[j]=c;
                }
        s=0;
        for(j=0; j<n; j++)
        {
            cout<<curent[j]<<",";
            s+=curent[j];
        }
        cout<<endl;

        if(s==k)
        {
            for(j=0; j<n; j++)
                cout<<curent[j]<<" ";
            break;
        }

    }
}

int main()
{
    citeste();

    rezolva();
}
