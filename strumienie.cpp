#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Strumień wyjściowy
    std::ofstream plik_wyjsciowy("plik.txt");

    // Wypisanie tekstu do pliku
    plik_wyjsciowy << "To jest tekst zapisany do pliku." << std::endl;

    // Zamknięcie pliku
    plik_wyjsciowy.close();

    // Strumień wejściowy
    std::ifstream plik_wejsciowy("plik.txt");

    // Odczyt tekstu z pliku
    std::string linia;
    while (std::getline(plik_wejsciowy, linia)) {
        std::cout << linia << std::endl;
    }

    // Zamknięcie pliku
    plik_wejsciowy.close();

    return 0;
}

=======================================================

#include <iostream>
#include <fstream>

int main() {
    // Strumień wyjściowy binarny
    std::ofstream plik_binarny_wyjsciowy("plik.bin", std::ios::binary);

    // Dane do zapisania
    int liczba = 42;
    double liczba_double = 3.14;

    // Zapis danych do pliku binarnego
    plik_binarny_wyjsciowy.write(reinterpret_cast<char*>(&liczba), sizeof(liczba));
    plik_binarny_wyjsciowy.write(reinterpret_cast<char*>(&liczba_double), sizeof(liczba_double));

    // Zamknięcie pliku
    plik_binarny_wyjsciowy.close();

    // Strumień wejściowy binarny
    std::ifstream plik_binarny_wejsciowy("plik.bin", std::ios::binary);

    // Odczyt danych z pliku binarnego
    int odczytana_liczba;
    double odczytana_liczba_double;

    plik_binarny_wejsciowy.read(reinterpret_cast<char*>(&odczytana_liczba), sizeof(odczytana_liczba));
    plik_binarny_wejsciowy.read(reinterpret_cast<char*>(&odczytana_liczba_double), sizeof(odczytana_liczba_double));

    // Wyświetlenie odczytanych danych
    std::cout << "Odczytana liczba: " << odczytana_liczba << std::endl;
    std::cout << "Odczytana liczba double: " << odczytana_liczba_double << std::endl;

    // Zamknięcie pliku
    plik_binarny_wejsciowy.close();

    return 0;
}
