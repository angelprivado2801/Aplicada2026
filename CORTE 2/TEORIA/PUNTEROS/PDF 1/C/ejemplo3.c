#include<stdio.h>

int main(){
    int x = 25;
    int *p = &x;

    printf("x = %d\n", x);
    printf("&x 0 %p\n", (void *)&x);
    printf("p = %p\n", (void *)p);
    printf("*p = %d\n", *p);

    return 0;
}
