Pytania:

1.	Dlaczego string do linii, a nie int?
W kodzie linie są reprezentowane jako ciągi znaków (string), ponieważ mogą 
zawierać zarówno litery, jak i cyfry. Użycie int ograniczyłoby możliwość reprezentowania linii, które mogą mieć bardziej złożone nazwy.  

•	unordered_map<string, set<string>>: Mapa, która przechowuje pary klucz-wartość, gdzie kluczem jest nazwa przystanku (string), a wartością jest zbiór (set) linii (string), które przechodzą przez ten przystanek.
•	przystanki.first: Klucz (nazwa przystanku).
•	przystanki.second: Wartość (zbiór linii przechodzących przez przystanek).


•	linia.rfind("LINIA", 0): Szuka podciągu "LINIA" w ciągu linia, zaczynając od pozycji 0.
•	== 0: Sprawdza, czy "LINIA" znajduje się dokładnie na początku ciągu linia.
Innymi słowy, linia.rfind("LINIA", 0) == 0 sprawdza, czy ciąg linia zaczyna się od "LINIA". Jeśli tak, to rfind zwróci 0, co oznacza, że podciąg "LINIA" został znaleziony na pozycji 0.

=========================
 map<int, int> ile_jest; // Mapa do przechowywania liczby wystąpień
   for (int n : vector) { // Zliczanie wystąpień
       ile_jest[n]++; // Zwiększ licznik dla danej liczby
   }

Załóżmy, że vector zawiera liczby {1, 2, 2, 3}. Pętla działa w następujący sposób:
1.	Pierwsza iteracja:
•	num = 1
•	ile_jest[1]++ zwiększa wartość skojarzoną z kluczem 1 w mapie ile_jest o 1.
•	Mapa ile_jest teraz zawiera: {1: 1}
2.	Druga iteracja:
•	num = 2
•	ile_jest[2]++ zwiększa wartość skojarzoną z kluczem 2 w mapie ile_jest o 1.
•	Mapa ile_jest teraz zawiera: {1: 1, 2: 1}
3.	Trzecia iteracja:
•	num = 2
•	ile_jest[2]++ ponownie zwiększa wartość skojarzoną z kluczem 2 w mapie ile_jest o 1.
•	Mapa ile_jest teraz zawiera: {1: 1, 2: 2}
================================================

    int ile_razy = 0;
    for (const auto& pair : ile_jest) {
        // pair.first to liczba, pair.second to liczba wystąpień
        if (pair.second > ile_razy) {
            ile_razy = pair.second; // Aktualizacja maksymalnej liczby wystąpień
        }
    }
   
   
Załóżmy, że mapa ile_jest zawiera następujące pary: {1: 2, 2: 2, 3: 2, 4: 2, 5: 3}. Pętla działa w następujący sposób:
1.	Pierwsza iteracja:
•	pair = {1, 2}
•	pair.second = 2
•	if (2 > 0) - Warunek jest spełniony.
•	ile_razy = 2 - Aktualizacja ile_razy do 2.
2.	Druga iteracja:
•	pair = {2, 2}
•	pair.second = 2
•	if (2 > 2) - Warunek nie jest spełniony.
•	ile_razy pozostaje 2.

==========================================================

Zadanie 1 - Kod

#include <iostream>
#include <vector> 
#include <map>
#include <algorithm>
using namespace std;

// Zadanie 1
pair<int, int> MostFrequent(const vector<int>& vector) {

    map<int, int> ile_jest; // Mapa do przechowywania liczby wystąpień
    for (int n : vector) { // Zliczanie wystąpień
        ile_jest[n]++; // Zwiększ licznik dla danej liczby
    }
    int ile_unikalne = ile_jest.size(); // Liczba unikalnych liczb w wektorze



    int ile_razy = 0;
    for (const auto& pair : ile_jest) {
        // pair.first to liczba, pair.second to liczba wystąpień
        if (pair.second > ile_razy) {
            ile_razy = pair.second; // Aktualizacja maksymalnej liczby wystąpień
        }
    }


    return {ile_unikalne, ile_razy}; // Zwrócenie pary wyników
}
// Zadanie 1 end

