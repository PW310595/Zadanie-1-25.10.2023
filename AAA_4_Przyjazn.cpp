przyjaciele h 


#include <iostream>
using namespace std;

class Prostokat; //trzeba napisac klase tutaj, bo w klasie Punkt nie wiadomo co to jest Prostokat (w linii 13) - dlatego piszemy na gorze tej klasy Punkt, Klase Prostoakt

class Punkt {
	string nazwa;
	float x, y;
public:
	Punkt(string = "A", float = 0, float = 0);
	void wczytaj();

	friend void sedzia(Punkt &pkt, Prostokat &p); ////zmiana do napisania & powoduje ze pracujemy na oryginale, a nie na kopii
};

class Prostokat {
	string nazwa;
	float x, y, szerokosc, wysokosc;
public:
	Prostokat(string = "brak", float = 0, float = 0, float = 1, float = 1);
	void wczytaj(); //bez mechanizmu kontroli bledu

	friend void sedzia(Punkt &pkt, Prostokat &p); ////zmiana do napisania & powoduje ze pracujemy na oryginale, a nie na kopii
};


przyjaciele.cpp


#include <iostream>
#include "N:\Reszta\projekty\nauka_1\ConsoleApplication1\przyjaciele.h"
using namespace std;

Punkt::Punkt(string n, float xx, float yy) {
	nazwa = n;
	x = xx;
	y = yy;
}

void Punkt::wczytaj() {
	cout << "Podaj x:"; cin >> x;
	cout << "Podaj y:"; cin >> y;
	cout << "Nazwa punktu: "; cin >> nazwa;
}

Prostokat::Prostokat(string n, float xx, float yy, float s, float w) {
	nazwa = n;
	x = xx;
	y = yy;
	szerokosc = s;
	wysokosc = w;
}

void Prostokat::wczytaj() {
	cout << "Podaj x lewegodolnego:"; cin >> x;
	cout << "Podaj y: lewegodolnego"; cin >> y;
	cout << "Nazwa Protsotkata: "; cin >> nazwa;
	cout << "Podaj szerokosc"; cin >> szerokosc;
	cout << "Podaj wysokosc"; cin >> wysokosc;
}


main.cpp


#include <iostream>
#include "N:\Reszta\projekty\nauka_1\ConsoleApplication1\przyjaciele.h"
using namespace std;

//przyjazn

void sedzia(Punkt &pkt,Prostokat &p) { //nazwy moga byc inne "p","pkt" //zmiana do napisania & powoduje ze pracujemy na oryginale, a nie na kopii

	p.nazwa = "Podmiana";

	if (((pkt.x >= p.x) && (pkt.x <= p.x + p.szerokosc)) && ((pkt.y >= p.y) && (pkt.y <= p.y + p.wysokosc)))

		cout << endl << "Punkt " << pkt.nazwa << "Nalezy do prostokat  " << p.nazwa;
	else
		cout << endl << "Punkt " << pkt.nazwa << "lezy Poza prosokatem  " << p.nazwa;
}

int main() {
	Punkt pkt1("A", 3, 17);
	//pkt1.wczytaj();

	Prostokat p1("Prostokat", 0, 0, 6, 4);
	//p1.wczytaj();

	sedzia(pkt1, p1);


	return 0;
}
