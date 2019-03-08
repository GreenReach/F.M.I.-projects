#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
ifstream f("date.in");
vector< pair<int,int> > v,S;
int n,p;

void citire()
{
    f>>n>>p;
    pair<int, int> a;

    for(int i=0; i<n; i++)
    {
        f>>a.first>>a.second;
        v.push_back(a);
    }
}

bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
    if(a.first>b.first)
        return 1;
    else if(a.first<b.first)
        return 0;
    else if(a.second>b.second)
        return 1;
    return 0;
}

int main()
{
    citire();
    sort(v.begin(),v.end(),cmp);
    int i,h=0;
    S.push_back(v[0]);
    h+=v[0].first;

    for(i=1; i<v.size(); i++)
        if(v[i].second!=S[S.size()-1].second && v[i].first!=S[S.size()-1].first)
        {
            S.push_back(v[i]);
            h+=v[i].first;
        }

    cout<<h<<endl;
    for(i=0; i<S.size(); i++)
        cout<<S[i].first<<" ";
}
