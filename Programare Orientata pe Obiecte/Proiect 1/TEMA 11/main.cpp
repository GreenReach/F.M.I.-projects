#include <iostream>
using namespace std;

/**
APOSTU ROBERT
 GRUPA 132

Cerinta. Clasa ”Multime” (multimi finite de numere intregi reprezentate ca tablouri
unidimensionale)
- membri privati pentru vectorul propriuzis si numarul de elemente;
- constructori pentru initializare si copiere;
- destructor (în cazul alocarii statice, se seteaza dimensiunea vectorului la zero,
iar în cazul alocarii dinamice, se dezaloca zona de memorie utilizata);
- metoda publica pentru transformare a unui vector in multime, prin eliminarea
duplicatelor din respectivul vector;
- reuniune a doua multimi, implementata prin supraincarcarea operatorului +;
- intersectie a doua multimi, implementata prin supraincarcarea operatorului *;
- diferenta a doua multimi, implementata prin supraincarcarea operatorului -.
*/


class Multime
{
private:

    int n;
    int *v;

public:

//constructor pentru initializare
    Multime(int m=0)
    {
        n=m;
        v=new int[n];
        int i;

        for(i=0; i<n; i++)
            cin>>v[i];
    }

//constructor pentru copiere
    Multime(Multime *x)
    {
        int i;
        n=x->n;
        v=new int[n];

        for(i=0; i<n; i++)
            v[i]=x->v[i];
    }

//citirea unei multimi
    void citire(int m)
    {
        n=m;
        v=new int[n];
        int i;

        for(i=0; i<n; i++)
            cin>>v[i];
    }

//folosesc metoda pentru a scoate toate elementele ce se repeta dintr-o multime
    void multimititizare()
    {
        int i,j,l;

        for(i=0; i<n-1; i++)
            for(j=i+1; j<n; j++)
                if(v[i]==v[j])
                {
                    for(l=j; l<n-1; l++)
                        swap(v[l],v[l+1]);
                    n--;
                    j--;
                }
    }

//afisarea pe ecran a unei multimi
    void scriere()
    {
        int i;
        for(i=0; i<n; i++)
            cout<<v[i]<<" ";
    }

//reuniunea a doua multimi
    Multime operator+(Multime& x)
    {
        int i;
        Multime a;

        a.n=n+x.n;
        a.v=new int[a.n];

//copiez elementele primei si celei de a doua multimi in a
        for(i=0; i<n; i++)
            a.v[i]=v[i];
        for(i=0; i<x.n; i++)
            a.v[i+n]=x.v[i];

//transform a in multime prin scoaterea elementelor ce se repeta
        a.multimititizare();

        return &a;
    }

//intersectia a 2 multimi
    Multime operator*(Multime& x)
    {
        int i,j,l,ok;
        Multime a;

        a.n=0;
        a.v=new int[n+x.n];

        for(i=0; i<n; i++)
        {
            ok=0;
            for(j=0; j<x.n; j++)
                if(x.v[j]==v[i])//verific daca un element se afla in ambele multimi
                {
                    ok=1;
                    break;
                }

            if(ok==1)//adaug elementul comun in multimea a
            {
                a.v[a.n]=v[i];
                a.n++;
            }
        }

        return &a;

    }

//diferenta a 2 multimi
    Multime operator-(Multime& x)
    {
        Multime a(this);//copiez multimea din care trebuie facuta diferenta in multimea a
        int i,j,l;

        for(i=0; i<a.n; i++)
            for(j=0; j<x.n; j++)
                if(a.v[i]==x.v[j])//verific daca exista elemente ce coincid in cele 2 multimi
                {
                    for(l=i; l<a.n-1; l++) //"sterg" elementele ce coincid
                        swap(a.v[l],a.v[l+1]);

                    a.n--;
                    i--;
                }

        return &a;
    }

//destructor pentru dezalocarea memoriei
    ~Multime()
    {
        delete []v;
    }

};


