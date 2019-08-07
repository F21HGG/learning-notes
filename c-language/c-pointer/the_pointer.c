#include <stdio.h>

int main(){
    int var = 20;
    int *ip;
    ip = &var;

    printf("Address of var variable: %p\n", &var);
    printf("Address stored in ip variable: %p\n", ip);
    printf("Value of *ip variable: %d\n\n", *ip);

    int *ptr = NULL;
    printf("ptr的地址是 %p\n", ptr);

    return 0;
}