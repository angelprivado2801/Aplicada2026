#include <stdio.h>

void cambiarSinPuntero(int n) {
    n = 100;
}

void cambiarCoNPuntero(int *p){
    if (p !=NULL){
        *p = 100;
    }
}

int main(){
    int x = 5;

    printf("Antes de cambiarSinPuntero: x = %d\n", x);
    cambiarSinPuntero(x);
    printf("Despues de cambiarSinPuntero: x = %d\n", x);
    
    printf("Antes de cambiarConPuntero: x = %d\n");
    cambiarCoNPuntero(&x);
    printf("Despues de cambiarSinPuntero: x = %d\n", x);

    return 0; 
}
