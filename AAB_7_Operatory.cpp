Vector2D operator-() const: Operator unarny - zwraca nowy wektor przeciwny do obecnego, zmieniając znaki współrzędnych x i y
na przeciwne. Na przykład, dla wektora (3, 4), wynik to (-3, -4).

Vector2D operator-(const Vector2D& other) const: Operator binarny - zwraca różnicę między dwoma wektorami. 
  Oblicza ją, odejmując współrzędne x i y wektora other od współrzędnych bieżącego obiektu. Na przykład, dla (3, 4) - (1, 2), wynik to (2, 2).

Vector2D& operator+=(const Vector2D& other): Operator += dodaje wartości x i y wektora other do bieżącego obiektu i 
aktualizuje jego współrzędne. Przykładowo, (3, 4) += (1, 2) zmienia bieżący wektor na (4, 6).

Vector2D operator*(double scalar) const: Operator * przemnaża współrzędne wektora przez skalar scalar i 
zwraca nowy wektor. Przykład: (3, 4) * 2 zwraca (6, 8).

void normalize(): Metoda normalize normalizuje wektor, nadając mu długość 1 (jeśli długość jest różna od 0). 
Przykładowo, wektor (3, 4) po normalizacji to (0.6, 0.8), gdyż jego długość przed normalizacją wynosiła 5.

void show() const: Metoda show wyświetla współrzędne wektora w formacie (x, y).

double dist(const Vector2D& other) const: Metoda dist zwraca odległość między bieżącym wektorem a innym wektorem other, obliczaną jako odległość euklidesowa.
