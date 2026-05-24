#include <stdio.h>
#include <stddef.h>

void cambiar(int *p) {
    if (p == NULL) {
        return;
    }
    *p = 100;
}

int main(void) {
    int x = 5;
    
    printf("Antes: x = %d\n", x);
    cambiar(&x);
    printf("Despues: x = %d\n", x); // x cambia exitosamente
    
    return 0;
}
