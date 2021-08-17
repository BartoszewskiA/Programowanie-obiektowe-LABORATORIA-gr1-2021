#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <ctime>

using namespace std;

const int ZYCIE = 200;

struct cios
{
    int atak_fizyczny = 0;
    int atak_magiczny = 0;
    bool podstepny_atak = false;
};
//--------------------------------------------------------------------------------------------------------------
class postac
{
protected:
    string imie;
    int zycie = ZYCIE;

public:
    postac(string im) : imie(im) {}
    virtual cios zadanie_ciosu() = 0;
    virtual void przyjecie_ciosu(cios c) = 0;
    virtual string przedstaw_sie() = 0;
    virtual string stan_postaci() = 0;
    int getZycie() { return zycie; }
};

//--------------------------------------------------------------------------------------------------------------

class barbarzynca : public postac
{
protected:
    int atak = 20;
    int obrona_fizyczna = 10;
    int obrona_magiczna = 0;
    int szal = 0;

public:
    barbarzynca(string im) : postac(im) {}
    friend void starcie(postac &p1, postac &p2);
    cios zadanie_ciosu()
    {
        cios c;
        szal = ZYCIE - zycie / 100;
        c.atak_fizyczny = atak * ((rand() % 81 + 20) / 100);
        c.atak_fizyczny = c.atak_fizyczny + szal * c.atak_fizyczny;
        return c;
    }
    void przyjecie_ciosu(cios c)
    {

        if (c.podstepny_atak)
        {
            zycie -= c.atak_fizyczny;
            zycie -= c.atak_magiczny;
        }
        else
        {
            zycie -= c.atak_fizyczny - obrona_fizyczna * ((rand() % 81 + 20) / 100);
            zycie -= c.atak_magiczny - obrona_magiczna * ((rand() % 81 + 20) / 100);
        }
    }
    string przedstaw_sie()
    {
        stringstream temp;
        temp << imie << " barbazybca; ";
        return temp.str();
    }
    string stan_postaci()
    {
        stringstream temp;
        temp << "Zycie: " << zycie; // itd
        return temp.str();
    }
};

//--------------------------------------------------------------------------------------------------------------

class mag : public postac
{

protected:
    int atak = 20;
    int obrona_fizyczna = 0;
    int obrona_magiczna = 10;
    int mana = 300;
    int przyrost_many = 1;

public:
    mag(string im) : postac(im) {}
    friend void starcie(postac &p1, postac &p2);
    cios zadanie_ciosu()
    {
        cios c;
        if (mana > 0)
        {
            int atak_m = atak * ((rand() % 81 + 20) / 100);
            mana -= atak_m;
            c.atak_magiczny = atak_m;
        }
        else
        {
            c.atak_fizyczny = 5;
        }
        mana += przyrost_many;
        return c;
    }
    void przyjecie_ciosu(cios c)
    {

        if (c.podstepny_atak)
        {
            zycie -= c.atak_fizyczny;
            zycie -= c.atak_magiczny;
        }
        else
        {
            int tarcza_magiczna = obrona_magiczna * ((rand() % 81 + 20) / 100);
            mana -= tarcza_magiczna / 2;
            zycie -= c.atak_fizyczny - tarcza_magiczna / 2;
            zycie -= c.atak_magiczny - tarcza_magiczna * 2;
            ;
        }
    }
    string przedstaw_sie()
    {
        stringstream temp;
        temp << imie << " mag; ";
        return temp.str();
    }
    string stan_postaci()
    {
        stringstream temp;
        temp << "Zycie: " << zycie; // itd
        return temp.str();
    }
};

//--------------------------------------------------------------------------------------------------------------

class lotrzyk : public postac
{
};

//--------------------------------------------------------------------------------------------------------------

void starcie(postac *p1, postac *p2)
{
    cios c;

    while (p1->getZycie() > 0 && p2->getZycie() > 0)
    {
        c = p1->zadanie_ciosu();
        p2->przyjecie_ciosu(c);
        c = p2->zadanie_ciosu();
        p1->przyjecie_ciosu(c);
    }
}

int main()
{
    srand(time(NULL));

    postac *druzyna_A[3] = {
        new barbarzynca("Conan"),
        new mag("Gandalf"),
        new barbarzynca("Xena")};

    postac *druzyna_B[3] = {
        new mag("Saruman"),
        new mag("Morgana"),
        new barbarzynca("Gora")};

    return 0;
}