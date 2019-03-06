#include <iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;
ifstream f("graf.in");

int main()
{
    int n,m,*viz,*tata,i,j,a,b,d,ok=0;
    vector<int> *v;
    queue<int> *c;
    f>>n>>m;
    v=new vector<int>[n+1];
    c=new queue<int>[n+1];
    viz=new int[n+1];
    tata=new int[n+1];

    for(i=1; i<=n; i++)
    {
        viz[i]=0;
        tata[i]=-1;
    }

    for(i=0; i<m; i++)
    {
        f>>a>>b;
        v[b].push_back(a);
    }

    tata[1]=0;
    c->push(1);
    viz[1]=1;
    while(c->empty()==false)
    {
        a=c->front();
        c->pop();
        viz[a]=1;
        for(i=0; i<v[a].size(); i++)
            if(viz[v[a][i]]==0)
            {
                tata[v[a][i]]=a;
                viz[v[a][i]]=1;
                c->push(v[a][i]);
            }

    }


    for(i=1; i<=n; i++)
        for(j=0; j<v[i].size(); j++)
        {
            a=i;
            b=v[i][j];
            while(tata[a]!=0)
            {
                if(b==tata[a])
                {
                    ok=1;
                    d=i;
                    while(d!=b)
                    {
                        cout<<d<<" ";
                        d=tata[d];
                    }
                    cout<<d;
                }
                a=tata[a];
            }

        }

    if(ok==0)
        cout<<"NEREALIZABIL";

}
