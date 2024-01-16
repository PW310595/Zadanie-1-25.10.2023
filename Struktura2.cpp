#include <iostream>
#include <string>

// Definicja struktury
struct Osoba {
    std::string imie;
    std::string nazwisko;
    int wiek;
};

int main() {
    // Utworzenie instancji struktury
    Osoba klient;

    // Przypisanie wartości
    klient.imie = "Jan";
    klient.nazwisko = "Kowalski";
    klient.wiek = 30;

    // Wyświetlenie danych
    std::cout << "Imię: " << klient.imie << std::endl;
    std::cout << "Nazwisko: " << klient.nazwisko << std::endl;
    std::cout << "Wiek: " << klient.wiek << " lat" << std::endl;

    return 0;
}
