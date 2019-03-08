#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
ifstream f("date.in");
vector< pair<int,int> >v;
int n,G;

bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    if( (a.second/a.first) >(b.second/b.first))
        return 1;
    return 0;
}

int main()
{
    pair<int,int> a;

    f>>n>>G;
    for(int i=0; i<n; i++)
    {
        f>>a.first>>a.second;
        v.push_back(a);
    }

    sort(v.begin(),v.end(),cmp);

    int m=-1,g=0;
    for(int i=0; i<n; i++)
    {
        if(g+v[i].first<=G)
        {
            m++;
            g+=v[i].first;
        }
    }

    for(int i=0; i<=m; i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;
}
