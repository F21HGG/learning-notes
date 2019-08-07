#include <stdio.h>

const int MAX = 3;

int main(){
    // ++
    printf("指针递增操作\n");
    int var[] = {10, 100, 200};
    int i, *ptr;
    ptr = var;
    for(i=0; i<MAX; i++){
        printf("存储地址：var[%d] = %p\n",i ,ptr);
        printf("存储值：var[%d] = %d\n",i ,*ptr);
        ptr++;
    }

    // --
    printf("指针递减操作\n");
    ptr = &var[MAX-1];
    for(i=MAX; i>0; i--){
        printf("存储地址：var[%d] = %p\n",i-1 ,ptr);
        printf("存储值：var[%d] = %d\n",i-1 ,*ptr);
        ptr--;
    }

    // cmp
    printf("指针比较操作\n");
    ptr = var;
    i = 0;
    while(ptr<=&var[MAX-1]){
        printf("存储地址：var[%d] = %p\n",i ,ptr);
        printf("存储值：var[%d] = %d\n",i ,*ptr);
        ptr++;
        i++;        
    }

    return 0;
}