int main() {
    // Zadanie 1
    vector<int> zestaw = {1,2,3,4,5,5,5,4,3,2,1}; // Przykładowy wektor liczb
    pair<int, int> wynik = MostFrequent(zestaw); //wywołanie funkcji
    cout << "unikalne liczby: " << wynik.first << endl;
    cout << "ile wystąpień najczęstszej liczby: " << wynik.second <<endl;
    // Zadanie 1 - end
    return 0;
}
=================================================================================

Zadanie 2

#include <iostream>
#include <vector> 
#include <map>
#include <algorithm>
//Zadanie2
#include <fstream>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

// Zadanie 1
pair<int, int> MostFrequent(const vector<int>& vector) {

    map<int, int> ile_jest; // Mapa do przechowywania liczby wystąpień
    for (int n : vector) { // Zliczanie wystąpień
        ile_jest[n]++; // Zwiększ licznik dla danej liczby
    }
    int ile_unikalne = ile_jest.size(); // Liczba unikalnych liczb w wektorze

    int ile_razy = 0;
    for (const auto& pair : ile_jest) {
        // pair.first to liczba, pair.second to liczba wystąpień
        if (pair.second > ile_razy) {
            ile_razy = pair.second; // Aktualizacja maksymalnej liczby wystąpień
        }
    }

    return { ile_unikalne, ile_razy }; // Zwrócenie pary wyników
}
// Zadanie 1 end

// Zadanie 2
void Prepare(const string& file_name) {

    // Odczytanie zawartości pliku
    ifstream odczyt_pliku(file_name);
    //otwarty poprawnie?
    if (!odczyt_pliku.is_open()) {
        cerr << "Blad" << file_name << endl;
        return;
    }
    //mapa do przechowywania przystankow, i string do linii
    unordered_map<string, set<string>> przystanki;
    string linia, linia_akt;

    while (getline(odczyt_pliku, linia)) { //Odczytuje każdą linię z pliku.
        if (linia.rfind("LINIA", 0)==0) { //Sprawdza, czy linia zaczyna się od "LINIA".
            linia_akt = "Linia" + linia.substr(5); // Łączy stały ciąg "Linia" z resztą ciągu po "LINIA".
        }
        else {
            przystanki[linia].insert(linia_akt); //Dodaje numer linii do przystanków (mapy)
        }
    }
    odczyt_pliku.close();

    // Wyświetlenie zawartości struktury danych na ekranie
    for (const auto& przystanek : przystanki) { //przechodzi przez mape przystanki
        cout << "#" << przystanek.first << endl; //Wyświetla nazwę przystanku.
        for (const auto& linia : przystanek.second) { //Przechodzi przez zbiór numerów linii.
            cout << linia << endl; //Wyświetla numer linii.
        }
        cout << "----------------------" << endl;
    }

    // Zapisanie zawartości struktury danych do plików
    for (const auto& przystanek : przystanki) { //Przechodzi przez mapę przystanków.
        string file_name = przystanek.first + ".txt"; //txt
        ofstream nowyPlik(file_name); // Tworzy plik o nazwie przystanku.
        if (nowyPlik.is_open()) {
            for (const auto& linia : przystanek.second) {
                nowyPlik << linia << endl; //Zapisuje numer linii do pliku.
            }
            nowyPlik.close();
        }
        else {
            cerr << "Nie można otworzyć pliku: " << przystanek.first << endl;
        }
    }
    return;
}

// Zadanie 2 - end

int main() {
    // Zadanie 1
    vector<int> zestaw = { 1,2,3,4,5,5,5,4,3,2,1 }; // Przykładowy wektor liczb
    pair<int, int> wynik = MostFrequent(zestaw); // wywołanie funkcji
    cout << "unikalne liczby: " << wynik.first << endl;
    cout << "ile wystąpień najczęstszej liczby: " << wynik.second << endl;
    // Zadanie 1 - end

    // Zadanie 2
    Prepare("E:\\Użytkownicy\\Pawel\\Desktop\\wiadomosc.txt");
    // Zadanie 2 - end

    return 0;
}
