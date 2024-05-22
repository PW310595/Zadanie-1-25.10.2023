#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <iomanip>


#define EMPTY -1 // puste miejsce w tablicy mieszajacej
#define REMOVED -2 // puste miejsce tablicy mieszajacej z ktorego usuniety zostal jakis element

//Zad. 1 Wstawianie do tablicy mieszajacej (adresowanie liniowe)

/** Funkcja mieszajÄ…ca wykorzystujÄ…ca adresowanie liniowe
@param x element dla ktĂłrego obliczamy wartoĹ›Ä‡ funkcji mieszajÄ…cej
@param m rozmiar tablicy do ktĂłrej wstawiamy (parametr funki mieszajacej)
@param i ktĂłra to prĂłba wstawienia/ktĂłre obliczenie funkcji mieszajÄ…cej (parametr funki mieszajacej)
@return wartoĹ›Ä‡ f. mieszajÄ…cej, pod ten indeks prĂłbujemy wstawiÄ‡ potem x
*/
int cnt = 0;
int h(int x, int m, int i) {
	cnt++;
	if (i == 0) return x % m;
	return (x % m + i) % m;
}

/** Funkcja wstawiajaca jeden element x do tablicy mieszajacej tab o rozmiarze m
 @param A tablica mieszajaca
 @param m rozmiar tablicy mieszajacej
 @param x element wstawiany do tablicy
 @return true, jesli element zostal wstawiony; false, jesli nie udalo sie wstawic elementu (brak miejsca w tablicy)
 */

bool hash_al_wstaw(int* A, int m, int x)
{
	for (int i = 0; i < m; i++) {
		int k = h(x, m, i);
		if (A[k] == EMPTY || A[k] == REMOVED) {
			A[k] = x;
			return true;
		}
	}
	return false;
}

bool hash_al_szukaj(int* A, int m, int x) {
	for (int i = 0; i < m; i++) {
		int k = h(x, m, i);
		if (A[k] == x) return true;
		if (A[k] == EMPTY) return false;
	}
	return false;
}

/** Funkcja pomocnicza: wyswietlanie tablicy mieszajacej A o rozmiarze m
 @param A tablica mieszajaca
 @param m rozmiar tablicy mieszajacej
 */
void print_tab(int* A, int m)
{
	std::cout << std::setw(7) << "indeks:";
	for (int i = 0; i < m; i++)
	{
		std::cout << std::setw(11) << i;
	}
	std::cout << std::endl;
	std::cout << std::setw(8) << "|";
	for (int i = 0; i < m; i++)
	{
		std::cout << std::setw(10) << A[i] << "|";
	}
	std::cout << std::endl;
}

