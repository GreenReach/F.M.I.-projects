#include <iostream>
#include<string.h>
using namespace std;

/**
Din clasa Nr_Natural_Mare să se deriveze clasa
Se dau urmatoarele clase:
- Vector (int *a)
- Nr_Natural_Mare(int_nrcif, Vector V)
- Numar_Intreg_mare(char semn) : Nr_Natural_Mare
Să se implementeze operatiile uzuale (+,-,*). Clasele derivate trebuie sa
contina constructori parametrizati (prin care sa se evidentieze transmiterea
parametrilor catre constructorul din clasa de baza) si destructori.
*/

class Vector
{

    int *a;

public:

    Vector(int);
    Vector operator=(int b)
    {
        a=new int[b];
    }

    void citire(char nr[100])
    {
        a=new int[strlen(nr)];
        for(int i=0; i<strlen(nr); i++)
        {
            a[i]=(int)nr[i]-'0';
        }
    }

    void scriere(int nrcif,ostream &out)
    {
        for(int i=0; i<nrcif; i++)
        {
            out<<a[i];
        }
    }

    int get_a(int i)
    {
        return a[i];
    }

    int set_a(int i,int nr)
    {
        a[i]=nr;
    }

    int set_lena(int nr)
    {
        a=new int[nr];
    }

    void remake(int nr)
    {
        for(int i=0; i<nr/2; i++)
            swap(a[i],a[nr-1-i]);
    }

    void sterge()
    {
        delete []a;
    }

    ~Vector()
    {
        sterge();
    }

    Vector operator=(const int& n)
    {
        a=new int[n];
    }


};

Vector::Vector(int n=0)
{
    a=new int[n];
}

class Nr_Natural_Mare
{
protected:
    int nrcif;
    Vector v;

public:

    Nr_Natural_Mare();
    Nr_Natural_Mare(int a);
    void citire(char nr[100])
    {
        nrcif=strlen(nr);
        v.citire(nr);
    }

    void scriere(ostream &out)
    {
        v.scriere(nrcif,out);
    }

    int get_nrc()
    {
        return nrcif;
    }

    int get_a(int i)
    {
        return v.get_a(i);
    }

    void set_nr(int nr)
    {
        nrcif=nr;
    }

    void set_a(int i,int nr)
    {
        v.set_a(i,nr);
    }

    void remake()
    {
        v.remake(nrcif);
    }

    friend istream& operator>>(istream & in, Nr_Natural_Mare n)
    {
        int a;
        in>>a;
        n.set_nr(a);
        return in;
    }

    friend ostream& operator<<(ostream& out,Nr_Natural_Mare n)
    {
        out<<n.get_nrc();
        return out;
    }

    void sterge()
    {
        v.sterge();
        nrcif=0;
    }

    ~Nr_Natural_Mare()
    {
        sterge();
    }
};


Nr_Natural_Mare::Nr_Natural_Mare(int a)
{
    nrcif=a;
}

Nr_Natural_Mare::Nr_Natural_Mare()
{
    nrcif=0;
}


class Numar_intreg_mare:public Nr_Natural_Mare
{
    char semn;

public:

    Numar_intreg_mare();
    Numar_intreg_mare(char c);

    friend istream& operator>>(istream &in,Numar_intreg_mare &n)
    {
        in>>n.semn;
        char nr[100];
        in>>nr;
        n.citire(nr);
        return in;
    }

    friend ostream& operator<<(ostream &out,Numar_intreg_mare &n)
    {
        out<<n.semn;
        n.scriere(out);
        return out;

    }

    Numar_intreg_mare operator+( Numar_intreg_mare& n)
    {
        Numar_intreg_mare nr;
        if(semn==n.semn)
        {
            nr.semn=semn;
            if(nrcif>=n.nrcif)
                nr.nrcif=nrcif;
            else
                nr.nrcif=n.nrcif;

            nr.v.set_lena(nr.nrcif+1);
            int i=nrcif-1,j=n.nrcif-1,r=0,s,t=0;
            while(i>=0 && j>=0)
            {
                s=0;
                s=v.get_a(i)+n.v.get_a(j);

                if(r!=0)
                {
                    s++;
                    r=0;
                }
                if(s>=10)
                {
                    r++;
                    s%=10;
                }

                nr.v.set_a(t,s);
                i--;
                j--;
                t++;
            }

            if(nrcif==n.nrcif && r==1)
            {
                nr.nrcif++;
                nr.v.set_a(nr.nrcif-1,1);
            }

            while(i>=0)
            {
                nr.v.set_a(t,v.get_a(i)+r);
                r=0;
                i--;
                t++;
            }

            while(j>=0)
            {
                nr.v.set_a(t,n.v.get_a(j)+r);
                r=0;
                j--;
                t++;
            }
            nr.remake();

        }
        else if(n.semn=='+')
        {
            n.semn='-';
            nr=(*this)-n;
            n.semn='+';
            return nr;
        }
        else
        {
            n.semn='+';
            nr=(*this)-n;
            n.semn='-';
            return nr;
        }

        cout<<nr;
        return nr;
    }

