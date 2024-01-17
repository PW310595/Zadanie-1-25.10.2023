#include <iostream>
#include <map>

int main() {
    // Deklaracja i inicjalizacja mapy
    std::map<int, std::string> mapa;

    // Dodanie elementów do mapy
    mapa[1] = "Jeden";
    mapa[2] = "Dwa";
    mapa[3] = "Trzy";

    // Iteracja przez mapę
    for (const auto& para : mapa) {
        std::cout << "Klucz: " << para.first << ", Wartość: " << para.second << std::endl;
    }

    // Wyszukiwanie elementu w mapie
    auto znaleziony = mapa.find(3);
    if (znaleziony != mapa.end()) {
        std::cout << "Znaleziono: " << znaleziony->second << std::endl;
    }

    return 0;
}
=================================================================================================
  #include <iostream>
#include <set>

int main() {
    // Deklaracja i inicjalizacja zbioru
    std::set<int> zbior;

    // Dodanie elementów do zbioru
    zbior.insert(3);
    zbior.insert(1);
    zbior.insert(2);

    // Iteracja przez zbiór
    for (const auto& element : zbior) {
        std::cout << "Element: " << element << std::endl;
    }

    // Wyszukiwanie elementu w zbiorze
    auto znaleziony = zbior.find(2);
    if (znaleziony != zbior.end()) {
        std::cout << "Znaleziono: " << *znaleziony << std::endl;
    }

    return 0;
}
