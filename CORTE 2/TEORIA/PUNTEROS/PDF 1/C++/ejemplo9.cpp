#include <iostream>

int main() {
    int* p = nullptr;

    // Reserva memoria en el Heap para un entero
    p = new (std::nothrow) int; 

    if (p == nullptr) {
        std::cerr << "No se pudo reservar memoria." << std::endl;
        return 1;
    }

    *p = 80;
    std::cout << "Valor = " << *p << std::endl;

    // Libera la memoria
    delete p;
    p = nullptr;

    return 0;
}
