############################################## getline (cin, który nie zatrzymuje sie przy pierwszej napotkanej spacji)
#include <iostream>
#include <string>

using namespace std;

int main()
{
   cout << "Podaj tekst: ";
   string tekst;
   getline(cin, tekst);
   cout << tekst << endl;
}
##########################################

#include <iostream>
#include <string>

using namespace std;

int main()
{

    cout << "Podaj liczbę: ";
    int liczba;
    cin >> liczba;
    
    cout << "Podaj tekst: ";
    string tekst;
    cin.ignore(); // to wywołanie usunie z bufora znak '\n' pozostawiony przez obiekt "cin"
    getline(cin, tekst);
    
    cout << liczba << ' ' << tekst << endl;

    return 0;
}

###########################################################

