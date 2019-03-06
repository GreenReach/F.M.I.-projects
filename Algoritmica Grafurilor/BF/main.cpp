#include <iostream>
#include<vector>
#include<fstream>
#include<queue>
using namespace std;
ifstream f("graf.in");

int main()
{
    int n,*viz,i,a,b,m,varf;
    vector<int> v[100];
    queue<int>c;

    f>>n;
    f>>m;

    viz=new int[n+1];
    for(i=0; i<=n; i++)
        viz[i]=0;

    for(i=0; i<m; i++)
    {
        f>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(i=1; i<=n; i++)
    {
        cout<<i<<"= ";
        for(int j=0; j<v[i].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<"; ";
    }

    cout<<"Varful de start: ";
    cin>>varf;
    viz[varf]=1;
    c.push(varf);
    cout<<varf<<" ";
    while(c.empty()==false)
    {
        a=c.front();
        c.pop();
        cout<<a<<" ";
        for(i=0; i<v[a].size(); i++)
            if(viz[v[a][i]]==0)
            {
                c.push(v[a][i]);
                viz[v[a][i]]=1;
            }
    }
}
