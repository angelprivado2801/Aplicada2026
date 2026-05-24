#include <stdio.h>

int main(void) {
    int datos[3] = {10, 20, 30};
    int *p = datos; // p apunta al primer elemento del arreglo

    printf("datos[0] = %d\n", datos[0]);
    printf("*p = %d\n", *p);
    printf("*(p+1) = %d\n", *(p+1));
    printf("*(p+2) = %d\n", *(p+2));

    return 0;
}
