#include <iostream>

int main() {
    int x = 25;
    int* p = &x;

    std::cout << "x = " << x << "\n";
    std::cout << "*p = " << *p << "\n";

    *p = 99;

    std::cout << "x despues = " << x << "\n";

    return 0;
}
