#include <stdio.h>
#include <stddef.h>

void analizarNumeros(int a, int b, int c, int *suma, int *mayor, int *menor) {
    if (suma == NULL || mayor == NULL || menor == NULL) return;

    *suma = a + b + c;

    *mayor = a;
    if (b > *mayor) *mayor = b;
    if (c > *mayor) *mayor = c;

    *menor = a;
    if (b < *menor) *menor = b;
    if (c < *menor) *menor = c;
}

int main(void) {
    int x = 8, y = 3, z = 15;
    int suma, mayor, menor;

    analizarNumeros(x, y, z, &suma, &mayor, &menor);

    printf("Suma = %d\n", suma);
    printf("Mayor = %d\n", mayor);
    printf("Menor = %d\n", menor);

    return 0;
}
