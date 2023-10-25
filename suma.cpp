
#include <iostream>

int main() {
	/*1
		int a, b;
		a = 5;
		b = 5;
		std::cout << "Suma a i b: \n" << a + b << std::endl;
		*/
		/* 2
			int c, d;
			std::cout << "Wprowadz c i d \n";
			std::cin >> c >> d;
			std::cout << "Suma c i d: \n" << c + d << std::endl;
			*/
			/* 3
				double a1,b1,c1;
				double x1;
				std::cout << "Rownanie liniowe: ax + b = c. Wprowadz a,b,c , aby obliczyc X \n";
				std::cin >> a1 >> b1 >> c1;
				if (a1 == 0) {
					std::cout << "'a' nie moze byc rowne 0\n";
				}
				else {
					x1 = (c1 - b1) / a1;
					std::cout << "X = " << x1;
				}
				*/
				//4
					/*
					double a2, b2, x, y;
					double c11 = 12;
					double c22 = 24;
					std::cout << "Podaj a i b dla równania:\n";
					std::cout << "ax + by = 12\n";
					std::cout << "2ax + 4by = 24\n";
					std::cin >> a2 >> b2;
					std::cout << a2 << "x + "<<b2 <<"y = 12\n";
					std::cout << 2*a2 <<"x + " << 4*b2 << "y = 24\n";
					if (a2 == 0 && b2 == 0) {
						std::cout << "Uk³ad nieoznaczony";
					}
					else if (a2==0 || b2 == 0) {
						std::cout << "Uk³ad jest sprzeczny";

					}
					else {
						y = (c22 - 2*a2*c11) / (2 * a2 * b2 - 4 *b2*b2);
						x = (c11 - b2 * y) / a2;
						std::cout << "Wartosc x i y:  X: " << x << "  Y:  " << y;
					}
					*/
					//5 
						/*
						double a3, b3, c3, d, x11, x22, x00;
						std::cout << "Rownanie kwadratowe: ax^2 + bx + c = 0. Wprowadz a,b,c , aby obliczyc X \n";
						std::cin >> a3 >> b3 >> c3;
						if (a3 == 0){
							if (b3 == 0) {
								if (c3 == 0) {
									std::cout << "0 = 0";
								}
								else {
									std::cout << "Sprzecznosc";
								}
							}
							else {
							std::cout << "Wynik: " << -c3 / b3;
							}
						}
						else {
							d = (b3*b3) - (4 * a3 * c3);
							if (d < 0) {
								std::cout << "Brak rozwiazan";
							}
							else {
								if (d == 0) {
									x00 = -b3 / (2 * a3);
									std::cout << "1 rozwiazanie: " << x00;
								}
								else {
									x11 = (-b3 - sqrt(d)) / (2 * a3);
									x22 = (-b3 + sqrt(d)) / (2 * a3);

									std::cout << "2 rozwiazania: x1: " << x11 <<" x2: " << x22;
								}

							}

						}
						*/
}

