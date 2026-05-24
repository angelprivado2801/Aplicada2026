#include <stdio.h>

int contadorGlobal = 0;

void contar() {
    int contadorLocalNormal = 0;

    static int contadorLocalEstatico = 0;

    contadorGlobal++;
    contadorLocalNormal++;
    contadorLocalEstatico++;

    printf("Global         = %d\n", contadorGlobal);
    printf("Local normal   = %d\n", contadorLocalNormal);
    printf("Local static   = %d\n", contadorLocalEstatico);
    printf("--------------------------\n");
}

int main() {
    contar();
    contar();
    contar();

    return 0;
}
