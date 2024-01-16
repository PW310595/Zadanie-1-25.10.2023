struct Punkty {

    double punkt_x;
    double punkt_y;
    double punkt_r;
};


double Punkt(Punkty a1, Punkty a2) {
    double d;
        d = sqrt((((a2.punkt_x - a1.punkt_x) * (a2.punkt_x - a1.punkt_x)) + ((a2.punkt_y - a1.punkt_y) * (a2.punkt_y - a1.punkt_y))));
    return d;
}

int main(){
 Punkty a1 = { 6,8 };
    Punkty a2 = { 0,0 };
    double K1;
    K1 = Punkt(a1, a2);
    std::cout << K1;
    std::cout << " " << std::endl;

}
