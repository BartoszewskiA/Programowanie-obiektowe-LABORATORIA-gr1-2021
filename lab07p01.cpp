#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class RGB
{
private:
    int R;
    int G;
    int B;

public:
    static int ile;
    RGB(int r = 0, int g = 0, int b = 0) : R(r), G(g), B(b) { ile++; }
    // void setR(int r) { R = r; }
    // void setG(int g) { G = g; }
    // void setB(int b) { B = b; }
    // int getR() { return R; }
    // int getG() { return G; }
    // int getB() { return B; }

    string toString(); // => R=.... G=... B=...

    friend RGB dodaj(RGB &kolor1, RGB &kolor2);
    friend RGB *dodaj_wsk(RGB *p1, RGB *p2);

    ~RGB() { cout << endl
                  << "---obiekt usunieto---" << endl; }
};

int RGB::ile = 0;

string RGB::toString()
{
    stringstream temp;
    temp << "R=" << R << " G=" << G << " B=" << B << " ";
    return temp.str();
}

RGB dodaj(RGB &kolor1, RGB &kolor2)
{
    RGB temp;
    temp.R = round((kolor1.R + kolor2.R) / 2.0);
    temp.G = round((kolor1.G + kolor2.G) / 2.0);
    temp.B = round((kolor1.B + kolor2.B) / 2.0);
    return temp;
}

RGB *dodaj_wsk(RGB *p1, RGB *p2)
{
    RGB *temp = new RGB;
    temp->R = round((p1->R + p2->R) / 2.0);
    temp->G = round((p1->G + p2->G) / 2.0);
    temp->B = round((p1->B + p2->B) / 2.0);
    return temp;
}

int main()
{
    // RGB p1(10, 20, 30), p2(20, 10, 20);
    // RGB wynik = dodaj(p1, p2);
    // cout << "Wynik - " << wynik.toString();
    // cout << endl
    //      << "obiektow bylo: " << RGB::ile;

    RGB *kol1 = new RGB(20, 30, 40);
    RGB *kol2 = new RGB(10, 30, 50);
    RGB *wynik_wsk = dodaj_wsk(kol1, kol2);

    cout << "Wynik - " << wynik_wsk->toString();
    cout << endl
         << "obiektow bylo: " << RGB::ile;

    delete kol1;
    delete kol2;
    delete wynik_wsk;
    return 0;
}