int main()
{
    Multime *mult;//declar vectorul de obiecte unde voi memora toate multimile
    int nr,n=0,nmax,m;//declar nr=optiunea din meniu aleasa , n=numarul de multimi curent,nmax=numarul maxim de multimi, m=numar de elemente la adaugarea unei noi multimi
    char nume;//declar nume pentru afisarea numelui multimii
    cout<<"Inserati numarul maxim de multimi permise: ";
    cin>>nmax;
    mult=new Multime[nmax];//aloc memorie pentru nmax elemente

    while(1)
    {
        cout<<"[1] Adauga multime "<<endl;
        cout<<"[2] Afiseaza toate multimile "<<endl;
        cout<<"[3] Reuneste 2 multimi "<<endl;
        cout<<"[4] Intersecteaza 2 multimi"<<endl;
        cout<<"[5] Diferenta a 2 multimi"<<endl;
        cout<<"[0] EXIT"<<endl;

        cout<<endl<<"Alegerea dumneavoastra: ";
        cin>>nr;
        cout<<endl<<endl;

        switch(nr)
        {
        case 1:
        {
            if(n<nmax)
            {
                cout<<"Introduceti numarul de elemente: ";
                cin>>m;//citesc numarul de elemente din noua multime
                cout<<"Introduceti "<<m<<" elemente: ";
                mult[n].citire(m);//citesc m elemente
                mult[n].multimititizare();//transform sirul citit intr-o multime
                n++;//cresc numarul actual de multimi
            }
            else
                cout<<"Numarul maxim de multimi a fost atins"<<endl;
            break;
        }


        case 2:
        {
            int i;
            for(i=0; i<n; i++)
            {
                nume=i+65;//creez numele multimi incepand de la litera 'A'
                cout<<nume<<"={ ";
                mult[i].scriere();//scriu multimea
                cout<<"}";
                cout<<endl;
            }
            break;
        }


        case 3:
        {
            Multime reuniune;
//citesc cele 2 multimi ce vor fi reunite ca litera mari de tipar si le "traduc" pentru a afla pozitia lor in vectorul de obiecte
            char a,b;
            int ai,bi;
            cout<<"Scrieti 2 multimi(ex: A B): ";
            cin>>a>>b;
            ai=a-65;
            bi=b-65;
            reuniune=mult[ai]+mult[bi];//supraincarcare operator +
            cout<<"{ ";
            reuniune.scriere();
            cout<<"}";
            cout<<endl;
            break;

        }


        case 4:
        {
            Multime intersectie;
//citesc cele 2 multimi ce vor fi intersectate ca litera mari de tipar si le "traduc" pentru a afla pozitia lor in vectorul de obiecte
            char a,b;
            int ai,bi;
            cout<<"Scrieti 2 multimi(ex: A B): ";
            cin>>a>>b;
            ai=a-65;
            bi=b-65;
            intersectie=mult[ai]*mult[bi];//supraincarcare operator *
            cout<<"{ ";
            intersectie.scriere();
            cout<<"}";
            cout<<endl;
            break;
        }


        case 5:
        {
            Multime diferenta;
//citesc cele 2 multimi din care se va face diferenta ca litera mari de tipar si le "traduc" pentru a afla pozitia lor in vectorul de obiecte
            char a,b;
            int ai,bi;
            cout<<"Scrieti 2 multimi(ex: A B): ";
            cin>>a>>b;
            ai=a-65;
            bi=b-65;
            diferenta=mult[ai]-mult[bi];//supraincarcare operator -
            cout<<"{ ";
            diferenta.scriere();
            cout<<"}";
            cout<<endl;
            break;
        }

//EXIT
        case 0:
        {
            return 0;
            break;
        }

        default:
            cout<<"Selectia dorita nu exista"<<endl;

        }
        cout<<"-------------------------------------------------------------------"<<endl;
    }
}