    Numar_intreg_mare operator-(Numar_intreg_mare& n)
    {
        Numar_intreg_mare nr;
        int i;
        if(semn=='+' && n.semn=='-')
        {
            n.semn='+';
            nr=(*this)+n;
            n.semn='-';
            return nr;
        }

        if(semn=='-' && n.semn=='+')
        {
            n.semn='-';
            nr=(*this)+n;
            n.semn='+';
            return nr;
        }

        if(n.nrcif>nrcif)
        {
            nr=n-(*this);
            return nr;
        }

        if(nrcif==n.nrcif)

            for(i=0; i<nrcif; i++)
            {
                if(get_a(i)<n.get_a(i))
                {
                    nr=n-(*this);
                    return nr;
                }
                if(get_a(i)>n.get_a(i))
                    break;
            }

        nr.semn=semn;
        nr.nrcif=nrcif;
        i=nrcif-1;
        int j=n.nrcif-1,r=0,t=0;
        while(j>=0)
        {
            if(r==1)
            {
                nr.set_a(t,get_a(i)-n.get_a(j)-r);
                r=0;
            }
            else
                nr.set_a(t,get_a(i)-n.get_a(j)-r);

            if(nr.get_a(t)<0)
            {
                r=1;
                nr.set_a(t,10+nr.get_a(t));

            }

            t++;
            i--;
            j--;
        }

        while(i>=0)
        {
            if(r==1)
            {
                nr.set_a(t,get_a(i)-1);
                r=0;
            }
            else
                nr.set_a(t,get_a(i));
            i--;
            t++;
        }

        nr.remake();
        int ok=0;
        cout<<nr.semn;
        for(i=0; i<nr.nrcif; i++)
        {
            if(nr.get_a(i)==0 && ok==0)
            {
                ok=0;
            }
            else
            {
                cout<<nr.get_a(i);
                ok=1;
            }
        }

        return nr;
    }


    Numar_intreg_mare operator*(Numar_intreg_mare& n)
    {
        Numar_intreg_mare nr;
        nr.nrcif=nrcif+n.nrcif;
        int i,j,p=0,t,r=0;
        nr.v.set_lena(nr.nrcif);
        if(semn!=n.semn)
            nr.semn='-';
        else
            nr.semn='+';
        for(i=0; i<nr.nrcif; i++)
            nr.set_a(i,0);

        if(nrcif<n.nrcif)
        {
            nr=n*(*this);
            return nr;
        }
        for(i=nrcif-1; i>=0; i--)
        {
            for(j=n.nrcif-1; j>=0; j--)
            {
                t=p;
                nr.set_a(t,get_a(i)*n.get_a(j)+nr.get_a(t)+r);
                r=0;
                if(nr.get_a(t)>9)
                {
                    r=nr.get_a(t)/10;
                    nr.set_a(t,nr.get_a(t)%10);
                }
                t++;
            }

            p++;
        }
        if( r!=0)
            nr.set_a(t,r+nr.get_a(t));

        nr.remake();
        int ok=0;
        cout<<nr.semn;
        for(i=0; i<nr.nrcif; i++)
        {
            if(nr.get_a(i)==0 && ok==0)
            {
                ok=0;
            }
            else
            {
                cout<<nr.get_a(i);
                ok=1;
            }
        }

        return nr;
    }

    virtual void sterge()
    {
        semn=NULL;
    }

    ~Numar_intreg_mare()
    {
        sterge();
    }

};

Numar_intreg_mare::Numar_intreg_mare()
{
    semn='+';
    nrcif=0;
}

Numar_intreg_mare::Numar_intreg_mare(char c)
{
    semn=c;
}

int main()
{
    static int n,a=1,i=0;
    cout<<"Introduceti numarul de elemente maxim: ";
    cin>>n;
    Numar_intreg_mare *v;
    Nr_Natural_Mare nat;
    v=new Numar_intreg_mare[n];

    while(a!=0)
    {
        cout<<"[1] Adaugati un numar"<<endl;
        cout<<"[2] Afisati toate numerele"<<endl;
        cout<<"[3] Adunati 2 numere"<<endl;
        cout<<"[4] Scadeti 2 numere"<<endl;
        cout<<"[5] Inmultitit 2 numere"<<endl;
        cout<<"[0] EXIT"<<endl;

        cout<<"Alegerea dumneavoastra: ";
        cin>>a;

        switch(a)
        {

        case 1:
        {
            if(i!=n)
            {
                cout<<"Introduceti numarul(exemplu: +445, -2544): ";
                cin>>v[i];
                i++;
            }
            else
                cout<<"Numarul maxim de numere a fost atins";
            break;
        }

        case 2:

        {
            for(int j=0; j<i; j++)
            {
                char c='a'+j;
                cout<<c<<" = ";
                cout<<v[j];
                cout<<endl;

            }
            break;
        }


        case 3:
        {
            cout<<"Scrieti 2 numere(exemplu: a b): ";
            char ac,bc;
            cin>>ac>>bc;
            int d,b;
            d=(int)ac-'a';
            b=(int)bc-'a';
            Numar_intreg_mare nr;
            nr=v[d]+v[b];
            break;
        }

        case 4:
        {
            cout<<"Scrieti 2 numere(exemplu: a b): ";
            char ac,bc;
            cin>>ac>>bc;
            int d,b;
            d=(int)ac-'a';
            b=(int)bc-'a';
            Numar_intreg_mare nr;
            nr=v[d]-v[b];
            break;
        }

        case 5:
        {
            cout<<"Scrieti 2 numere(exemplu a b): ";
            char ac,bc;
            cin>>ac>>bc;
            int d,b;
            d=(int)ac-'a';
            b=(int)bc-'a';
            Numar_intreg_mare nr;
            nr=v[d]*v[b];
            break;
        }

        }

        cout<<endl<<endl;

    }

    for(int j=0; j<i; j++)
        v[j].sterge();
    int ok=0;
    for(int j=0; j<i; j++)
    {
        Nr_Natural_Mare *upcast =&v[j];
        if(upcast->get_nrc()!=0)
            ok=1;
    }
    if(ok==1)
        cout<<"STERGEREA A FOST FACUTA CU SUCCES";

}
