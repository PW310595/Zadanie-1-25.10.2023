#include <iostream>
using namespace std;

void obrus(int size, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if ((i / size) % 2 == 0) {
                if ((j / size) % 2 == 0)
                    cout << "X";
                else
                    cout << "+";
            } else {
                if ((j / size) % 2 == 0)
                    cout << "+";
                else
                    cout << "X";
            }
        }
        cout << endl;
    }
}

int main() {
    int size, width, height;

    cout << "Podaj rozmiar pola (S): ";
    cin >> size;

    cout << "Podaj szerokość (W): ";
    cin >> width;

    cout << "Podaj wysokość (H): ";
    cin >> height;

    obrus(size, width * size, height * size);

    return 0;
}
