#include <iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
ifstream f("date.in");

/**

La realizarea unui film(nume,tip,durata), participa o mulțime de
persoane: un regizor, actori, personal tehnic etc. Dacă filmul este bun,
atunci el ruleaza într-un numar de cinematografe și realizeaza incasari
substantiale pe fiecare cinematogram în parte. Fiecare personal (cnp,
nume, nume_film) are prevăzut prin contract un procent din incasari, drept
urmare primește, pentru fiecare film la care participa, o anumita suma.
Actorii, dacă sunt personaje principale, primesc un bonus de 10% din
incasari, iar regizorul are prevăzut și o suma fixa, indiferent de calitatea
filmului produs.

Cerinta suplimentara:

- Sa se construiasca clasa template FirmaDistributie care sa conțină
informații despre filmele realizate într-un an. Clasa conțina numărul total
de persoane implicat incrementat automat), numărul de actori
(incrementat automat) și un vector de persoane alocat dinamic.
- Sa se construiasca o specializare a acestei clase pentru un tip de data
la alegere care sa conțină numărul actorilor care au fost distribuiti în
roluri principale.

*/

class Personal
{

    string nume;
    string prenume;
    int procent_incasari;
    int salariu;
    string titlu;
    string CNP;

public:

    Personal(int s=0,int p=0)
    {
        salariu=s;
        procent_incasari=p;
    }
    virtual ~Personal()
    {
        procent_incasari=0;
    }

    Personal operator=(Personal& a)
    {
        nume=a.nume;
        prenume=a.prenume;
        procent_incasari=a.procent_incasari;
        salariu=a.salariu;
        titlu=a.titlu;
        CNP=a.CNP;
    }


    friend ifstream& operator>>(ifstream& in,Personal& p)
    {
        in>>p.nume;
        in>>p.prenume;
        in>>p.CNP;
        in>>p.titlu;

        if(p.titlu.compare("Director")==0)
        {
            in>>p.salariu;
            in>>p.procent_incasari;
        }
        else
        {
            in>>p.procent_incasari;
        }

        return in;
    }



    friend ostream& operator<<(ostream& out,Personal& p)
    {
        out<<p.titlu<<": "<<p.prenume<<" "<<p.nume<<endl;
        out<<"CNP: "<<p.CNP<<endl;

        try
        {
            if(p.CNP.size()!=13)
                throw 0;
        }
        catch(int x)
        {
            cout<<"EROARE ... CNP INCORECT"<<endl;
        }

        out<<"Salariu: "<<p.salariu<<" $"<<endl;
        return out;

    }



    void payday(int n)
    {
        if(titlu.compare("Director")!=0)
            salariu=(n*procent_incasari)/100;
        else
            salariu+=(n*procent_incasari)/100;
        if(titlu.compare("ActorPrincipal")==0)
            salariu+=n/10;
    }


    string get_titlu()
    {
        return titlu;
    }
    void static_check()
    {
        cout<<endl<<"Prin acest mesaj se verifica folosirea single_cast-ului"<<endl;
    }
    void dynamic_check()
    {
        cout<<endl<<"Prin acest mesaj se ferifica folosirea dynamic_cast-ului"<<endl;
    }

};



class Film:public Personal
{

    string nume;
    string gen;
    int nr_cinema;
    vector<int>incasari_cinema;
    int incasari_total;
    int nr_personal;
    Personal *p;
    int durata;

public:

    Film(int nrc=0, int d=0, int nrp=0)
    {
        nr_cinema=nrc;
        nr_personal=nrp;
        durata=d;
    }
    ~Film()
    {
        incasari_cinema.empty();
    }

    void make_it_rain()
    {
        int i;
        for(i=0; i<nr_personal; i++)
            p[i].payday(incasari_total);
    }

    Film operator=(Film a)
    {
        nume=a.nume;
        gen=a.gen;
        nr_cinema=a.nr_cinema;
        incasari_cinema=a.incasari_cinema;
        incasari_cinema=a.incasari_cinema;
        nr_personal=a.nr_personal;
        durata=a.durata;
        for(int i=0; i<nr_personal; i++)
            p[i]=a.p[i];

    }

    friend ifstream& operator>>(ifstream& in,Film& a)
    {
        getline(in,a.nume);
        getline(in,a.gen);
        in>>a.durata;

        in>>a.nr_personal;
        a.p=new Personal[a.nr_personal];
        for(int i=0; i<a.nr_personal; i++)
        {
            in>>a.p[i];
        }


        in>>a.nr_cinema;
        int s;
        a.incasari_total=0;
        for(int i=0; i<a.nr_cinema; i++)
        {
            in>>s;
            a.incasari_cinema.push_back(s);
            a.incasari_total+=s;
        }

        return in;
    }


    void citeste()
    {
        f>>*this;
        make_it_rain();
    }



    friend ostream& operator<<(ostream& out,Film& fi)
    {
        out<<fi.nume<<endl;
        out<<"Gen: "<<fi.gen<<endl<<"Durata: "<<fi.durata<<endl;
        out<<"Box Office: "<<fi.incasari_total<<" $"<<endl<<endl<<"  DISTRIBUTIE"<<endl<<endl;
        for(int i=0; i<fi.nr_personal; i++)
        {
            out<<fi.p[i];
            cout<<endl;
        }
        cout<<"--------------------------------------------------------";
        return out;
    }

    int get_nr_personal()
    {
        return nr_personal;
    }

    int numara_actori()
    {
        string test;
        int nr=0;
        for(int i=0; i<nr_personal; i++)
        {
            test=p[i].get_titlu();
            if(test.compare("ActorPrincipal")==0)
                nr++;
        }

        return nr;

    }

};

template <class T>
class FirmaDistributie
{
    T *filme;
    int nr,an;
    int nr_pers;
    int nr_actoriPrin;

public:

    FirmaDistributie(int a,int n)
    {
        an=a;
        nr=n;
        filme=new T[nr];
        nr_pers=0;
        nr_actoriPrin=0;
    }


    friend ifstream& operator>>(ifstream& in,FirmaDistributie& fd)
    {
        for(int i=0; i<fd.nr; i++)
        {
            fd.filme[i].citeste();
            fd.nr_pers+=fd.filme[i].get_nr_personal();
        }
        return in;

    }


    friend ostream& operator<<(ostream& of,FirmaDistributie& fd)
    {
        of<<"ANUL ";
        of<<fd.an;
        of<<endl;
        of<<endl;
        for(int i=0; i<fd.nr; i++)
        {
            of<<fd.filme[i];
            cout<<endl;
            fd.nr_actoriPrin+=fd.filme[i].numara_actori();
        }

        of<<endl;
        of<<"Numar total de persoane inplicate: ";
        of<<fd.nr_pers;
        of<<endl;
        of<<"Numar de actori principali: ";
        of<<fd.nr_actoriPrin;
        of<<endl;
        return of;
    }


};

int main()
{
    int a,b;
    f>>a>>b;
    FirmaDistributie<Film> fi(a,b);
    f>>fi;
    cout<<fi;

    Film *fs;
    Personal *ps;

    fs = static_cast<Film*>(ps);
    fs->static_check();

    Film *pd=new Film;
    Personal* fd=dynamic_cast<Personal*>(pd);
    fd->dynamic_check();


}
