#include <stdio.h>

int main(void) {
    int x = 10;
    
    printf("Valor de x = %d\n", x);
    printf("Direccion de x = %p\n", (void *)&x);
    
    return 0;
}
