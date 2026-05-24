#include <iostream>

int main() {
    int x = 25;
    int* p = &x;

    std::cout << "x = " << x << "\n";
    std::cout << "&x = " << &x << "\n";
    std::cout << "p = " << p << "\n";
    std::cout << "*p = " << *p << "\n";

    return 0;
}
