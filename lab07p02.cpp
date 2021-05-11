#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class RGB;
class ARGB;

class RGB
{
private:
    int R;
    int G;
    int B;

public:
    RGB(int r = 0, int g = 0, int b = 0) : R(r), G(g), B(b) {}
    string toString()
    {
        stringstream temp;
        temp << "R=" << R << " G=" << G << " B=" << B << " ";
        return temp.str();
    }
    friend ARGB* dodaj(RGB* p1, ARGB* p2);
    friend ARGB* dodaj(ARGB* p1, RGB* p2);
    friend ARGB* dodaj(ARGB* p1, ARGB* p2);
    friend ARGB* dodaj(RGB* p1, RGB* p2);
};

class ARGB
{
private:
    int A;
    int R;
    int G;
    int B;

public:
    ARGB(int a=0, int r = 0, int g = 0, int b = 0) : A(a), R(r), G(g), B(b) {}
    string toString()
    {
        stringstream temp;
        temp << "A=" << A << " R=" << R << " G=" << G << " B=" << B << " ";
        return temp.str();
    }

    friend ARGB* dodaj(RGB* p1, ARGB* p2);
    friend ARGB* dodaj(ARGB* p1, RGB* p2);
    friend ARGB* dodaj(ARGB* p1, ARGB* p2);
    friend ARGB* dodaj(RGB* p1, RGB* p2);
};

ARGB* dodaj(RGB* p1, ARGB* p2)
{
    ARGB* temp = new ARGB;
    temp->A = round((255 + p2->A)/ 2.0);
    temp->R = round((p1->R + p2->R) / 2.0);
    temp->G = round((p1->G + p2->G) / 2.0);
    temp->B = round((p1->B + p2->B) / 2.0);
    return temp;
}

ARGB* dodaj(ARGB* p1, RGB* p2)
{
    ARGB* temp = new ARGB;
    temp->A = round((p1->A + 255)/ 2.0);
    temp->R = round((p1->R + p2->R) / 2.0);
    temp->G = round((p1->G + p2->G) / 2.0);
    temp->B = round((p1->B + p2->B) / 2.0);
    return temp;
}

ARGB* dodaj(ARGB* p1, ARGB* p2)
{
    ARGB* temp = new ARGB;
    temp->A = round((p1->A + p2->A)/ 2.0);
    temp->R = round((p1->R + p2->R) / 2.0);
    temp->G = round((p1->G + p2->G) / 2.0);
    temp->B = round((p1->B + p2->B) / 2.0);
    return temp;
}

ARGB* dodaj(RGB* p1, RGB* p2)
{
    ARGB* temp = new ARGB;
    temp->A = 255;
    temp->R = round((p1->R + p2->R) / 2.0);
    temp->G = round((p1->G + p2->G) / 2.0);
    temp->B = round((p1->B + p2->B) / 2.0);
    return temp;
}

int main()
{
    RGB* kol1 =  new RGB(20,30,50);
    ARGB* kol2 = new ARGB(50,40,25,20);
    ARGB* wynik = dodaj(kol2,kol1);
    cout<<wynik->toString();
    delete kol1;
    delete kol2;
    delete wynik;
    return 0;
}