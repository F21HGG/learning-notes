#include <stdio.h>
#include <pthread.h>

int pthread_create(
    pthread_t *,
    const pthread_attr_t *,
    void* (*) (void*),
    void*) __attribute__ ((weak));

int main(){
    if(pthread_create){
        printf("this is multi-thread version!\n");
    }else{
        printf("this is single-thread version!\n");
    }
}

