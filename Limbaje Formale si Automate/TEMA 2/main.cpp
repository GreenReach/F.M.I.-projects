#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<string.h>
#include<ctype.h>
using namespace std;
ifstream f("date.in");
vector<string> *productii;
string cuvant;
char *nonterminali,*terminali;
int n,m;

//rand 1 - numar nonterminali
//rand 2 - lista nonterminali
//rand 3 - numar alfabet
//rand 4 - lista alfabet
//rand 5 - numar productii
//rand 6 - productii...

class nod
{
public:
    vector<string>lista_prod ;
    string cuv;
    nod *fii;

    void creeaza_list()
    {
        int i,j,lit_cur=0,nr;
        char c;
        for(i=0; i<cuv.size(); i++)
        {
            if(isupper(cuv[i]))
            {
                lit_cur++;
                c=cuv[i];
                for(j=0; j<n; j++)
                {
                    if(nonterminali[j]==c)
                    {
                        nr=j;
                        break;
                    }
                }

                for(j=0; j<productii[nr].size(); j++)
                {
                    string cuv2;
                    cuv2.assign(cuv);
                    cuv2.erase(i,1);
                    cuv2.insert(i,productii[nr][j]);
                    lista_prod.push_back(cuv2);
                }
            }
        }
    }

    int acceptor()
    {
        for(int u=0; u<cuv.size(); u++)
            if(cuv[u]=='0')
            {
                cuv.erase(u,1);
                u--;
            }
        if(cuv.compare(cuvant)==0)
            return 1;
        else if(cuv.size()>cuvant.size())
            return 0;
        else
        {
            creeaza_list();
            fii=new nod[lista_prod.size()];
            for(int i=0; i<lista_prod.size(); i++)
            {
                fii[i].cuv.assign(lista_prod[i]);
                if(fii[i].acceptor()==1)
                    return 1;
            }

        }

        return 0;
    }

};

int main()
{
    int i,j,nr;
    char c,d[10];

    f>>n;
    productii=new vector<string>[n];
    nonterminali=new char[n];
    for(i=0; i<n; i++)
        f>>nonterminali[i];

    f>>m;
    terminali=new char[m];
    for(i=0; i<m; i++)
        f>>terminali[i];

    f>>nr;
    for(i=0; i<nr; i++)
    {
        f>>c;
        f>>d;
        for(j=0; j<n; j++)
            if(nonterminali[j]==c)
                productii[j].push_back(d);
    }

    cin>>cuvant;

   

    if(cuvant.compare("0")==0)
    {
        int ok=0;
        for(i=0; i<productii[0].size(); i++)
            if(productii[0][i].compare("0")==0)
            {
                cout<<"DA";
                ok=1;
            }
        if(ok==0)
            cout<<"NU";

    }
    else
    { 
        for(int u=0; u<cuvant.size(); u++)
        if(cuvant[u]=='0')
        {
            cuvant.erase(u,1);
            u--;
        }
        nod start;
        start.cuv='S';
        if(start.acceptor()==1)
            cout<<"DA";
        else
            cout<<"NU";
    }
}
