#include <iostream>
#include "N:\Reszta\projekty\nauka_1\ConsoleApplication1\przyjaciele.h"
#include <math.h>
using namespace std;
 
class Ksztalt {

public:
	virtual void oblicz_pole() = 0; //funkcja czysta, bedzie zawsze przyslonieta
};

class Kolo :public Ksztalt
{
	float r;
public:
	Kolo(float x) {
		r = x;
	}
	virtual void oblicz_pole() //nie trzeba wstawiac virutal
	{
		cout << "Pole Kola: " << 3.14 * r * r << endl;
	}
};

class Kwadrat :public Ksztalt {
	float a;
public:
	Kwadrat(float x)
	{
		a = x;
	}
	virtual void oblicz_pole()
	{
		cout << "Pole: " << a * a << endl;
	}
};

void obliczenia(Ksztalt* x) {

	x->oblicz_pole();
}

int main() {

	Kolo k(1);
	Kwadrat kw(2);

	Ksztalt* wsk; //wskaznik polimorficzny

	wsk = &k;
	wsk->oblicz_pole();

	wsk = &kw;
//	wsk->oblicz_pole();

	obliczenia(wsk);

	return 0;

}
