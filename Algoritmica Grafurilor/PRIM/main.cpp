#include <iostream>
#include<fstream>
#include<vector>
using namespace std;
ifstream f("graf.in");
vector< pair<int,int> > *graf;
vector<int> *g;
int *tata,*d,n,m,*viz;

void PRIM(int nod)
{
    int i,j,dmin=d[graf[nod][0].first],nmin=graf[nod][0].first;
    viz[nod]=1;

    for(i=0; i<graf[nod].size(); i++)
    {
        if(viz[graf[nod][i].first]==0)
        {
            if(d[graf[nod][i].first]>graf[nod][i].second )
            {
                d[graf[nod][i].first]=graf[nod][i].second;
                tata[graf[nod][i].first]=nod;
            }
            if(d[graf[nod][i].first]<dmin)
            {
                dmin=d[graf[nod][i].first];
                nmin=graf[nod][i].first;
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        if(d[i]<d[nmin] && viz[i]==0)
            nmin=i;
    }

    if(viz[nmin]==0)
        PRIM(nmin);

}



int main()
{
    int i,j,a,b,c;
    f>>n>>m;
    graf=new vector< pair<int,int> >[n+1];
    g=new vector<int>[n+1];
    tata=new int[n+1];
    d=new int[n+1];
    viz=new int[n+1];

    for(i=0; i<m; i++)
    {
        f>>a>>b>>c;
        graf[a].push_back(make_pair(b,c));
        graf[b].push_back(make_pair(a,c));
    }

    for(i=1; i<=n; i++)
    {
        d[i]=1000;
        viz[i]=0;
    }

    d[1]=0;
    tata[1]=0;
    viz[1]=1;
    PRIM(1);
    for(i=1; i<=n; i++)
        cout<<tata[i]<<" ";
}
