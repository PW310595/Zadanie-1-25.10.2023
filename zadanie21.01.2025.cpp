/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////grupaE

// NumberSequence.h
#ifndef NUMBERSEQUENCE_H
#define NUMBERSEQUENCE_H

#include <string>
#include <sstream>

// Abstrakcyjna klasa reprezentująca ciąg liczbowy
class NumberSequence {
private:
    std::string type; // Prywatny łańcuch znakowy przechowujący typ ciągu

public:
    // Konstruktor ustawiający typ ciągu
    NumberSequence(const std::string& type) : type(type) {} //•	Konstruktor klasy NumberSequence, który inicjalizuje pole type przekazanym argumentem.

    // Metoda czysto wirtualna wyznaczająca n-ty wyraz ciągu
    virtual int calc_nth(int n) const = 0; //•	const oznacza, że metoda nie zmienia stanu obiektu.

    // Metoda zwracająca łańcuch znakowy zawierający typ ciągu i pierwszych 15 wyrazów
    std::string as_string() const {
        std::ostringstream oss;
        oss << "Typ ciągu: " << type << "\nPierwsze 15 wyrazów: ";
        for (int i = 1; i <= 15; ++i) {
            oss << calc_nth(i) << " ";
        }
        return oss.str();
    }
  /*
  •	Deklaracja metody as_string, która zwraca łańcuch znakowy zawierający typ ciągu i pierwszych 15 wyrazów.
•	std::ostringstream oss; - Tworzy strumień pamięciowy.
•	oss << "Typ ciągu: " << type << "\nPierwsze 15 wyrazów: "; - Dodaje typ ciągu do strumienia.
•	Pętla for iteruje od 1 do 15, wywołując calc_nth(i) i dodając wynik do strumienia.
•	return oss.str(); - Zwraca zawartość strumienia jako łańcuch znakowy.
  */

    // Wirtualny destruktor
    virtual ~NumberSequence() {} //•	Deklaracja wirtualnego destruktora, co zapewnia poprawne niszczenie obiektów pochodnych.
};

#endif // NUMBERSEQUENCE_H





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////grupaC

// Geometry.h
#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <string>
#include <sstream>
#include <iomanip>

class Geometry {
private:
    std::string name; //Prywatne pole name przechowuje nazwę figury geometrycznej jako łańcuch znaków.

public:
//spróbuj bez konstruktowa wpierw xd
    Geometry(const std::string& name) : name(name) {} //Konstruktor klasy Geometry, który inicjalizuje pole name przekazanym argumentem.
    virtual ~Geometry() {}

    virtual double perimeter() const = 0; // Metoda czysto wirtualna
    virtual double area() const = 0; // Metoda czysto wirtualna

