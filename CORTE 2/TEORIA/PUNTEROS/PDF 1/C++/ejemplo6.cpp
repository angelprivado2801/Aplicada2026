#include <iostream>

void cambiarSinPuntero(int n) {
    n = 100;
}

void cambiarCoNPuntero(int *p) {
    if (p != nullptr) {
        *p = 100;
    }
}

int main() {
    int x = 5;

    std::cout << "Antes de cambiarSinPuntero: x = " << x << std::endl;
    cambiarSinPuntero(x);
    std::cout << "Desoues de cambiarSinPuntero: x = " << x << std::endl;
    
    std::cout << "Antes de cambiarConPuntero: x = " << x << std::endl;
    cambiarCoNPuntero(&x);
    std::cout << "Despues de cambiarSinPuntero: x = " << x << std::endl;

    return 0;
}
