#include <iostream>
#include <vector>

int main() {

	std::vector<int> liczba;
	liczba.push_back(5);
	liczba.push_back(-1);
	liczba.push_back(10);

	std::cout << liczba[2];
}
