#include <iostream>

void cambiar(int n) {
    n = 100;
    std::cout << "Dentro de cambiar: n = " << n << "\n";
}

int main() {
    int x = 5;
    
    std::cout << "Antes: x = " << x << "\n";
    cambiar(x);
    std::cout << "Despues: x = " << x << "\n";
    
    return 0;
}
