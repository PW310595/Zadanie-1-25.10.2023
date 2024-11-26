Szablony funkcji pozwalają na definiowanie funkcji, które mogą działać z różnymi typami danych.
Pozwala nie przeciazac funkcji, w  sensie szablony przyjumją dowolny typ danych
template <typename Typ> Kompilator sam wybiera sobie typ
======================================
using namespace std;
template < int ilosc >
class tablica_typu_int
{
public:
    int zmienna[ ilosc ]; //nasza ilosc
    int zmienna_zawierajaca_prawidlowa_ilosc; //tym zajmiemy się w jednej funkcji z klasy, przydatna do jednego z warunków w przyszłości
    void uzupelnij( int ktora )
    {
        cin >> zmienna[ ktora ];
    }
    void pokaz( int ktora )
    {
        cout << zmienna[ ktora ] << endl;
    }
    int wielkosc()
    {
        return ilosc;
    }
    void nadaj_prawidlowa_ilosc()
    {
        zmienna_zawierajaca_prawidlowa_ilosc = ilosc;
    }
};
int main()
{
    tablica_typu_int < 11 > nowa; //ustalamy
    nowa.nadaj_prawidlowa_ilosc();
    int a = 0;
    cout << "Nasza tablica to: " << nowa.wielkosc() << " elementow." << endl << endl;
    while( a < nowa.zmienna_zawierajaca_prawidlowa_ilosc ) //właśnie tu
    {
        nowa.uzupelnij( a );
        nowa.pokaz( a );
        cout << a << endl;
        a++;
    }
    cout << "Operacja ukończona - " << a << endl;
}
==============================================================================================

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << max(10, 20) << std::endl; // działa dla int
    std::cout << max(3.14, 2.71) << std::endl; // działa dla double
    std::cout << max('a', 'z') << std::endl; // działa dla char
}
=========================================================================================!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include <iostream>
using namespace std;
template <typename Typ> #tworze wlasny typ
void wyswietl(Typ x){
  cout << x;
}
int main(){
wyswietl('k')
//wyswietl('12.543')
//wyswietl('12')
return 0;
}
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include <iostream>
using namespace std;
template <typename Typ> #tworze wlasny typ
Typ wyswietl(Typ x){  //dla return x, void zmieniamy dla Typ, bo void nic nie zwraca
  return x;
}
int main(){
cout << wyswietl('k')
//wyswietl('12.543')
//wyswietl('12')
return 0;
}
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include <iostream>
using namespace std;
template <typename Typ> #tworze wlasny typ
Typ wyswietl(Typ x,Typ y){  //dla return x, void zmieniamy dla Typ, bo void nic nie zwraca
  return x+y;
}
int main(){
cout << wyswietl(24.12, 12.24);
return 0;
}
