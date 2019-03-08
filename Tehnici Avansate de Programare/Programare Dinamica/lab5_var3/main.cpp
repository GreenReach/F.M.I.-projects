#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");
int **v,**R,n,m;


void citire()
{
    f>>n>>m;
    v=new int*[n];
    R=new int*[n];

    for(int i=0; i<n; i++)
    {
        v[i]=new int[m];
        R[i]=new int[m];
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            f>>v[i][j];

}


int main()
{
    citire();

    int i,j;


    for(i=n-1; i>=0; i--)
        for(j=m-1; j>=0; j--)
        {
            if(v[i][j]==0)
                if( i==n-1 || j==m-1 )
                    R[i][j]=1;
                else if( R[i+1][j]==R[i][j+1]&& R[i][j+1]==R[i+1][j+1] && v[i][j]==0)
                    R[i][j]=1+R[i+1][j];
                else
                    R[i][j]=min( min(R[i][j+1],R[i+1][j]), R[i+1][j+1] )+1;
            else
                R[i][j]=0;
        }


    int ci=0,cj=0,AMax=R[0][0];
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if(R[i][j]>AMax)
            {
                ci=i;
                cj=j;
                AMax=R[i][j];
            }

    cout<<ci<<" "<<cj<<endl<<AMax<<endl;

    int k,sum=0;
    f>>k;

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
        {
            if(R[i][j]==k)
                sum++;
            if(R[i][j]>k)
                sum+=R[i][j]-k+1;
        }

    cout<<sum;

}
