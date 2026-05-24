#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = NULL;

    p = malloc(sizeof(int));

    if (p == NULL) {
        printf("No se pudo reservar memoria.\n");
        return 1;
    }

    *p = 80;

    printf("Valor = %d\n", *p);

    free(p);
    p = NULL;

    return 0;
}
