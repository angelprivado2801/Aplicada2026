#include <iostream>

void cambiar(int* p) {
    if (p == nullptr) {
        return;
    }
    *p = 100;
}

int main() {
    int x = 5;
    
    std::cout << "Antes: x = " << x << "\n";
    cambiar(&x);
    std::cout << "Despues: x = " << x << "\n";
    
    return 0;
}
