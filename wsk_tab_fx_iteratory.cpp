#include <iostream>

int main() {
    const int rozmiar_tablicy = 5;

    // Deklaracja i inicjalizacja tablicy
    int tablica[rozmiar_tablicy] = { 1, 2, 3, 4, 5 };

    // Wskaźnik do pierwszego elementu tablicy
    int* wskaznik = tablica;

    // Iteracja przez tablicę za pomocą wskaźnika
    for (int i = 1; i < rozmiar_tablicy; ++i) {
        std::cout << "Element " << i << ": " << *wskaznik << std::endl;
        ++wskaznik;  // Przejście do następnego elementu
    }

    return 0;
}
===================================================
#include <iostream>

// Funkcja do dodawania dwóch liczb
int dodaj(int a, int b) {
    return a + b;
}

int main() {
    // Wskaźnik do funkcji
    int (*wskaznik_do_funkcji)(int, int) = dodaj;

    // Wywołanie funkcji za pomocą wskaźnika
    int wynik = wskaznik_do_funkcji(3, 4);

    std::cout << "Wynik dodawania: " << wynik << std::endl;

    return 0;
}
==============================================================
#include <iostream>
#include <vector>

int main() {
    // Deklaracja i inicjalizacja wektora
    std::vector<int> wektor = { 1, 2, 3, 4, 5 };

    // Iterator do pierwszego elementu wektora
    std::vector<int>::iterator iterator = wektor.begin();

    // Iteracja przez wektor za pomocą iteratora
    while (iterator != wektor.end()) {
        std::cout << "Element: " << *iterator << std::endl;
        ++iterator;  // Przejście do następnego elementu
    }

    return 0;
}
