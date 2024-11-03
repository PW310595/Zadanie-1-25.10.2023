#include <iostream>
#include "N:\Reszta\projekty\nauka_1\ConsoleApplication1\przyjaciele.h"
#include <math.h>
using namespace std;
 

class Punkt {

	float x, y;
	string nazwa;

public:
	void wyswietl()
	{
		cout << nazwa << "(" << x << "," << y << ")" << endl;
	}
	Punkt(string n="S", float a=0, float b=0) {

		nazwa = n;
		x = a;
		y = b;
	}

	void dopisz()
	{
		//bez nazwy, aby dzialal KOLO
		cout << "Srodek Punktu" << endl;
		cin >> x >> y;
	}

};

class Kolo : public Punkt //klasa kolo dziedziczy publicznie z klasy Punkt
{
	float r;
	string nazwa; //przesloniecie stringa z klasy Punkt
	int M_PI; //zepsute xd

public:
	void wyswietl() {
		float M_PI = 3.14;
		cout << "Nazwa Kola" << endl;
		cout << "Srodek Kola" << endl;
		Punkt::wyswietl(); //wywolanie z klasy rodzica, Klasy Punkt
		cout << "Promien: " << r << endl;
		cout << "Pole kola :" << M_PI * r * r << endl;
	}

	void dopisz() {
		cout << "Nazwa Kola" << endl;
		cin >> nazwa;
		Punkt::dopisz();
		cout << "Promien Kola" << endl;
		cin >> r;

	}

	Kolo(string nk="KoloDUze", string np="S", float a = 0, float b = 0, float pr = 1)
		:Punkt(np,a,b) //czesc atrybutow wzieta z Punktu
	{
		nazwa = nk;
		r = pr;

	}

};


int main() {

	Kolo k1;
	k1.dopisz();
	k1.wyswietl();


	return 0;

}
