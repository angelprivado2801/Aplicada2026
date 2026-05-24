#include <iostream>

void analizarNumeros(int a, int b, int c, int* suma, int* mayor, int* menor) {
    if (suma == nullptr || mayor == nullptr || menor == nullptr) {
        return;
    }

    *suma = a + b + c;

    *mayor = a;
    if (b > *mayor) *mayor = b;
    if (c > *mayor) *mayor = c;

    *menor = a;
    if (b < *menor) *menor = b;
    if (c < *menor) *menor = c;
}

int main() {
    int x = 8, y = 3, z = 15;
    int suma, mayor, menor;

    analizarNumeros(x, y, z, &suma, &mayor, &menor);

    std::cout << "Suma = " << suma << "\n";
    std::cout << "Mayor = " << mayor << "\n";
    std::cout << "Menor = " << menor << "\n";

    return 0;
}
