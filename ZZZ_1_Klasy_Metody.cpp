#include <iostream>
using namespace std;

class Zwierze
{
public:
    //atrybuty
    string gatunek;
    string imie;
    int wiek;
    //metody
    void dodaj_zwierze() {
        cout << "Dodawanie Zwierzecią do Bazy" << endl;
        cout << "Podaj gatunek: ";
        cin >> gatunek;
        cout << "Podaj imie: ";
            cin >> imie;
            cout << "Podaj wiek: ";
            cin >> wiek;

    }

    void daj_głos() {
        if (gatunek == "kot") cout << imie << " lat" << wiek << "Miau!";
        else if (gatunek == "koza") cout << imie << " lat" << wiek << "Beeeeeeeeeeeeeee!";
        else if (gatunek == "krowa") cout << imie << " lat" << wiek << "Muuuuuuuuuuuuuuuuu!";
        else cout << "WTF";
    }

    void cotozagatunek() {
        cout << gatunek << endl;
    }

};

int main()
{
    Zwierze z1;
    z1.dodaj_zwierze();
    z1.daj_głos();
    z1.cotozagatunek();

    Zwierze z2;
    z2.gatunek;
}
