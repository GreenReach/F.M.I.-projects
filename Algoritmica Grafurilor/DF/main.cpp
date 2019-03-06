#include <iostream>
#include<vector>
#include<fstream>
using namespace std;
ifstream f("graf.in");
int viz[10];
vector<int> v[10],c;

void DF(int i)
{
    cout<<i<<" ";
    viz[i]=1;
    for(int j=0; j<v[i].size(); j++)
    {
        if(viz[v[i][j]]==0)
            DF(v[i][j]);
    }
}

int main()
{
    int n,i,a,b,m,varf;
    f>>n;
    f>>m;


    for(i=0; i<m; i++)
    {
        f>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cout<<"Varful de start: ";
    cin>>varf;
    DF(varf);
}
