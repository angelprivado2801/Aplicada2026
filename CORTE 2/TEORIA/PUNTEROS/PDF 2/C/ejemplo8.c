#include <stdio.h>

void cambiar(int n) {
    n = 100;
    printf("Dentro de cambiar: n = %d\n", n);
}

int main(void) {
    int x = 5;
    
    printf("Antes: x = %d\n", x);
    cambiar(x);
    printf("Despues: x = %d\n", x); // x no cambia
    
    return 0;
}
