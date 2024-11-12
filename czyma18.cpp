##################################### Zadanie1

class SimpleSimulation: public Simulation
{
protected:
	
	virtual void Next() {

	}

	virtual void Init() {

		Animal* animal = new Animal();
		this->safari.Add(animal);
	}

};

##################################### Zadanie2

#pragma once
using namespace std;
class Vector2D {
private:

	double x, y;

public:
	//2 konstruktor
	Vector2D(double xx, double yy) {
		x = xx;
		y = yy;
	}

	//2a unarny

	Vector2D operator-() {
		return Vector2D(x*(-1), y*(-1));
	}
	//2a binarny

	Vector2D operator-(const Vector2D drugiwektor) {
		return Vector2D(x - drugiwektor.x, y - drugiwektor.y);

	}

	//2b

	Vector2D operator+=(const Vector2D drugiwektor) {
		x += drugiwektor.x;
		y += drugiwektor.y;

		return Vector2D(x, y);

	}

	//2c

	Vector2D operator*(const double skalar) {
		return Vector2D(x*skalar, y*skalar);
	}

	//2d

	void normalize() {
		double dlugosc = sqrt(x*x +  y*y);
		if (dlugosc > 0) {
			x = x / dlugosc;
			y = x / dlugosc;
		}
	}

	//2e

	void Show() {
		cout << " x i y: "<< x << " " << y << endl;
	}

	//2f

	double dist(const Vector2D drugiwektor){

		double xx = x - drugiwektor.x;
		double yy = y - drugiwektor.y;
		double dist = sqrt(xx*xx + yy*yy);
		return dist;
	}

};

##################################### Zadanie3

#pragma once
#include "safari.h"
#include <iostream>
#include "vector2d.h"
class Animal
{
protected:
	//3a
	Vector2D pozycja;
	//3c
	Vector2D kierunek;
	//3d
	double predkosc;
public:
	void Show()
	{
		std::cout << "metoda Show klasy Animal\n";
	}
	

	void Do(Safari& safari)
	{
		std::cout << "metoda Do klasy Animal\n";
	}

	//3b
	Vector2D GetPos() const {
		return pozycja;
	}

	//3e

	Animal(Vector2D poz, Vector2D kie, double pre) {
		pozycja = poz;
		kierunek = kie;
		predkosc = pre;
	}


};
