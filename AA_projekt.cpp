#include <iostream>
//Zapis Element<T> oznacza użycie klasy szablonowej Element z konkretnym typem T.
//Dzięki temu możemy tworzyć elastyczne i wielokrotnego użytku struktury danych
//W powyższym przykładzie zarówno Element jak i List są klasami szablonowymi, 
//więc każda z nich ma swoją własną deklarację template<typename T>.
//-----------------------------------------

//Zad 1 Element(T dane_1, Element<T>* wsk_next_ele_1 = nullptr) : dane(dane_1), wsk_next_ele(wsk_next_ele_1) {}
//nullptr - pusty wskaźnik
//wsk_next_ele przechowuje adres kolejnego elementu listy, który jest obiektem klasy Element.

//Zad 2 Bez & w T& operator*(): Uzyskałbyś kopię, a zmiany nie dotknęłyby oryginalnych danych.
//Referencja(&) - pobiera adres, odwołanie do oryginału 
//Dereferencja(*) -pozwala na uzyskanie wartości przechowywanej pod adresem wskaźnika

//Zad 3 zamiast int napisać size_t -  size_t jest specjalnie zaprojektowany do przechowywania rozmiarów i indeksów, jest typem całkowitym bez znaku, co oznacza, że może przechowywać tylko wartości nieujemne

//Zad 4  poprawić jeśli trzeba size_t OdczytLiczbaElementow() const {  ... int OdczytLiczbaElementow() const {return liczba_elementow;}
//List() : pierwszy(nullptr), ostatni(nullptr), liczba_elementow(0) {}
//bezargumentowy - List() : pierwszy(nullptr), ostatni(nullptr), liczba_elementow(0) {}
//argumentowy - List(Element<T>* pierwszyElement, Element<T>* ostatniElement, int liczbaElementow): pierwszy(pierwszyElement), ostatni(ostatniElement), liczba_elementow(liczbaElementow) {}

//Zad5 void add {//	liczba_elementow++;} ??-----------------------
//Linia ostatni->UstawNext(NowyEle); ustawia wskaźnik wsk_next_ele ostatniego elementu w liście na nowo utworzony element NowyEle.
//Dzięki temu nowy element zostaje dodany na końcu listy,
//a poprzedni ostatni element teraz wskazuje na ten nowy element jako na swój następny element.

//Debugowanie
//Podwójna dereferencja **current: Pierwsza dereferencja *current zwraca referencję do przechowywanej wartości typu T 
//(w tym przypadku int). Druga dereferencja **current`` uzyskuje wartość przechowywaną w elemencie,
//którą można bezpośrednio wyświetlić za pomocą operatora <<`.

//Destruktor klasy List jest odpowiedzialny za poprawną dealokację pamięci,
//aby uniknąć wycieków pamięci. W przypadku listy dynamicznej, 
//  każdy element listy jest alokowany dynamicznie za pomocą operatora new, 
//  więc musimy upewnić się, że każdy z tych elementów zostanie
//poprawnie zwolniony za pomocą operatora delete.

//Podsumowanie - Destruktor iteruje przez całą listę, usuwając każdy element po kolei. 
//Dzięki temu wszystkie dynamicznie alokowane elementy listy są poprawnie zwalniane, 
// co zapobiega wyciekom pamięci.

#include <iostream>
using namespace std;
//Zadanie 1
namespace data_structures {

	template<typename T>

	class Element {
	private:
		T dane; //dana typu T
		Element* wsk_next_ele;

	public:
		//konstruktor

		Element(T dane_1, Element* wsk_next_ele_1) : dane(dane_1), wsk_next_ele(wsk_next_ele_1) {}
//Zadanie 2
		//akcesory dla wskaźnika na kolejny element listy
		//Setter i Getter

		void UstawNext(Element* wsk_next_ele_2){
			wsk_next_ele = wsk_next_ele_2;
		}

		Element* OdczytNext(){
			return wsk_next_ele;
		}

		//operator dereferencji * zwracający referencję na przechowywaną daną typu T
		T& operator*() {
			return dane;
		}
	};

//Zadanie 3
    template<typename T> //deklaracja szablonowa dla List
    class List {
    private:
        Element<T>* pierwszy;
        Element<T>* ostatni;
        int liczba_elementow;

