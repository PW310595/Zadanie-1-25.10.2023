
#include <iostream>
#include <string>
#include <deque>
#include <vector>

int main()
{
    std::deque<int> d = { 1, 2, 3, 4, 5 };

    std::cout << "size = " << d.size() << std::endl;

    std::cout << "Third element = " << d[2] << std::endl;

    std::cout << d.front() << ", " << d.back() << std::endl;

    for (std::deque<int>::iterator it = d.begin(); it != d.end(); ++it)
        std::cout << *it << "\t";
    std::cout << std::endl;
 //==================================================================================

std::vector<std::string> Items;
Items = { "Ala", "Ma", "Kot" };
Items.push_back("Pies");

for (int i = 0; i < Items.size(); i++) {

	std::cout << Items[i] << std::endl;
}

  //==================================================================================
  #include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Wektor jako tablica o niestałym rozmiarze: vector<T>.


template<typename T>
void Losowo(std::vector<T>& tablica, int roz) {
    for (int i = 0; i < roz; i++) {
        tablica.push_back(rand() % 100);
    }
}

template<typename T>
void Losowo2(std::vector<T>& tablica, int roz) {

    for (int i = 0; i < roz; i++) {
        tablica.push_back(rand() % 100);
    }
    for (int i = 0; i < tablica.size(); i++) {
        std::cout << tablica[i] << " ";
    }
}

template<typename T>
void Losowo3(std::vector<T>& tablica, int roz) {

    for (int i = 0; i < roz; i++) {
        tablica.push_back(rand() % 100);
    }
    for (int i = 0; i < tablica.size(); i++) {
        std::cout << tablica[i] << " ";
    }

    int min = INT_MAX;
    for (int j = 0; j < tablica.size(); j++) {
        if (tablica[j] < min) {
            min = tablica[j];
        }
    }
    std::cout << " MIN: " << min << std::endl;

    int max = INT_MIN;
    for (int k = 0; k < tablica.size(); k++) {
        if (tablica[k] > max) {
            max = tablica[k];
        }
    }
    std::cout << " MAX: " << max << std::endl;
}


struct Kolo {

    double punkt_x;
    double punkt_y;
    double punkt_r;
};

std::vector<Kolo> generujKola() {
    std::vector<Kolo> kola;

    Kolo kolo1 = {1, 2, 2};
    Kolo kolo2 = {4, 8, 4};
    Kolo kolo3 = {9, 18, 6};

    kola.push_back(kolo1);
    kola.push_back(kolo2);
    kola.push_back(kolo3);

    return kola;
}

int MaleKolo(const std::vector<Kolo>& kola) {
    double minPole = std::numeric_limits<double>::max();
    int Najmni = -1;

    for (int i = 0; i < kola.size(); ++i) {
        double pole = (22.0/7.0)*pow(kola[i].punkt_r, 2);
        if (pole < minPole) {
            minPole = pole;
            Najmni = i;
        }
    }

    return Najmni;
}

int main() {

    // 1. Funkcja wypełniająca tablicę wartościami losowymi(vector<T>)
    int n;
    std::cout << "Podaj n" << std::endl;
    std::cin >> n;
    std::vector<int> Wektor;
    Losowo(Wektor, n);

    for (int i = 0; i < Wektor.size(); i++) {
        std::cout << Wektor[i] << " ";
    }
    std::cout << " " << std::endl;

    // 2. Funkcja wypisująca tablicę na ekran.

    int n2;
    std::cout << "Podaj n2" << std::endl;
    std::cin >> n2;
    std::vector<int> Wektor2;
    Losowo2(Wektor2, n2);

    // 3. Funkcja wyznaczająca minimum i maksimum z tablicy(vector<T>).
    int n3;
    std::cout << "Podaj n3" << std::endl;
    std::cin >> n3;
    std::vector<int> Wektor3;
    Losowo3(Wektor3, n3);

    /* 4. Zdefiniować strukturę koło(opisaną przez środek i promień).Stworzyć funkcję generującą wektor kół oraz funkcję,
    która wylicza pole koła dla każdego elementu i zwraca indeks najmniejszego koła. */
    
    
    std::vector<Kolo> kola = generujKola();

    for (const auto& kolo : kola) {
        std::cout << "Srodek: " << kolo.punkt_x << ", " << kolo.punkt_y << " Promien: " << kolo.punkt_r << std::endl;
    }
    int Najmni = MaleKolo(kola);
    std::cout << "Indeks najmniejszego kola: " << Najmni << std::endl;

    return 0;
}

}
