#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string msg = "Jestem piratem agrr, az sie boje agrr";
    
   char a;
    while (a != string::npos) {
        msg.replace(a, 4, "AGRR");
        a = msg.find("agrr", a + 3);
    }
    
    cout << msg << endl;
    
    return 0;
}
