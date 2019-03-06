#include <iostream>
#include<fstream>
#include<vector>
using namespace std;
ifstream f("graf.in");
vector<int> *graf;
int *viz,*niv_min,*nivel;

void DF(int i)
{
    viz[i]=1;
    niv_min[i]=nivel[i];
    for(int j=0; j<graf[i].size(); j++)
    {
        int nod=graf[i][j];
        if(viz[nod]==0)
        {
            nivel[nod]=nivel[i]+1;
            DF(nod);
            if(niv_min[i]>niv_min[nod])
                niv_min[i]=niv_min[nod];
            if(niv_min[nod]>nivel[i])
                cout<<i<<nod<<" ";
        }
        else if( nivel[nod] < nivel[i]-1 && niv_min[i] > nivel[nod])
            niv_min[i]=nivel[nod];

    }
}

int main()
{
    int n,m,a,b,i;
    f>>n>>m;
    graf=new vector<int>[n+1];
    viz=new int[n+1];
    niv_min=new int[n+1];
    nivel=new int[n+1];

    for(i=0; i<m; i++)
    {
        f>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    for(i=1; i<=n; i++)
        viz[i]=0;

    nivel[1]=1;
    niv_min[1]=1;
    DF(1);

}
