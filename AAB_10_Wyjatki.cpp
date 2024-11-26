Dobrym przykładem sytuacji wyjątkowej jest niewystarczająca ilość pamięci. Jeśli zażądamy operatorem new więcej pamięci niż możemy dostać, zostanie wyrzucony wyjątek
(Przechwytywanie bledów)

std::logic_error	Ogólny błąd - naruszono założenie, niezmiennik itp.
std::runtime_error	Ogólny bład - bład czasu wykonania (możliwy do wykrycia tylko w czasie wykonania)
std::invalid_argument	Przekazano nieprawidłowy argument
std::domain_error	Bład dziedziny operacji (w sensie matematycznym). Np dzielenie przez zero
std::length_error	Przekroczenie maksymalnego dozwolonego rozmiaru czegoś
std::out_of_range	Argument poza dopuszczalnym zakresem
std::range_error	Przekroczenie zakresu w obliczeniach. Np wynik obliczeń jest poza zakresem docelowego typu
std::overflow_error	Przepełnienie liczby
std::underflow_error	Niedopełnienie liczby

==========================================================================================================
#include <iostream>

using namespace std;

class Animal{
private:
int wiek;
public:
Animal(int w){
  if(w < 0){
    throw -1; //throw - wyrzucanie wyjatku
  }
  if(w > 500){
    throw "Za stary!"
  }
  if(w==199){
    throw 'errorek'
  }
  wiek = w;
  cout << "Wiek: " << wiek << endl;
};

int main(){ //try jest jeden, catch moze byc wiele
try{  //wygenerowanie wyjatku, sprobuj utworzyc taki obiekt, ale.... 
  Animal a(-10); //Animal a(-10) - wiek nie moze byc taki lib Animal a(999)
}            

catch(int e ){ //..... przechwyć wyjatek w razie problemu === x - dowolna nazwa
  cout << "Error: " << e << endl; // e = -1 , bo throw -1
}
catch(const char* x){
  cout << "Message: " << x << endl;
}

catch(...){ //.kropki to sa wszystkie bledy
  cout << "Inny Error" << endl; // e = -1 , bo throw -1
}
  
return 0;
}
===============================================================================================================
pare catch w IF'ie

class Animal {
private:
    int wiek;
public:
    Animal(int w) {
        if (w < 0) {
            throw -1; // Ujemny wiek
        }
        if (w > 500) {
            throw -2; // Zbyt stary
        }
        if (w == 199) {
            throw -3; // Specjalny przypadek
        }
        wiek = w;
        cout << "Wiek: " << wiek << endl;
    }
};

int main() {
    try {
        Animal a(199); // Przykład wieku powodującego wyjątek
    }
    catch (int e) {
        if (e == -1) {
            cout << "Error: wiek nie moze byc ujemny!" << endl;
        } else if (e == -2) {
            cout << "Error: za stary wiek!" << endl;
        } else if (e == -3) {
            cout << "Error: specjalny przypadek wieku 199!" << endl;
        }
    }
    catch (...) {
        cout << "Nieznany blad." << endl;
    }

    return 0;
}



