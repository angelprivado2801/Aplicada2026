#include<stdio.h>

void analizarNumeros(int a, int b, int c, int *suma, int *mayor, int *menor) {
    *suma = a + b + c;
    
    *mayor = a;
    if (b > *mayor) {
        *mayor = b;
    }
    if(c > *mayor) {
        *mayor = c;
    }

    *menor = a;
    if (b < *menor) {
        *menor = b;
    }
    if (c < *menor) {
        *menor = c;
    }
}
int main(){
    int x = 8;
    int y = 3;
    int z = 15;

    int suma;
    int mayor;
    int menor;

    analizarNumeros(x, y, z, &suma, &mayor, &menor);

    printf("Suma = %d\n", suma);
    printf("Mayor = %d\n", mayor);
    printf("Menor = %d\n", menor);

    return 0;
}
