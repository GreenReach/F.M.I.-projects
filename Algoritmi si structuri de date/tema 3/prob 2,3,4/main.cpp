#include <iostream>
#include<fstream>
#include<math.h>
using namespace std;
ifstream f("date.in");

struct pol
{
    int gr,coef;
    pol *next;
};

pol *primP,*curentP,*ajutorP,*primQ,*curentQ,*ajutorQ,*prim,*curent,*ajutor;

void afisP()
{
    curentP=primP;
    while(curentP->next!=NULL)
    {
        cout<<curentP->coef<<"x^"<<curentP->gr;
        ajutorP=curentP->next;
        if(ajutorP->next!=NULL)
            cout<<"+";
        curentP=curentP->next;
    }
}

void afisQ()
{
    curentQ=primQ;
    while(curentQ->next!=NULL)
    {
        cout<<curentQ->coef<<"x^"<<curentQ->gr;
        ajutorQ=curentQ->next;
        if(ajutorQ->next!=NULL)
            cout<<"+";
        curentQ=curentQ->next;
    }
}

void adunare_scalar(int x)
{
    curentP=primP;
    cout<<"POLINOMUL P:";
    while(curentP->next!=NULL)
    {
        cout<<curentP->coef*x<<"x^"<<curentP->gr;
        ajutorP=curentP->next;
        if(ajutorP->next!=NULL)
            cout<<"+";
        curentP=curentP->next;
    }
    cout<<endl;

    curentQ=primQ;
    cout<<"POLINOMUL Q:";
    while(curentQ->next!=NULL)
    {
        cout<<curentQ->coef*x<<"x^"<<curentQ->gr;
        ajutorQ=curentQ->next;
        if(ajutorQ->next!=NULL)
            cout<<"+";
        curentQ=curentQ->next;
    }
    cout<<endl;
}

void punct(int x)
{
    int suma=0;
    curentP=primP;
    while(curentP->next!=NULL)
    {
        suma+=curentP->coef*pow(x,curentP->gr);
        curentP=curentP->next;
    }
    cout<<suma<<endl;

}

void suma()
{
    curentP=primP;
    curentQ=primQ;
    while(curentP->next!=NULL || curentQ->next!=NULL)
    {
        if(curentP->gr==curentQ->gr)
        {
            cout<<curentP->coef+curentQ->coef<<"X^"<<curentP->gr<<"+";
            curentP=curentP->next;
            curentQ=curentQ->next;
        }

        if(curentP->gr>curentQ->gr)
        {
            cout<<curentP->coef<<"X^"<<curentP->gr<<"+";
            curentP=curentP->next;
        }
        if(curentP->gr<curentQ->gr)
        {
            cout<<curentQ->coef<<"X^"<<curentQ->gr<<"+";
            curentQ=curentQ->next;
        }

    }
    cout<<endl;
}


int main()
{
    int n,m,i,x;
    f>>n>>m;
    primP=new pol;
    curentP=primP;
    for(i=0; i<=n; i++)
    {
        f>>x;
        if(x!=0)
        {
            curentP->coef=x;
            curentP->gr=n-i;
            ajutorP=new pol;
            curentP->next=ajutorP;
            curentP=ajutorP;
        }
    }
    curentP->next=NULL;

    primQ=new pol;
    curentQ=primQ;
    for(i=0; i<=m; i++)
    {
        f>>x;
        if(x!=0)
        {
            curentQ->coef=x;
            curentQ->gr=m-i;
            ajutorQ=new pol;
            curentQ->next=ajutorQ;
            curentQ=ajutorQ;
        }
    }
    curentQ->next=NULL;


    cout<<"Inmultirea polinoamelor P si Q cu scalarul:";
    cin>>x;
    if(x==0)
        cout<<"Ambele polinoame devin 0";
    else
        adunare_scalar(x);

    cout<<"Inserati X0:";
    cin>>x;
    punct(x);

    cout<<"Suma polinoamelor P si Q este: ";
    suma();

}
