#include <stdio.h>

int main(){
    int var;
    int *ptr;
    int **pptr;

    var = 3000;

    ptr = &var;
    pptr = &ptr;

    printf("变量名：    变量值：   变量地址：    \n");
    printf("var        %d        %p\n", var, &var);
    printf("ptr        %p        %p\n", ptr, &ptr);
    printf("pptr        %p        %p\n", pptr, &pptr);
    printf("sizeof ptr: %d\n", (int)sizeof(ptr));
    return 0;
}