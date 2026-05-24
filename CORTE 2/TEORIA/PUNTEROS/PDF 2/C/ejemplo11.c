#include <stdio.h>

int sumar(int a, int b) {
    return a + b;
}

int main(void) {
    int resultado = sumar(4, 7);
    printf("Resultado = %d\n", resultado);
    
    return 0;
}
