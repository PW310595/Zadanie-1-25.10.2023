#include <iostream>

void choinka(int P, int K) {
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < P + K - i; j++) {
            std::cout << " ";
        }
        for (int j = 0; j < (2 * i) + 1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < P; i++) {
        for (int j = 0; j < P + K; j++) {
            std::cout << " ";
        }
        	std::cout << "x" << std::endl;
    }
}

int main() {
    int P, K;
    std::cout << "Podaj wysokosc pnia: ";
    std::cin >> P;
    std::cout << "Podaj wysokosc korony: ";
    std::cin >> K;

    choinka(P, K);

    return 0;
}
