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

/*
Model date de intrare din fisierul "date.in"
rand 1 - numar nonterminali
rand 2 - lista nonterminali
rand 3 - numar alfabet
rand 4 - lista alfabet
rand 5 - numar productii
rand 6 - productii
obs: nonterminalul de start trebuie notat cu "S"
*/

class nod
{
public:
    vector<string>lista_prod ;
    string cuv;
    nod *fii;

    //creez lista de productii dezvoltand fiecare nonterminal cu fiecare productie a sa si adaugand toate cuvintele formate intr-un vector 
    void creeaza_list()
    {
        int i,j,lit_cur=0,nr;
        char c;
        
        //Parcurg cuvantul cautand nonterminalii
        for(i=0; i<cuv.size(); i++)
        {
            if(isupper(cuv[i]))
            {
                lit_cur++;
                c=cuv[i];
                
                //daca un nonterminal a fost gasit caut indexul sau in lista de nonterminali
                for(j=0; j<n; j++)
                {
                    if(nonterminali[j]==c)
                    {
                        nr=j;
                        break;
                    }
                }
                
                //creez cuvinte prin dezvoltarea nonterminalului gasit pentru fiecare productie a sa din lista de productii
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

    //verifica daca un cuvant apartine limbajului
    int acceptor()
    {
        //elimin toate cuvintele vide din cuvantul curent 
        for(int u=0; u<cuv.size(); u++)
            if(cuv[u]=='0')
            {
                cuv.erase(u,1);
                u--;
            }
        //daca cuvantul actual este identic cu cel initial atunci el este acceptat 
        if(cuv.compare(cuvant)==0)
            return 1;
        else if(cuv.size()>cuvant.size())
            //daca cuvantul este mai mare atunci cautarea pe ramura curenta se opreste
            //cand toate cautarile se opresc si cuvantul nu a fost acceotat atunci acesta nu apartine limbajului
            return 0;
        else
        {
            //creez lista de cuvinte noi si atribui fiecarui nou cuvant un nod in arbore ca si fiu al cuvantului actual 
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

    //Citesc nonterminalii intr-un vector si creez vectroul de tranzitii
    f>>n;
    productii=new vector<string>[n];
    nonterminali=new char[n];
    for(i=0; i<n; i++)
        f>>nonterminali[i];

    //citesc terminalii intr-un vector
    f>>m;
    terminali=new char[m];
    for(i=0; i<m; i++)
        f>>terminali[i];

    //citesc tranzitiile in vectroul deja creat
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
    
    //verific petntru cazul null
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
        //creez primul nod din arbore cu nonterminalul de start 
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