    public:
//Zadanie 4
		//konstruktor bezargumentowy inicjalizujący składowe tak,
		// by zapewnić poprawność działania listy. nullptr - pusty wskaźnik
		List() : pierwszy(nullptr), ostatni(nullptr), liczba_elementow(0) {}
		//pusty destruktor,
		~List() {}
		//akcesory do pobierania wartości pól prywatnych - Gettery
		Element<T>* OdczytPierwszy() const {
			return pierwszy;
		}

		Element<T>* OdczytOstatni() const {
			return ostatni;
		}

		void OdczytLiczbaElementow(int& liczba) const {
			liczba = liczba_elementow;
			cout << liczba << endl;
		}

//Zadanie 5

void add(T dane) {
    Element<T>* NowyEle = new Element<T>(dane, nullptr); //nowy element
    if (ostatni != nullptr) { //sprawdzenie czy lista nie jest pusta
        ostatni->UstawNext(NowyEle);
    }
    else {
        pierwszy = NowyEle; //pierwszy element, teoretycznie ostatni
    }
    ostatni = NowyEle;
   // liczba_elementow++;
}

    };
}

	//Zadanie 5 Zapewnij poprawną dealokację pamięci przy destrukcji obiekt
	
	~List() {
		Element<T>* aktualny_ele = pierwszy;
		while (aktualny_ele != nullptr) { //dopóki lista nie jest pusta
			Element<T>* next_ele = aktualny_ele->OdczytNext();//odczyt aktualnego elementu
			delete aktualny_ele; //usuniecie
			aktualny_ele = next_ele; //sprawdzenie nastepnego
		}
	}
//Zadanie 6 i 7?????????
#include <string> 
u góry pod data_structures
zadanie 7 dodać do listu: public ISerializable

1/2
    class ISerializable {
    public:
        virtual std::string save() const = 0;

        friend std::ostream& operator<<(std::ostream& os, const ISerializable& obj) {
            return os << obj.save();
        }
    };
//save()
//•	Jest to czysto wirtualna metoda (= 0), co oznacza, że każda klasa dziedzicząca po ISerializable musi zaimplementować tę metodę.
//•	Metoda save() ma zwracać std::string, który reprezentuje serializowaną wersję obiektu.
<<
//•	Jest zdefiniowany jako funkcja zaprzyjaźniona (friend), co pozwala jej na dostęp do prywatnych i chronionych członków klasy.
//•	Operator << wywołuje metodę save() na obiekcie ISerializable i zwraca strumień wyjściowy (os), co umożliwia łatwe wypisywanie obiektów na standardowe wyjście lub do pliku.
2/2
   std::string save() const override {
     std::string result;
     Element<T>* aktualny_ele = pierwszy;
     while (aktualny_ele != nullptr) {
         result += std::to_string(*aktualny_ele) + " ";
         aktualny_ele = aktualny_ele->OdczytNext();
     }
     return result;
 }
//1.	Deklaracja metody:
//•	Metoda save() jest oznaczona jako override, co oznacza, że nadpisuje wirtualną metodę save() z interfejsu ISerializable.
//2.	Tworzenie wyniku:
//•	Tworzony jest pusty std::string o nazwie result, który będzie zawierał serializowaną wersję listy.
//3.	Iteracja przez elementy listy:
//•	Używana jest zmienna aktualny_ele, która początkowo wskazuje na pierwszy element listy.
//•	Pętla while iteruje przez wszystkie elementy listy, dopóki aktualny_ele nie jest nullptr.
//4.	Serializacja elementów:
//•	W każdej iteracji, metoda std::to_string(*aktualny_ele) konwertuje wartość przechowywaną w aktualnym elemencie na std::string i dodaje ją do result, wraz ze spacją.
//•	aktualny_ele jest aktualizowany do następnego elementu w liście za pomocą OdczytNext().
//5.	Zwracanie wyniku:
//•	Po zakończeniu iteracji, result zawiera serializowaną wersję całej listy i jest zwracany jako wynik metody save().
========================================================================== main.cpp
#include <iostream>
#include ".h"
using namespace std;
int main() {
    data_structures::List<int> lista;
    // Dodawanie elementów do listy
    lista.add(1);
    lista.add(2);
    lista.add(3);

   // int liczbaElementow;
    //lista.OdczytLiczbaElementow(liczbaElementow);
    //cout << "liczbaElementow: " << liczbaElementow << endl;

    // Debugowanie
    data_structures::Element<int>* aktualny_ele = lista.OdczytPierwszy();
    while (aktualny_ele != nullptr) {
        cout << **aktualny_ele << endl;
        aktualny_ele = aktualny_ele->OdczytNext();
    }
    return 0;
}

