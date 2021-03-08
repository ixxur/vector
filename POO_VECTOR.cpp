#include <iostream>
#include <stdlib.h>
using namespace std;

class Vector
{
     ///Date membre private
private:

    int n;   ///n = nr de elemente dintr-un vector
    int* v;  ///v = vectorul

   ///Metode publice
public:
    Vector();               ///Constructor de initializare fara parametrii
    Vector(int, int);       ///Constructor de initiatlizare cu parametrii
    Vector(Vector&);        ///Constructor de copiere
    ~Vector();              ///Destructor
    void citire(istream &in);         ///Metoda ppentru citire
    void afisare(ostream &out);       ///Metoda pentru aisare
    friend istream& operator>>(istream &in, Vector& );  ///supraincarcare pe >>
    friend ostream& operator<<(ostream &out, Vector& );  ///supraincarcare pe <<
    Vector& operator = (Vector& );          ///Metoda pentru atribuire
    void reactualizare (int, int);          ///Metoda pentru reactualizarea valorilor
    int suma();                             ///Metoda pentru calcularea sumei
    void maxim();                           ///Metoda pentru gasirea maximului si a pozitiei lui
    void sortare();                         ///Metoda pentru sortarea crescatoare a unui vector
   // void set_n() {int};
   // void set_v(){int};
   // int get_n(){return n;};
   // int get_v(int& n){for (int i = 0; i<n; i++)return v[i];}

};


///Constructor de initializare fara parametrii
Vector::Vector()
{
    this->n = 0;
    this->v = new int[n];
}

///Constructor de initializare cu parametrii
Vector::Vector(int nr_elem, int nr)  ///nr_elem = numarul de elemente ale vector; nr = valoarea cu care se initializeaza componentele vectorului
{
    n = nr_elem;
    v = new int[n];
    for (int i=0; i<n; i++)
       v[i] = nr;
}

///Constructor de copiere
Vector::Vector(Vector& vec)  ///Se copiaza in vectorul v datele din vectorul vec
{
    this->n = vec.n;
    this->v = new int [this->n];
    for (int i=0; i<this->n; i++)
        this->v[i] = vec.v[i];
}

///Destructor
Vector::~Vector()
{
   this->n = 0;
   delete []v;
}


///Supraincarcare >>
istream& operator>>(istream &in, Vector& vec)
{
   vec.citire(in);
   return in;
}

///Supraincarcare <<
ostream& operator<<(ostream &out, Vector& vec)
{
    vec.afisare(out);
    return out;
}

///Metoda pentru atribuire
Vector& Vector::operator= (Vector& vec)
{
    n = vec.n;
    for(int i = 0; i<n; i++)
        v[i] = vec.v[i];
}

///Metoda pentru citire
void Vector::citire(istream& in)
{
    cout<<"Dati numarul de elemente ale noului vector: ";
    in>>n;                                            ///Se citeste nr de elemente
    v= new int[n];                                    ///Se aloca memorie dinamic
    cout<<"Completati vectorul cu valori: ";
    for(int i=0; i<n; i++)
        in>>v[i];                                     ///Se citesc elementele vectorului
        cout<<endl;

}

///Metoda pentru afisare
void Vector::afisare(ostream& out)
{
    for(int i=0; i<n; i++)
        out<<v[i]<<" ";
}

///Metoda pentru reactualizarea unui vector
void Vector::reactualizare(int nr_nou, int nr_elem)    ///nr_nou = valoarea cu  care se initializeaza toate elementele vectorului;
{                                                      ///nr_elem = nr de elemente pentru care vectorul isi va realoca memorie
    n = nr_elem;
    v = new int[n];
    for (int i = 0; i<n; i++)
        v[i] = nr_nou;

}

///Metoda pentru suma componentelor unui vector
int Vector::suma()
{
    int S = 0;
    for(int i=0; i<n; i++)
        S = S + v[i];
        return S;
}

///Metoda pentru gasirea maximului dintr-un vector, cat si pozitia acestuia
void Vector::maxim()
{
    int maxi = v[0];
    int poz = 0;
    for(int i = 1; i<n; i++)
        if(maxi < v[i])
        {
            maxi = v[i];
            poz  = i;
        }
    cout<<"Maximul este: ";
    cout<<maxi;
    cout<<endl;
    cout<<"Pozitia maximului este: ";
    cout<<poz;
}

///Metoda pentru sortarea in ordine crescatoare a elementelor unui vector
void Vector::sortare()
{
for (int i=0; i<n-1; i++)
    for(int j = i+1; j<n; j++)
       if(v[i]>v[j])
{
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}
for(int i = 0; i<n; i++)
    cout<<v[i]<<" ";
}

