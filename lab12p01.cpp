
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
class zespolona
{
private:
    double r; //część rzeczywista
    double u; //część urojona
public:
    zespolona(double R = 0, double U = 0) : r(R), u(U) {}
    friend ostream &operator<<(ostream &str, zespolona x);
    friend istream &operator>>(istream &str, zespolona &x);
};

ostream &operator<<(ostream &str, zespolona x)
{
    if (x.r == 0 && x.u == 0)
    {
        str << 0;
    }
    else
    {
        if (x.r != 0)
            str << x.r;
        if (x.r != 0 && x.u > 0)
            str << "+";
        if (x.u != 0)
            str << x.u << "i";
    }
    return str;
}

istream &operator>>(istream &str, zespolona &x)
{
    // /-(r)+/-(u)i
    string temp;
    int poz = 0;
    str >> temp;
    //3 ; -5 - tylo część rzeczywista
    if (temp[temp.length() - 1] != 'i')
    {
        x.r = atof(temp.c_str());
        x.u = 0;
    }
    else
    {
        for (int i = 0; i < temp.length(); i++)
            if (temp[i] == '+' || temp[i] == '-')
                poz = i;
        if (poz == 0) //liczba ma tylko częśc urojoną 3i -5i
        {
            temp = temp.substr(0, temp.length() - 1); //obcinamy "i"
            x.u = atof(temp.c_str());
            x.r = 0;
        }
        else // pełny zapis liczby zespolonej a+bi
        {
            string tempR = "", tempU = "";
            tempR = temp.substr(0, poz);
            x.r = atof(tempR.c_str());
            tempU = temp.substr(poz, temp.length() - 1);
            x.u = atof(tempU.c_str());
        }
    }
    return str;
}

int main()
{
    //zespolona a(10, 3), b(0, 0), c(0, -5), d(-3, -5), e(3, 0);
    zespolona a;
    cin >> a;
    cout << a << endl;

    return 0;
}
