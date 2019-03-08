#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
ifstream f("date.in");
vector< pair<int,int> > v,r;
int n;

bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
    if(a.second<b.second)
        return 1;
    if( a.second== b.second && a.first<b.first)
        return 1;
    return 0;
}

void citire()
{
    pair<int,int> a;
    f>>n;
    for(int i=0; i<n; i++)
    {
        f>>a.first>>a.second;
        v.push_back(a);
    }
}

void scriere(vector< pair<int,int> >v)
{

    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;
}

void raspuns()
{
    int ultim=v[0].second;
    r.push_back(v[0]);

    for(int i=1; i<n; i++)
        if(v[i].first>=ultim)
        {
            r.push_back(v[i]);
            ultim=v[i].second;
        }

}



int main()
{
    citire();
    sort(v.begin(),v.end(),cmp);
    raspuns();
    scriere(r);
}
