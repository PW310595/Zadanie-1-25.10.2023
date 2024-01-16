#include <iostream>
#include <vector>

int main() {

	int tab[3][3];

	for (int n = 0; n < 3; n++) {
		for (int i = 0; i < 3; i++) {
			std::cin >> tab[n][i];
		}
	}

	std::cout << " " << std::endl;

	for (int n = 0; n < 3; n++) {
		for (int i = 0; i < 3; i++) {
			std::cout << tab[n][i] << std::endl;
		}
	}

}
