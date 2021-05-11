#include <iostream>

using namespace std;

class liczba
{
private:
    int x;

public:
    static int ile;
    static int suma;
    liczba(int dana = 0) : x(dana)
    {
        ile++;
        suma += x;
    }
    ~liczba()
    {
        ile--;
        suma -= x;
    }
    int getLiczba() { return x; }
    void setLiczba(int liczba)
    {
        suma-=x;
        x = liczba;
        suma+=x;
    }
};

int liczba::ile = 0;
int liczba::suma = 0;

int main()
{

    // liczba a(20), b, c(40), d(50);

    // cout<<liczba::ile<<endl;
    // liczba e(300);
    // cout<<liczba::ile<<endl;

    liczba *p1 = new liczba(100);
    liczba *p2 = new liczba(200);
    liczba *p3 = new liczba(300);

    cout << "liczb: " << liczba::ile << " suma=" << liczba::suma << endl;
    p2->setLiczba(1000);
    cout << "liczb: " << liczba::ile << " suma=" << liczba::suma << endl;

    delete p1;
    delete p2;
    delete p3;
    cout << "liczb: " << liczba::ile << " suma=" << liczba::suma << endl;

    return 0;
}