///Afisarea meniului in consola
void menu_output()
{
    cout<<endl<<"OPREA ANA-MARIA-RUXANDRA"<<endl;
    cout<<"\n Manipularea vectorilor utilizand poo \n";
    cout<<"\n\t MENIU";
    cout<<endl<<"======================================================================"<<endl<<endl;
    cout<<"1. Adaugati vectori"<<endl;
    cout<<"2. Afisati vectori"<<endl;
    cout<<"3. Reactualizati numarul de elemente dintr-un vector si initializati componentele acestuia cu un numar dat"<<endl;
    cout<<"4. Calculati suma componentelor unui vector"<<endl;
    cout<<"5. Gasiti maximul si pozitia acestuia dintr-un vector"<<endl;
    cout<<"6. Sortati crescator un vector"<<endl;
    cout<<"0. Abort mission"<<endl;
    cout<<endl;
}

///Functie pentru adaugarea de noi obiecte in clasa
void add_vector(Vector** vec, int* nrelem)
{
    Vector* aux;
    int nrnou;
    cout<<"Introduceti numarul de noi vectori: ";
    cin>>nrnou;
    cout<<endl;

    aux = new Vector[*nrelem + nrnou];   ///Ne folosim de un obiect auxiliar caruia ii alocam memorie pentru vectorii deja existenti, cat si pentru cei care urmeaza sa fie adaugati
    for(int i = 0; i<*nrelem; i++)
        aux[i] = (*vec)[i];              ///Copiem valorile deja existene in aux
    for(int i = *nrelem; i< *nrelem+nrnou; i++)
     cin>>aux[i];                        ///Adaugam valorile noi pana la final
     *nrelem = *nrelem + nrnou;          ///Reactualizam nr de elemente al obiectului
     *vec = new Vector [*nrelem];        ///Realocam memorie suficienta pentru obiectul initial
    for(int i=0; i<*nrelem; i++)
        (*vec)[i] = aux[i];              ///Completam obiectul cu valorile din aux
    delete []aux;                        ///Dezalocam memoria folosita de aux deoarece nu mai avem nevoie de el

}


void menu()
{
    int option;
    option = 0;
    int nrelem = 0;
    Vector* vec;

    do
    {
        menu_output();

        cout<<endl<<"Introduceti numarul actiunii: ";
        cin>>option;
        cout<<endl;

        if(option == 1)
        {
           add_vector(&vec, &nrelem);
        }

        if(option == 2)
        {
            for(int i = 0; i<nrelem; i++)
               {
                   cout<<"Vectorul "<<i<<": ";
                   cout<<vec[i]<<" ";
                   cout<<endl;
               }
        }

        if(option == 3)
        {   int x, nr_elem, nr_nou;
            cout<<"Alegeti vectorul pe care doriti sa il reactualizati "<<endl;
             for(int i = 0; i<nrelem; i++)
               {
                   cout<<"Vectorul "<<i<<": ";
                   cout<<vec[i]<<" ";
                   cout<<endl;
                }
            cin>>x;       /// x = locul vectorului din sirul de vectori de la 0 la nr de vectori -1
            cout<<"Reactualizati numarul de elemente: ";
            cin>>nr_elem;
            cout<<"Initializati componentele vectorului cu o valoare: ";
            cin>>nr_nou;
            vec[x].reactualizare(nr_nou,  nr_elem);
            cout<<"Vectorul "<<x<<": "<<vec[x];
        }



        if(option == 4)
        {
          int x;
          for(int i = 0; i<nrelem; i++)
               {
                   cout<<"Vectorul "<<i<<": ";
                   cout<<vec[i]<<" ";
                   cout<<endl;
                }
          cout<<"Doriti sa calculati suma vectorului: ";

          cin>>x;         /// x = locul vectorului din sirul de vectori de la 0 la nr de vectori-1
                cout<<endl<<"Suma este: "<<vec[x].suma();

        }

        if(option == 5)
        {
            int x;
            for(int i = 0; i<nrelem; i++)
               {
                   cout<<"Vectorul "<<i<<": ";
                   cout<<vec[i]<<" ";
                   cout<<endl;
                }
            cout<<"Doriti sa gasiti maximul din vectorul: ";

            cin>>x;         /// x = locul vectorului din sirul de vectori de la 0 la nr de vectori-1
            cout<<endl;
                   vec[x].maxim();
        }

        if(option == 6)
        {
            int x;
            for(int i = 0; i<nrelem; i++)
               {
                   cout<<"Vectorul "<<i<<": ";
                   cout<<vec[i]<<" ";
                   cout<<endl;
                }
            cout<<"Ordonati crescator vectorul: ";

            cin>>x;         /// x = locul vectorului din sirul de vectori de la 0 la nr de vectori-1
            cout<<endl<<"Vectorul "<<x<<":  ";
            vec[x].sortare();

        }

        if(option == 0)
        {
            cout<<endl<<"EXIT"<<endl;

        }
        if(option < 0 || option  > 6)
        {
            cout<<endl<<"Selectie invalida"<<endl;
        }
        cout<<endl;
        system("pause");
        system("cls");
    }
    while(option!=0);
}
int main()
{
    menu();

 return 0;

}
