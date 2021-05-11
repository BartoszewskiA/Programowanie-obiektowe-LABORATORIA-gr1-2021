#include <iostream>
#include <ctime>
#include <conio.h>
#include <fstream>

using namespace std;

class liczba
{
private:
    int x;
    int Id;
    time_t utworzenie;
    void zapisz_czas(int akcja);

public:
    static int ile;
    static time_t czas_start;
    liczba(int liczba = 0) : x(liczba)
    {
        Id = ++ile;
        zapisz_czas(1);
    }
    ~liczba() { zapisz_czas(0); }
    int getLiczba() { return x; }
};

void liczba::zapisz_czas(int akcja)
{
    fstream plik;
    plik.open("lab06p02.log", ios::app);
    time_t czas = time(NULL);
    tm * czasLokalny = localtime(&czas);
    plik << "obiekt: " << Id;
    if (akcja == 1)
        plik << " utworzono ";
    else
        plik << " usunieto ";
    plik << czasLokalny->tm_hour<<":"<<czasLokalny->tm_min<<":"<<czasLokalny->tm_sec<<";"
        <<" po "<<czas - czas_start<<" s. od uruchomienia programu"<<endl;
    plik.close();
}

int liczba::ile = 0;
time_t liczba::czas_start;

int main()
{
    liczba::czas_start = time(NULL);
    cout << "press any key" << endl;
    getch();
    liczba *p1 = new liczba(10);
    cout << "press any key" << endl;
    getch();
    liczba *p2 = new liczba(20);
    cout << liczba::ile << endl;
    delete p1;
    delete p2;
    return 0;
}