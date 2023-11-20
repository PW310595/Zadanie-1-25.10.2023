#include <iostream>
using namespace std;

int main() {
    string msg = "Tajna wiadomosc";
    int s = 3;

    for (int i = 0; i < msg.length(); i++) {
        if (isalpha(msg[i])) {
            if (isupper(msg[i])) {
                msg[i] = char(int(msg[i] + s - 65) % 26 + 65);
            } else {
                msg[i] = char(int(msg[i] + s - 97) % 26 + 97);
            }
        }
    }

    cout << "Zaszyfrowana wiadomoœæ: " << msg << endl;

    return 0;
}
