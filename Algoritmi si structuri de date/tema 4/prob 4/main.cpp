#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");
struct nod_coloana

{
    int info,coloana;
    nod_coloana *next_col;
};

struct nod_linie
{
    int linie;
    nod_coloana *next_col;
    nod_linie *next_lin;
};

nod_linie *prim,*curentl,*ajutorl;
nod_coloana *curentc,*ajutorc,*primc;


int coloana(int m)
{
    int i,ok=0,val,primulc=0;

    for(i=0; i<m; i++)
    {
        f>>val;
        if(val!=0)
        {
            ok=1;
            if(primulc==0)
            {
                primc=new nod_coloana;
                primulc=1;
                curentc=primc;
            }

            curentc->info=val;
            curentc->coloana=i;
            ajutorc=new nod_coloana;
            curentc->next_col=ajutorc;
            curentc=ajutorc;
            curentc->next_col=NULL;
        }

    }
    return ok;
}


int main()
{
    int i,j,n,m,val;
    f>>n>>m;

    prim=new nod_linie;
    curentl=prim;
    curentc=new nod_coloana;
    prim->next_col=curentc;

    for(i=0; i<n; i++)
    {
        if(coloana(m)==1)
        {
            ajutorl=new nod_linie;
            curentl->next_lin=ajutorl;
            curentl->linie=i;
            curentl->next_col=primc;
            curentl=ajutorl;
            curentl->next_lin=NULL;
        }

    }

    curentl=prim;
    curentc=curentl->next_col;

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            if(curentl->linie==i && curentc->coloana==j)
            {
                cout<<curentc->info<<" ";
                if(curentc->next_col==NULL)
                {
                    curentl=curentl->next_lin;
                    curentc=curentl->next_col;
                }
                else
                    curentc=curentc->next_col;
            }
            else
                cout<<"0 ";
        cout<<endl;
    }
}
