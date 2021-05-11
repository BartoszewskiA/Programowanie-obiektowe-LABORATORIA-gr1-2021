#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

class punkt
{
private:
    int x;
    int y;

public:
    void setX(int px) { x = px; }
    void setY(int py) { y = py; }
    int getX() { return x; }
    int getY() { return y; }
    double getR();

    void losujPunkt(int min, int maks);
};

void punkt::losujPunkt(int min, int maks) //<min,max)
{
    x = rand() % (maks - min) + min;
    y = rand() % (maks - min) + min;
}

double punkt::getR()
{
    return sqrt(x * x + y * y);
}

// punkt tab[100];

punkt* tab[100];

int main()
{
    srand(time(NULL));

    // for (int i = 0; i < 100; i++)
    //     tab[i].losujPunkt(-100, 100);
    // for (int i = 0; i < 100; i++)
    //     if (tab[i].getR() <= 60)
    //         cout << "(" << tab[i].getX() << ";" << tab[i].getY() << ")  ";

    for (int i=0; i<100; i++)
        {
            tab[i] = new punkt;
            tab[i]->losujPunkt(-100, 100);
        }

    for (int i=0; i<100; i++)
        delete tab[i];
    return 0;
}