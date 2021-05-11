#include <iostream>
#include <sstream>

using namespace std;

class pracownik
{
protected:
    int Id;
    string imie;
    string nazwisko;
    string wydzial;
    string adres_wydzialu;
    string tel_wydzialu;
    string* info;
public:
    static int ile;
    pracownik(string im ="", string na="", string w="", string aw="", string tel="")
        :imie(im), nazwisko(na), wydzial(w), adres_wydzialu(aw), tel_wydzialu(tel) 
        {
            Id=++ile;
            info = new string;
        }

    void setInfo(string inf){*info = inf;}

    pracownik(pracownik & wzor, string im, string naz)
    {
        imie = im;
        nazwisko = naz;
        wydzial = wzor.wydzial;
        adres_wydzialu = wzor.adres_wydzialu;
        tel_wydzialu = wzor.tel_wydzialu;
    }

    string toString()
    {
        stringstream temp;
        temp<<Id<<" "
            <<nazwisko<<" "<<imie
            <<" ["<<wydzial<<", "<<adres_wydzialu<<" tel: "<<tel_wydzialu<<"]"
            <<"Informacje:"<<*info;
            return temp.str();
    }

    ~pracownik()
    {
        delete info;
    }
};

pracownik wydzialy[] = {
    pracownik("","","Mechaniczny","Malczewskiego 20","48360321"),
    pracownik("","","Transpotru","Malczewskieho 28","281234566"),
    pracownik("","","Filologiczno-Pedagogiczny", "Chrobrego 20","12345566")
};

int pracownik::ile = 0;
int main()
{
    pracownik::ile=0; // resetujemy numerację Id
    pracownik* pracownicy[10];

    pracownicy[0] =  new pracownik(wydzialy[0],"Jan","Kowalski");
    pracownicy[1] =  new pracownik(wydzialy[2],"Jan","Nowak");
    pracownicy[2] =  new pracownik(wydzialy[1],"Anna","Kowalska");

    for (int i=0;i<3;i++)
      cout<< pracownicy[i]->toString()<<endl;


    return 0;
}