#include <iostream>

int main() {
    int datos[3] = {10, 20, 30};
    int* p = datos;

    std::cout << "datos[0] = " << datos[0] << "\n";
    std::cout << "*p = " << *p << "\n";
    std::cout << "*(p+1) = " << *(p+1) << "\n";
    std::cout << "*(p+2) = " << *(p+2) << "\n";

    return 0;
}
