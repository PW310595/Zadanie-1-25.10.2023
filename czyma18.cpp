#include <iostream>

int main() {
    int dzien, miesiac, rok;
    
    std::cout << "Podaj dzien urodzenia: ";
    std::cin >> dzien;
    
    std::cout << "Podaj miesiac urodzenia: ";
    std::cin >> miesiac;
    
    std::cout << "Podaj rok urodzenia: ";
    std::cin >> rok;
    
    int aktualnyDzien = 20;
    int aktualnyMiesiac = 11;
    int aktualnyRok = 2023;
    
    if((
	(miesiac==1 || miesiac==3 || miesiac==5 || miesiac==7 || miesiac==8 || miesiac==10 || miesiac==12) && (dzien<32 && dzien>0))
	 || 
	 (
	(miesiac==4 || miesiac==6 || miesiac==9 || miesiac==11) && (dzien<31 && dzien>0))
	||
	 ((miesiac==2) && (dzien<29 && dzien>0))){
    	if (aktualnyRok - rok > 18 || (aktualnyRok - rok == 18 && aktualnyMiesiac > miesiac) || (aktualnyRok - rok == 18 && aktualnyMiesiac == miesiac && aktualnyDzien >= dzien))
    {
        std::cout << "Masz 18 lat!" << std::endl;
    }
    else
    {
        std::cout << "Nie masz 18 lat." << std::endl;
    }
	} else {
		std::cout << "Blad danych" << std::endl;
	}
    
    
}
