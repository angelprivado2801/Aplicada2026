#include <stdio.h>

int main(void) {
    int x = 5;
    int *p = &x; // Declaracion
    
    *p = 40;     // Desreferenciacion
    
    printf("x = %d\n", x);
    
    return 0;
}
