#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cmath>

using namespace std;

struct punkt
{
    int x;
    int y;
};

punkt *punkty[100];

void wypisz();
void losuj(int a, int b);
double promien(punkt *p);
int usun(int r);
void usun();

int main()
{
    srand(time(NULL));
    losuj(-100, 100);
    wypisz();
    cout << endl;
    cout << usun(50);
    cout << endl;
    wypisz();
    usun();
    return 0;
}

void wypisz()
{
    for (int i = 0; i < 100; i++)
        if (punkty[i] != NULL)
            cout << "(" << punkty[i]->x
                 << ";" << punkty[i]->y
                 << ")  ";
}

void losuj(int a, int b)
{
    for (int i = 0; i < 100; i++)
    {
        punkty[i] = new punkt;
        punkty[i]->x = rand() % (b - a) + a;
        punkty[i]->y = rand() % (b - a) + a;
    }
}

double promien(punkt *p)
{
    return sqrt(p->x * p->x + p->y * p->y);
}

int usun(int r)
{
    int ile = 0;
    for (int i = 0; i < 100; i++)
        if (punkty[i] != NULL)
            if (promien(punkty[i]) > r)
            {
                delete punkty[i];
                punkty[i] = NULL;
                ile++;
            }

    return ile;
}

void usun()
{
    for (int i = 0; i < 100; i++)
        if (punkty[i] != NULL)
            delete punkty[i];
}