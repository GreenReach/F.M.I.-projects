#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");
int **S,**T;
int n,m;

void citeste()
{
    f>>n>>m;
    S=new int*[n];
    T=new int*[n];

    int i,j;
    for( i=0; i<n; i++)
    {
        S[i]=new int[m];
        T[i]=new int[m];
    }

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            f>>T[i][j];

}

void make_S()
{
    int i,j;

    for(i=n-1; i>=0; i--)
        for(j=m-1; j>=0; j--)
        {
            if(i==n-1 && j==m-1)
                S[i][j]=T[i][j];
            else if(i==n-1 && j!=m-1)
                S[i][j]=T[i][j]+S[i][j+1];
            else if(i!=n-1 && j==m-1)
                S[i][j]=T[i][j]+S[i+1][j];
            else
                S[i][j]=T[i][j]+max(S[i][j+1],S[i+1][j]);

        }
}

int traseu(int i,int j)
{
    cout<<i<<" "<<j<<endl;
    if(i==n-1 && j==n-1)
    {
        return 0;
    }
    else if(i==n-1 && j!=m-1)
        return traseu(i,j+1);
    else if(i!=n-1 && j==m-1)
        return traseu(i+1,j);
    else if(S[i][j]==S[i+1][j]+T[i][j])
        return traseu(i+1,j);
    else
        return traseu(i,j+1);
}

int main()
{
    citeste();
    make_S();

    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            cout<<S[i][j]<<" ";
        cout<<endl;

    }

    cout<<endl;
    traseu(0,0);
}
