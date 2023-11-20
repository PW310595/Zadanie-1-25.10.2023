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


==========================================================================

#include <iostream>

int main() {
    for (int i = 1; i <= 100; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            std::cout << "Aaaa Grrrrrr" << std::endl;
        } else if (i % 3 == 0) {
            std::cout << "Aaaa" << std::endl;
        } else if (i % 5 == 0) {
            std::cout << "Grrrrrr" << std::endl;
        } else {
            std::cout << i << std::endl;
        }
    }

    return 0;
}
