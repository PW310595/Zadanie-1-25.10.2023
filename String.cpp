
#include <iostream>
#include <string>

int main()
{
    std::string s;
        std::string d = "Witam bardzo serdecznie";
    getline(std::cin, s);
    std::cout << s;
    std::cout << d;

    reverse(s.begin(), s.end());
    std::cout << s;
}
