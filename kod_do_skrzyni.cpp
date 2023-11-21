#include <iostream>

int main() {
    int ZaszyfrowanyKod[12] = {11, 10, 96, 43, 15, 17, 55, 17, 55, 19, 13, 17};
    
    int pierwsza = 0;
    int druga = 0;
    int trzecia = 0;
    int czwarta = 0;
    int z = 0;
  	 int z1 = 0;
   
    for (int i = 0; i < 12; ++i) {
        if (ZaszyfrowanyKod[i] % 10 % 2 == 1) {
            if (z == 0) {
                pierwsza = ZaszyfrowanyKod[i] / 10;
                z++;
            } else if (z == 1) {
                druga = ZaszyfrowanyKod[i] / 10;
                z++;
                break;
            }
        }
    }

    for (int i = 11; i >= 0; --i) {
        if (ZaszyfrowanyKod[i] % 10 % 2 == 1) {
            if (z1 == 0) {
                czwarta = ZaszyfrowanyKod[i] / 10;
                z1++;
            } else if (z1 == 1) {
                trzecia = ZaszyfrowanyKod[i] / 10;
                z1++;
                break;
            }
        }
    }

    std::cout << "Kod otwierający skrzynię: " << pierwsza << " " << druga << " " << trzecia << " " << czwarta << std::endl;

    return 0;
}
