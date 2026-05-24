#include <iostream>

int contadorGlobal = 0;

void contar() {
    int contadorLocalNormal = 0;

    static int contadorLocalEstatico = 0;

    contadorGlobal++;
    contadorLocalNormal++;
    contadorLocalEstatico++;

    std::cout << "Global         = " << contadorGlobal << std::endl;
    std::cout << "Local normal   = " << contadorLocalNormal << std::endl;
    std::cout << "Local static   = " << contadorLocalEstatico << std::endl;
    std::cout << "--------------------------" << std::endl;
}

int main() {
    contar();
    contar();
    contar();

    return 0;
}
