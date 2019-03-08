#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
vector< pair<int,float> > v;
ifstream f("date.in");
int n;

void citeste()
{
    f>>n;
    int a;
    for(int i=0; i<n; i++)
    {
        f>>a;
        v.push_back(make_pair(a,0));
    }
    for(int i=0; i<n; i++)
        f>>v[i].second;

}

bool cmp(const pair<int,float> &a, const pair<int,float> &b)
{
    if(a.second>b.second)
        return 0;
    return 1;
}

int mediana()
{
    sort(v.begin(),v.end(),cmp);
    float s=v[0].second;
    int i=0;
    while(s<0.5)
    {
        i++;
        s+=v[i].second;
    }
    return v[i].first;
}

int main()
{
    citeste();
    cout<<mediana();
}
