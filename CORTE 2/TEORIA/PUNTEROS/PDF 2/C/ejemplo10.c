#include <stdio.h>

void intercambiar(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Dentro de intercambiar: a = %d, b = %d\n", a, b);
}

int main(void) {
    int x = 10;
    int y = 20;
    
    printf("Antes: x = %d, y = %d\n", x, y);
    intercambiar(x, y);
    printf("Despues: x = %d, y = %d\n", x, y); // x e y no cambian
    
    return 0;
}
