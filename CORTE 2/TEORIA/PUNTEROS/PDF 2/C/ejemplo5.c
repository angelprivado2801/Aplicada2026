#include <stdio.h>
#include <stddef.h>

void duplicar(int *p) {
    if (p != NULL) {
        *p = (*p) * 2;
    }
}

void intercambiar(int *a, int *b) {
    if (a == NULL || b == NULL) return;
    int temp = *a;
    *a = *b;
    *b = temp;
}

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
    int x = 10;
    int y = 20;
    int z = 5;
    int *px = &x;
    int suma, mayor, menor;
    int opcion;

    do {
        printf("\n========== MENU CORTO DE PUNTEROS ==========\n");
        printf("1. Mostrar x, &x, px y *px\n");
        printf("2. Duplicar x usando el puntero px\n");
        printf("3. Intercambiar x y y usando punteros\n");
        printf("4. Analizar x, y, z usando punteros de salida\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("x = %d\n", x);
                printf("&x = %p\n", (void *)&x);
                printf("px = %p\n", (void *)px);
                printf("*px = %d\n", *px);
                break;
            case 2:
                printf("Antes: x = %d\n", x);
                duplicar(px);
                printf("Despues: x = %d\n", x);
                break;
            case 3:
                printf("Antes: x = %d, y = %d\n", x, y);
                intercambiar(&x, &y);
                printf("Despues: x = %d, y = %d\n", x, y);
                break;
            case 4:
                analizarNumeros(x, y, z, &suma, &mayor, &menor);
                printf("Suma = %d\n", suma);
                printf("Mayor = %d\n", mayor);
                printf("Menor = %d\n", menor);
                break;
            case 0:
                printf("Fin del programa.\n");
                break;
            default:
                printf("Opcion no valida.\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}
