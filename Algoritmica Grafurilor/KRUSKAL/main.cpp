#include <iostream>
#include<fstream>
#include<vector>
using namespace std;
ifstream f("graf.in");
vector<int> graf_sort[3];
vector<int> k[100];
int *reprez,n,m;

void umple(int a,int b)
{
    int i;
    for(i=1; i<=n; i++)
        if(reprez[i]==b)
            reprez[i]=a;
}


int main()
{
    int a,b,i,c,j;
    f>>n>>m;
    reprez=new int[n+1];

    for(i=0; i<m; i++)
    {
        f>>a>>b>>c;
        graf_sort[0].push_back(a);
        graf_sort[1].push_back(b);
        graf_sort[2].push_back(c);
    }

    for(i=1; i<=n; i++)
        reprez[i]=i;

    for(i=0; i<m-1; i++)
        for(j=i+1; j<m; j++)
        {
            if(graf_sort[2][i]>graf_sort[2][j])
            {
                swap(graf_sort[1][i],graf_sort[1][j]);
                swap(graf_sort[2][i],graf_sort[2][j]);
                swap(graf_sort[0][i],graf_sort[0][j]);
            }
        }

    for(i=0; i<m; i++)
    {
        if(reprez[graf_sort[0][i]]!=reprez[graf_sort[1][i]])
        {
            umple(reprez[graf_sort[0][i]],reprez[graf_sort[1][i]]);
            int x=graf_sort[0][i],y=graf_sort[1][i];

            k[x].push_back(y);
            k[y].push_back(x);
        }
    }

    for(i=1; i<=n; i++)
    {
        cout<<i<<" = ";
        for(j=0; j<k[i].size(); j++)
            cout<<k[i][j]<<" ";
        cout<<endl;
    }

}
