#include <iostream>

using namespace std;

class tablica
{
private:
    int tab[5];
    int dlugosc = 5;

public:
    int &operator[](unsigned int index)
    {
         return tab[index];
     }
    int getDlugosc() { return dlugosc; }
};

int main()
{
    tablica t;

    t[0] = 10;
    cout << t[0]<<endl;
    cout<<t.getDlugosc();

    return 0;
}