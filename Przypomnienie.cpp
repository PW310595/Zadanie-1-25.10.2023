#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <iomanip>


#define EMPTY -1 // puste miejsce w tablicy mieszajacej
#define REMOVED -2 // puste miejsce tablicy mieszajacej z ktorego usuniety zostal jakis element

//Zad. 1 Wstawianie do tablicy mieszajacej (adresowanie liniowe)

/** Funkcja mieszająca wykorzystująca adresowanie liniowe
@param x element dla którego obliczamy wartość funkcji mieszającej
@param m rozmiar tablicy do której wstawiamy (parametr funki mieszajacej)
@param i która to próba wstawienia/które obliczenie funkcji mieszającej (parametr funki mieszajacej)
@return wartość f. mieszającej, pod ten indeks próbujemy wstawić potem x
*/
int ilosc = 0;
int h(int x, int m, int i)
{
    ilosc++;
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
    for (int i = 0; i < m; i++)
    {
        int k = h(x, m, i);
        if (A[k] == EMPTY)
        {
            A[k] = x;
            return true;
        }
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

    // Wstawianie elementów do tablicy mieszajacej t (uzyć funkcji hash_al_wstaw)
    hash_al_wstaw(t, m1,21);
    hash_al_wstaw(t, m1, 8);
    hash_al_wstaw(t, m1, 17);
    hash_al_wstaw(t, m1, 0);
    hash_al_wstaw(t, m1, 12);
    hash_al_wstaw(t, m1, 7);
    hash_al_wstaw(t, m1, 4);
    hash_al_wstaw(t, m1, 55);


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
    int* tab = new int[m];
    for (int i = 0; i < m; i++)
    {
        tab[i] = EMPTY;
    }

    // c) Wstaw 10000 elemetow z tablicy dane do pustej tablicy mieszajacej tab (zapelnienie 0%). Na tej podstawie zmierz sredni czas wstawiania elementu oraz srednią liczbe wywolan funkcji mieszajacej przy wstawianiu elementu do pustej tablicy.

    std::cout << "Pomiary:\n";
    // Mierzenie czasu, przyklad:
    float p = 0.0;
    for (int j = 0; j<10;j++)
    {
        for (int i = 0; i < m * p; i++)   //wypelnianie tablicy w 10%
        {
            tab[i] = dane[i];
        }
        ilosc = 0;
        auto start = std::chrono::high_resolution_clock::now();
        //tutaj mierzona operacja
        int b = (m * p) + 10000;
        for (int i = (m * p); i < b; i++)
        {
            hash_al_wstaw(tab, m, dane[i]);

        }
        //koniec mierzenia
        auto stop = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::micro> czas = stop - start;
        std::cerr << "srednio Uplynelo dla " << p*100 << "%: " << czas.count() / 10000.0 << " us\n";
        std::cout << "srednia ilosc wywolan dla " << p*100 << "%: " << ilosc / 10000.0;
        std::cout << std::endl;
        p += 0.1;
        for (int i = 0; i < m; i++)
        {
            tab[i] = EMPTY;
        }
    }
    // d) Zmierz sredni czas wstawiania elementu oraz srednią liczbe wywolan funkcji mieszajacej przy wstawianiu elementu do tablicy wypelnionej w 10%, 20%, 30%, 40%, 50%, 60%, 70%, 80%, 90% (dla próbki: 10000 elementów).
    //UWAGA! Do tablicy mieszajacej nie wstawiac elementow, ktore juz w niej sa (wstawiane elementy nie mogą się powtarzać).

    

    return 0;
}
