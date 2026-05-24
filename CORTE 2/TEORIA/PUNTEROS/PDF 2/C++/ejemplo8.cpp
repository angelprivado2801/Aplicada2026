#include <iostream>

void intercambiar(int* a, int* b) {
    if (a == nullptr || b == nullptr) {
        return;
    }
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10;
    int y = 20;
    
    std::cout << "Antes: x = " << x << ", y = " << y << "\n";
    intercambiar(&x, &y);
    std::cout << "Despues: x = " << x << ", y = " << y << "\n";
    
    return 0;
}
