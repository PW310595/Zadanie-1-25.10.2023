nagłówke.h

#include <iostream>
#include "N:\Reszta\projekty\nauka_1\ConsoleApplication1\pytanie.h"
#include <fstream>
#include <cstdlib>
#include <string> //do getline

using namespace std;


void Pytanie::wczytaj()
{
    fstream plik;
    plik.open("N:\\Reszta\\projekty\\nauka_1\\ConsoleApplication1\\quiz.txt", ios::in);

    if (plik.good() == false)
    {
        cout << "Nie udalo sie otworzyc pliku!";
        exit(0);
    }

    int nr_linii = (nr_pytania - 1) * 6 + 1;
    int aktualny_nr = 1;
    string linia;

    while (getline(plik, linia))
    {
        if (aktualny_nr == nr_linii) tresc = linia;
        if (aktualny_nr == nr_linii + 1) a = linia;
        if (aktualny_nr == nr_linii + 2) b = linia;
        if (aktualny_nr == nr_linii + 3) c = linia;
        if (aktualny_nr == nr_linii + 4) d = linia;
        if (aktualny_nr == nr_linii + 5) poprawna = linia;
        aktualny_nr++;
    }

    plik.close();

}

void Pytanie::zadaj()
{
    cout << endl << tresc << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << "------------------------" << endl;
    cout << endl << "Odpowiedz: ";
    cin >> odpowiedz;
}

void Pytanie::sprawdz()
{
    if (odpowiedz == poprawna)
    {
        punkt = 1;
    }
    else punkt = 0;
}

pytanie.h

#include <iostream>

using namespace std;

class Pytanie
{
public:

	string tresc;
	string a, b, c, d;
	int nr_pytania;
	string poprawna;
	string odpowiedz;
	int punkt;

	void wczytaj(); //wczytuje pytania z pliku
	void zadaj(); //pokazuje pytanie, czyta odpowiedz
	void sprawdz(); //sprawdza poprawnosc odpowiedzi
};

main.cpp

#include <iostream>
#include "N:\Reszta\projekty\nauka_1\ConsoleApplication1\pytanie.h"
using namespace std;


int main()
{

	Pytanie p[5]; //0-4
	int suma = 0;
	for(int i=0;i<=4;i++){

	p[i].nr_pytania = i+1; //1-5
	p[i].wczytaj();
	p[i].zadaj();
	p[i].sprawdz();
	suma += p[i].punkt;

	}
	cout << "Koniec    Punkty:  " << suma;

	return 0;

}


