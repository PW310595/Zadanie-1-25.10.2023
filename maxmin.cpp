#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

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


   int n3;
    std::cout << "Podaj n3" << std::endl;
    std::cin >> n3;
    std::vector<int> Wektor3;
    Losowo3(Wektor3, n3);
