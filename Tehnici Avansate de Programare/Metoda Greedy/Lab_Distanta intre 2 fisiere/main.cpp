#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
ifstream f("date1.in");
ifstream g("date2.in");
vector< pair<string,int> > v1,v2;

void citeste(ifstream& f, vector< pair<string,int> > &v)
{
    int i,ok;
    string a;
    pair<string,int> x;
    while(f>>a)
    {
        ok=0;

        for(i=0; i<v.size(); i++)
            if( a.compare( v[i].first ) == 0)
            {
                v[i].second++;
                ok=1;
            }

        if(ok==0)
        {
            x.first=a;
            x.second=1;
            v.push_back(x);
        }

    }
}
float raspuns()
{
    int i,j,sum=0;
    double r1=0,r2=0,rasp;

    for(i=0; i<v1.size(); i++)
        r1+=v1[i].second*v1[i].second;
    r1=sqrt(r1);

    for(i=0; i<v2.size(); i++)
        r2+=v2[i].second*v2[i].second;
    r2=sqrt(r2);

    for(i=0; i<v1.size(); i++)
        for(j=0; j<v2.size(); j++)
        {
            if(v1[i].first.compare(v2[j].first)==0)
                sum+=v1[i].second * v2[j].second;
        }

    rasp=sum/(r1*r2);
    return rasp;
}

int main()
{
    citeste(f,v1);
    citeste(g,v2);
    cout<<raspuns();
}
