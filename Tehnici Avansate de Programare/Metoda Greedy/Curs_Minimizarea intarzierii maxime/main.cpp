#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
ifstream f("date.in");
vector< pair<int,int> > v;
int n;

void citire()
{
    f>>n;
    pair<int, int> a;
    for(int i=0; i<n; i++)
    {
        f>>a.first>>a.second;
        v.push_back(a);
    }
}

bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.second>b.second)
        return 1;
    else if(a.second<b.second)
        return 0;
    else if(a.first>b.first)
        return 1;
    return 0;
}

int main()
{
    citire();

    sort(v.begin(), v.end(), cmp);
    int h=0,hMax=0;

    for(int i=0; i<v.size(); i++)
    {
        cout<<"activitatea "<<v[i].first<<": intervalul "<<h<<" ";
        h+=v[i].first;
        cout<<h<<" intarziere ";
        if(h>v[i].first)
        {
            cout<<h-v[i].first;
            hMax+=h-v[i].first;
        }
        cout<<endl;
    }

    cout<<hMax;
}
