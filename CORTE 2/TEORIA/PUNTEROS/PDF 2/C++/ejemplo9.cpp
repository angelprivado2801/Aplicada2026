#include <iostream>

int sumar(int a, int b) {
    return a + b;
}

int main() {
    int resultado = sumar(4, 7);
    std::cout << "Resultado = " << resultado << "\n";
    
    return 0;
}