    std::string toString() const {
        std::ostringstream oss; //moze byc cos innego niz oss
       // oss << std::fixed << std::setprecision(2); do zmienno przecinkowych (fixed powoduje, ze setprecision dziala do dwoch miejsc po przecinku) setprecision(2) - do dwoch liczb znaczacych
        oss << "Figura: " << name << ", Obwód: " << perimeter() << ", Pole: " << area(); //zmienna i metody dodane do strumienia
        return oss.str(); //•	Zwrócenie zawartości strumienia oss jako łańcucha znakowego (std::string). Metoda str() konwertuje zawartość strumienia na łańcuch znakowy.


//Zapewnij, że metody nie będą zmieniały obiektu, na rzecz którego są wywoływane -- dodanie const
      //Metoda toString, która zwraca łańcuch znaków zawierający nazwę figury, jej obwód i pole.
//Publiczna metoda niewirtualna to metoda, która jest dostępna dla wszystkich użytkowników klasy, ale nie może być przesłonięta przez klasy pochodne
   
//Listy inicjalizacyjne w C++ to sposób inicjalizacji składowych klasy bezpośrednio w momencie tworzenia obiektu. Używając list inicjalizacyjnych, można efektywnie i czytelnie przypisywać wartości do składowych klasy.
//Listy inicjalizacyjne są umieszczone po dwukropku : i przed ciałem konstruktora. Pozwalają one na bezpośrednie przypisanie wartości do składowych klasy w momencie tworzenia obiektu.
//Składowe klasy (ang. class members) to elementy, które są zdefiniowane wewnątrz klasy

//Konstruktor parametryczny to konstruktor, który przyjmuje argumenty i używa ich do inicjalizacji składowych klasy. Wykorzystuje listę inicjalizacyjną do przypisania wartości do składowej name.

•	Geometry(const std::string& name): Definicja konstruktora, który przyjmuje jeden argument typu const std::string&. Argument ten jest przekazywany przez referencję, co unika kopiowania.
•	: name(name): Lista inicjalizacyjna, która inicjalizuje składową name wartością przekazaną jako argument name. Dzięki temu składowa name jest bezpośrednio inicjalizowana wartością argumentu, co jest bardziej efektywne niż przypisanie w ciele konstruktora.



//Konstruktor kopiujący tworzy nowy obiekt jako kopię istniejącego obiektu. Kopiuje wartości składowych z jednego obiektu do drugiego. Wykorzystuje listę inicjalizacyjną do przypisania wartości składowej name z innego obiektu.
 

•	Geometry(const Geometry& other): Definicja konstruktora kopiującego, który przyjmuje jeden argument typu const Geometry&. Argument ten jest referencją do innego obiektu Geometry, który ma być skopiowany.
•	: name(other.name): Lista inicjalizacyjna, która inicjalizuje składową name wartością składowej name z obiektu other. Dzięki temu nowy obiekt Geometry będzie miał taką samą wartość składowej name jak obiekt other.



//Konstruktor przenoszący tworzy nowy obiekt, przenosząc zasoby z innego obiektu. Zamiast kopiować wartości, przenosi je, co jest bardziej efektywne. Wykorzystuje listę inicjalizacyjną do przeniesienia wartości składowej name z innego obiektu.
W konstruktorze przenoszącym other.name odnosi się do składowej name obiektu other, który jest argumentem konstruktora. Nazwa other jest nazwą argumentu, a name jest składową klasy Geometry. Można to zmienić na dowolną inną nazwę, ale ważne jest, aby zrozumieć, że other reprezentuje obiekt, z którego przenosimy zasoby.

1.	Geometry(Geometry&& other):
•	Geometry&&: Typ argumentu to referencja do r-wartości (rvalue reference). R-wartość to tymczasowy obiekt, który może być przeniesiony.
•	other: Nazwa argumentu, który jest obiektem, z którego przenosimy zasoby.
2.	noexcept:
•	Słowo kluczowe noexcept oznacza, że konstruktor nie zgłasza wyjątków. Jest to ważne dla optymalizacji i bezpieczeństwa.
3.	: name(std::move(other.name)):
•	Lista inicjalizacyjna: Używana do bezpośredniego inicjalizowania składowych klasy.
•	std::move(other.name): Funkcja std::move konwertuje other.name na r-wartość, co pozwala na przeniesienie zasobów zamiast ich kopiowania. std::move nie przenosi danych sam w sobie, ale oznacza, że dane mogą być przeniesione.

Geometry g1("Kwadrat");
Geometry g2(std::move(g1)); // Konstruktor przenoszący

•	g2 jest tworzony przy użyciu konstruktora przenoszącego.
•	Zasoby (np. pamięć przechowująca nazwę "Kwadrat") są przenoszone z g1 do g2.
•	g1 jest pozostawiony w stanie "pustym" lub "przeniesionym", co oznacza, że jego zasoby zostały przeniesione do g2.



//podsumowanie
/* •	Konstruktor parametryczny: Geometry(const std::string& name) : name(name) {} - Inicjalizuje składową name wartością przekazaną jako argument.
•	Konstruktor kopiujący: Geometry(const Geometry& other) : name(other.name) {} - Kopiuje wartość składowej name z innego obiektu Geometry.
•	Konstruktor przenoszący: Geometry(Geometry&& other) noexcept : name(std::move(other.name)) {} - Przenosi wartość składowej name z innego obiektu Geometry przy użyciu std::move, co jest bardziej efektywne niż kopiowanie.
*/


}
};

#endif // GEOMETRY_H


ZADANIE 2 - C

#include <iostream>
#include <string>
#include <utility> // dla std::move

class Geometry {
private:
    std::string name;

public:
    // Konstruktor parametryczny
    Geometry(const std::string& name) : name(name) {}

    // Konstruktor kopiujący
    Geometry(const Geometry& other) : name(other.name) {}

    // Konstruktor przenoszący
    Geometry(Geometry&& other) noexcept : name(std::move(other.name)) {}

    // Metoda toString
    std::string toString() const {
        std::ostringstream outputStream;
        outputStream << "Figura: " << name;
        return outputStream.str();
    }
};
