#include <iostream>

int main() {
    char letter = 'a'; 

    std::cout << "Alfabet: ";
    for (int i = 0; i < 26; ++i) {
        std::cout << letter << " ";
        letter=letter+1; 
    }
    std::cout << std::endl;

    return 0;
}
