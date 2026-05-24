#include <stdio.h>

int main(void) {
    int x = 25;
    int *p = &x; // p guarda la dirección de x

    printf("x = %d\n", x);
    printf("&x = %p\n", (void *)&x);
    printf("p = %p\n", (void *)p);
    printf("*p = %d\n", *p);

    *p = 99; // Modifica x indirectamente mediante el puntero p
    printf("x despues = %d\n", x);

    return 0;
}
