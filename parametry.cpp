
#include <iostream>
#include <string>


void my_swap_1(int* a, int* b) {
    int wynik;
    wynik = *a;
    *a = *b;
    *b = wynik;

}

void zerowanie(int* a) {

    (*a) = 0;
}
int main()
{
    int a1, a2;
    std::cout << "Zadanie 2 " << std::endl;
    a1 = 10;
    a2 = 20;
    int* n1 = &a1;
    int* n2 = &a2;
    my_swap_1(n1, n2);
    std::cout << *n1 << "  " << *n2;

    int zmienna = 101;
    zerowanie(&zmienna);
    std::cout << " " << zmienna;

}
