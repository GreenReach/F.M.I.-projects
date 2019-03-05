#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");

void recur(int v[20][20],int i,int j,int nr)
{
    v[i][j]=nr;

    if(i>1 && v[i-1][j]==1)
        recur(v,i-1,j,nr);
    if(v[i+1][j]==1)
        recur(v,i+1,j,nr);
    if(j>1 && v[i][j-1]==1)
        recur(v,i,j-1,nr);
    if(v[i][j+1]==1)
        recur(v,i,j+1,nr);
}

int main()
{
    int m,v[20][20],i,j,nr=2;
    f>>m;

    for(i=1; i<=m; i++)
        for(j=1; j<=m; j++)
            f>>v[i][j];

    for(i=1; i<=m; i++)
        for(j=1; j<=m; j++)
            if(v[i][j]==1)
            {
                recur(v,i,j,nr);
                nr++;
            }


    for(i=1; i<=m; i++)
    {
        for(j=1; j<=m; j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }


}
