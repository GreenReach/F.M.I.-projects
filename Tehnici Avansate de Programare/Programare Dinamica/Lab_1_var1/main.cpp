#include <iostream>
#include<fstream>
#include<vector>
using namespace std;
ifstream f("date.in");
vector< pair<int,int> > v,*subsir;
int n;

void citire()
{
    f>>n;
    subsir=new vector< pair<int,int> >[n];

    pair<int,int> a;

    for(int i=0; i<n; i++)
    {
        f>>a.first>>a.second;
        v.push_back(a);
    }
}

void make_subsir()
{
    int i,j;
    subsir[n-1].push_back(v[n-1]);
    for(i=n-2; i>=0; i--)
    {
        subsir[i].push_back(v[i]);
        for(j=i+1; j<n; j++)
        {
            if(subsir[j].size()+1>subsir[i].size() && v[i].second==v[j].first)
            {
                subsir[i].clear();
                subsir[i].push_back(v[i]);
                for(int k=0; k<subsir[j].size(); k++)
                    subsir[i].push_back(subsir[j][k]);
            }
        }

    }

}

int punctul_b(int nr_max)
{
    nr_max++;
    int i,maxi=subsir[0].size(),poz1=0;

    for(i=1; i<n; i++)
        if(maxi<subsir[i].size())
        {
            maxi=subsir[i].size();
            poz1=i;
        }

    for(i=n-1; i<=0; i--)
        if(v[i].first==subsir[poz1][subsir[poz1].size()-1].first &&  v[i].second==subsir[poz1][subsir[poz1].size()-1].second)
        {
            v.erase(v.begin()+i);
            break;
        }


    for(i=0; i<n; i++)
        subsir[i].clear();


    n-=1;
    make_subsir();


    int maxi1=subsir[0].size(),poz2=0;

    for(i=1; i<n; i++)
        if(maxi1<subsir[i].size())
        {
            maxi1=subsir[i].size();
            poz2=i;
        }

    if(maxi1==maxi)
        punctul_b(nr_max);
    else
        return nr_max;

}


int main()
{
    citire();
    make_subsir();
    int i,maxi=subsir[0].size(),poz1=0;

    for(i=1; i<n; i++)
        if(maxi<subsir[i].size())
        {
            maxi=subsir[i].size();
            poz1=i;
        }

    for(i=0; i<subsir[poz1].size(); i++)
        cout<<subsir[poz1][i].first<<" "<<subsir[poz1][i].second<<endl;
    cout<<endl;

    cout<<punctul_b(0);
}