int main()
{
	std::cout << "Zadanie 1 i 2:\n";
	// Zad. 2 (rozgrzewka + test)
	const int m1 = 8; //rozmiar tablicy mieszajacej
	int t[m1]; //tablica mieszajaca
	// Wyczyszczenie tablicy mieszajacej t (Wypelnienie pustymi miejscami)
	for (int i = 0; i < m1; i++)
	{
		t[i] = EMPTY;
	}

	// Wstawianie elementĂłw do tablicy mieszajacej t (uzyÄ‡ funkcji hash_al_wstaw)
	// ...
	/*
	hash_al_wstaw(t, m1, 15);
	hash_al_wstaw(t, m1, 3);
	hash_al_wstaw(t, m1, 8);
	hash_al_wstaw(t, m1, 20);
	hash_al_wstaw(t, m1, 27);
	hash_al_wstaw(t, m1, 18);
	hash_al_wstaw(t, m1, 25);
	hash_al_wstaw(t, m1, 0);
	*/
	// Wyswietlenie tablicy t o rzmiarze m1 (std::cout)
	print_tab(t, m1);

	// Zad. 3 Pomiary
	std::cout << "\nZadanie 3:\n";
	// a) Tablica z danymi
	// Tworzenie tablicy dane z danymi do wstawinia do tablicy mieszajacej
	int rozm_dane = 20000000; //liczba elementow w tablicy dane
	int* dane = new int[rozm_dane];
	//wypelnienie tablicy dane kolejnymi liczbami od 0 do rozm_dane-1
	for (int i = 0; i < rozm_dane; i++)
	{
		dane[i] = i;
	}
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(dane, dane + rozm_dane, g); //losowa permutacja elementow w tablicy dane (wymieszanie tablicy)


	// b) Tablica mieszajaca
	// Utworz pusta tablice mieszajaca tab o rozmiarze m = 2097152 (2 do potegi 21)
	const int m = 2097152;
	int * tab = new int[m];
	for (int i = 0; i < m; i++)
	{
		tab[i] = EMPTY;
	}
	// ... 

	// c) Wstaw 10000 elemetow z tablicy dane do pustej tablicy mieszajacej tab (zapelnienie 0%). Na tej podstawie zmierz sredni czas wstawiania elementu oraz sredniÄ… liczbe wywolan funkcji mieszajacej przy wstawianiu elementu do pustej tablicy.

	
	std::cout << "Pomiary:\n";
	// Mierzenie czasu, przyklad:
	auto start0 = std::chrono::high_resolution_clock::now();
	//tutaj mierzona operacja
	
	for (int i = 0; i < 10000; i++)
	{
		hash_al_wstaw(tab, m, dane[i]);
	}
	std::cout << "liczba wywolan h: " << cnt << std::endl;
	

	//koniec mierzenia zwykĹ‚ego
	auto stop0 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> czas0 = stop0 - start0;
	std::cerr << "Uplynelo: " << czas0.count() << " us\n" << std::endl;

	// Mierzenie 2
	for (double z = 0.1; z < 1; z += 0.1) {
		for (int i = 0; i < m; i++){tab[i] = EMPTY;}
		for (int i = 0; i < m * z; i++){hash_al_wstaw(tab, m, dane[i]);}
		cnt = 0;
		
		//Zapelnianie
		auto start1 = std::chrono::high_resolution_clock::now();
		for (int i = m * z; i < m * z + 10000; i++) {hash_al_wstaw(tab, m, dane[i]);}
		auto stop1 = std::chrono::high_resolution_clock::now();
		//Info
		//std::cout << "Procent zapelnienia h: " << z * 100 << "%" << std::endl;
		//std::cout << "ZAPELNIANIE" << std::endl;
		//std::cout << "Ilosc wywolan h: " << cnt << std::endl;
		//std::cout << "Srednie h dla wstawiania: " << cnt / 10000.0 << std::endl;
		std::chrono::duration<double, std::micro> czas1 = stop1 - start1;
		//std::cerr << "Zapelniono w: " << czas1.count()/10000.0 << " us" << std::endl;
		
		std::cout << z * 100 << ", " << czas1.count() / 10000.0 << ", " << cnt / 10000.0 << ", ";

		//Szukanie
		//losowanie z zakresu wstawionych
		cnt = 0;
		std::uniform_int_distribution<> distr(0, m * z);
		
		start1 = std::chrono::high_resolution_clock::now();
		for (int i = m * z; i < m * z + 10000; i++) { hash_al_szukaj(tab, m, dane[distr(g)]); }
		stop1 = std::chrono::high_resolution_clock::now();
		czas1 = stop1 - start1;

		std::cout << czas1.count() / 10000.0 << ", " << cnt / 10000.0 << std::endl;

		//std::cout << "SZUKANIE" << std::endl;
		//std::cout << "Ilosc wywolan h: " << cnt << std::endl;
		//std::cout << "Srednie h dla szukania " << cnt / 10000.0 << std::endl;
		//std::cerr << "Szukano w: " << czas1.count()/ 10000.0 << "us" << std::endl << std::endl;

	}

	// d) Zmierz sredni czas wstawiania elementu oraz sredniÄ… liczbe wywolan funkcji mieszajacej przy wstawianiu elementu do tablicy wypelnionej w 10%, 20%, 30%, 40%, 50%, 60%, 70%, 80%, 90% (dla prĂłbki: 10000 elementĂłw).
	//UWAGA! Do tablicy mieszajacej nie wstawiac elementow, ktore juz w niej sa (wstawiane elementy nie mogÄ… siÄ™ powtarzaÄ‡).

	return 0;
}
