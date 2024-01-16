#include <iostream>
//using namespace std;
//std::to_string(s) - good to know
int main(){
// Mno¿enie - Dzia³anie matematyczne
	
	/*
	double a,b,c;
	std:: cout << "Wprowadz a i b: \n";
    std::cin >> a >> b;
    std:: cout << "Wynik mnozenia a * b: \n";
    std:: cout << a*b << std::endl;
    std:: cout << "Wynik dzielenia a / b: \n";
    c = a/b;
    std:: cout << c << std::endl;
    */
    //std::setprecision(10)
    
// Size of zmienna
    //std:: cout << sizeof(b);
    

// Znaki i liczby (Char, Int)
    
    /*
    char znak;
    std:: cout << "Wprowadz znak: \n";
    std::cin >> znak;
    std:: cout << "Znak: " << char(znak) << std::endl;
    std:: cout << "Wartosc: " << int(znak) << std::endl;
    */
   
// IF - warunek
/*
	int a,b;
	std:: cout << "Wprowadz a i b: \n";
    std::cin >> a >> b;
    if(a > b){
    	std:: cout << "A jest wieksze od B: \n" << a << " > " << b <<std::endl;
	} else {
		std:: cout << "B jest wieksze od A: \n" << b << " > " << a <<std::endl;
	}
	*/
	
//FOR - pêtla
	/*
	int a;
	std:: cout << "Wprowadz a: \n";
    std::cin >> a;
    std:: cout << "Petla: \n";
	for(int x(1); x <= 8; x++){
		std:: cout << a*x << std::endl;
	}
	*/
	
//WHILE - pêtla
	/*
	int a,x;
	x=1;
	std:: cout << "Wprowadz a: \n";
    std::cin >> a;
	std:: cout << "Petla: \n";
	while(x<=8){
		std:: cout << a*2*x << std::endl;
		x++;
	}
	*/

//DO WHILE - pêtla

	/*
	int a,x;
	x=1;
	std:: cout << "Wprowadz a: \n";
    std::cin >> a;
	std:: cout << "Petla: \n";
	do{ std:: cout << a*2*x << std::endl;
		x++;
	}while(x<=8);
/////////////////////

	/*
	int suma;
	int a;
	do{ std:: cout << "Wprowadz a. Dodawanie kolejnych liczb: \n";
    std::cin >> a;
    std::cout << a << "+" << suma << std::endl;
    suma += a;
	std::cout << "Suma: "<< suma << std::endl;}while(suma<500);
    std::cout << "Wynik Ostateczny: "<< suma << std::endl;
    */
// MAX WARTOŒÆ LUB MIN WARTOŒÆ

	/*
	int a[4];
    int n;
    for(int x = 0; x < 4; x++) {
        std::cout << "Wprowadz n dla a[" << x+1 << "] \n";
        std::cin >> n;
        a[x] = n;
    }
    int max = a[0]; 
    for (int x = 1; x < 4; x++) {
        if (a[x] > max) {
            max = a[x];
        }
    }

    std::cout << "Max liczba: \n";
    std::cout << max;
    
	*/
//FIBONACCI
	/*
	int n;
	std:: cout << "WprowadŸ liczbê powtorzen: ";
	std:: cin >> n;
	int w1(1);
	int w2(1);

		for(int i=3; i<=n; i++){
			w2 = w1+w2;
			w1 = w2-w1;
		} 
	std:: cout << w2;
	*/
	
//SILNIA
	//
	int n,s;
	s = 1;
	cout << "WprowadŸ liczbe: _?_! \n";
	cin >> n;
	for (int i=2; i<=n;i++){
		s*=i;}
	cout << "Silnia: " << n << "! = " << s;
}
