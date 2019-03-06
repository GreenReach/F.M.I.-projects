#include <iostream>
#include<fstream>
#include<vector>
using namespace std;
ifstream f("graf.in");
vector<int> *graf;
int *lg,*nn,n;//lista graf si nume nod

int sortare()
{
    int i,j;
    for(i=1; i<n; i++)
        for(j=i+1; j<=n; j++)
            if(lg[i]<lg[j])
            {
                swap(lg[i],lg[j]);
                swap(nn[i],nn[j]);
            }

    int nod=0;
    for(i=1; i<=n; i++)
        if(lg[i]==0)
            nod++;
    return nod;
}

void HAVEL_HAKIMI()
{
    int nod=sortare();
    if(nod==n) return;
    if(nod==n-1)
    {
        cout<<"NEREALIZABIL";
        return;
    }
    int a=nn[1];
    int j=2;
    for(int i=0; i<lg[1]; i++)
    {
        graf[a].push_back(nn[j]);
        graf[nn[j]].push_back(a);
        lg[j]--;
        j++;
    }
    lg[1]=0;
    HAVEL_HAKIMI();
}

int main()
{
    int i,j,s=0;
    f>>n;
    graf=new vector<int>[n+1];
    lg=new int[n+1];
    nn=new int[n+1];
    for(i=1; i<=n; i++)
    {
        f>>lg[i];
        nn[i]=i;
        s+=lg[i];
        if(lg[i]>=n)
        {
            cout<<"NEREALIZABIL";
            return 0;
        }
    }

    if(s%2==1)
    {
        cout<<"NEREALIZABIL";
        return 0;
    }

    HAVEL_HAKIMI();

    for(i=1; i<=n; i++)
    {
        cout<<i<<" = ";
        for(j=0; j<graf[i].size(); j++)
            cout<<graf[i][j]<<" ";
        cout<<endl;
    }
}
