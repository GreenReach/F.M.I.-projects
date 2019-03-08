#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");
int *nrM,n;

int nrMinim(int n)
{
    int n1,n2,n3;

    if(n==1)
        return 0;
    else
    {
        nrM[n-1]=n1=nrMinim(n-1);
        if(n%2==0)
            n2=nrM[n/2]=nrMinim(n/2);

        if(n%3==0)
            n2=nrM[n/3]=nrMinim(n/3);

        return 1+ min(min(n1,n2),n3);
    }
}

int main()
{
    f>>n;
    nrM=new int[n];
    cout<<nrMinim(n);

}
