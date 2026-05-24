#include <stdio.h>

int *crearNumeroIncorrecto() {
    int x = 50;

    return &x;
}

int main() {
    int *p = crearNumeroIncorrecto();

    printf("Valor = %d\n", *p);

    return 0;
}
