#include <iostream>

int main() {
    int* p = nullptr;
    
    if (p != nullptr) {
        std::cout << "Valor = " << *p << "\n";
    } else {
        std::cout << "p no apunta a una direccion valida.\n";
    }
    
    return 0;
}
