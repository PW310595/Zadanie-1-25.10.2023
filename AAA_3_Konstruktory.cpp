=================================================main.cpp

#include <iostream>
#include "N:\Reszta\projekty\nauka_1\ConsoleApplication1\event.h"
using namespace std;


int main()
{
	 //Event w1; //niepoprawne, bo juz musimy podac wartosci do konstruktora

	Event w1("Kino w Szkole",6,8,2045,8,15);
	
	//w1.load();
	w1.show();
}

=====================================================event.h

#include <iostream>
using namespace std;

class Event
{
private: 
	int day, month, year;
	int hour, minutes;
	string name;
public:

	//konstruktor
	//Event(string,int,int,int,int,int);

	//Tak aby w main.cpp Event w1; znowu działał

	Event(string="brak", int=1, int=1, int=2025, int=12, int=0);

	//destruktor
	~Event();
	void load();
	void show();

};



  =====================================================event.cpp

#include <iostream>
#include "N:\Reszta\projekty\nauka_1\ConsoleApplication1\event.h"
using namespace std;

void Event::load() {
	cout << endl << "Nazwa Eventu";
		cin >> name;
		cout << endl << "Dzien Eventu";
		cin >> day;
		cout << endl << "Miesiac Eventu";
		cin >> month;
		cout << endl << "Rok Eventu";
		cin >> year;
		cout << endl << "Godzina Eventu";
		cin >> hour;
		cout << endl << "Minuta Eventu";
		cin >> minutes;
}

void Event::show() {
	cout << endl << name << "  " << day << "  " << month << "  " << year << "  " << hour << "  " << minutes << "  " << endl;

}

Event::Event(string n,int d, int m, int y, int h,int mins) { //konstruktor //piszemy string n, bo nazwa obojetna. Nie moze byc jak w klasie
	name = n;
	day = d;
	month = m;
	year = y;
	hour = h;
	minutes = mins;
}

//destruktor

Event::~Event()
{
	cout << "Czyszczenie Destruktora";
}
