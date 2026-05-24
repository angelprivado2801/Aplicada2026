#include <iostream>

int main() {
    int x = 25;
    int *p = &x;

    std::cout << "x = " << x << std::endl;
    std::cout << "&x = " << (void *)&x << std::endl;
    std::cout << "p = " << (void *)p << std::endl;
    std::cout << "*p = " << *p << std::endl;

    return 0;
}
