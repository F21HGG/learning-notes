#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *threadFunc(void *parm){
    while(1){
        fprintf(stdout, "I am the child thread.\n");
        pthread_testcancel();
        sleep(1);
    }
}

int main(int argc, char *argv[]){
    void *status;
    pthread_t thread;
    pthread_create(&thread, NULL, threadFunc, NULL);
    sleep(10);
    pthread_cancel(thread);
    pthread_join(thread, &status);
    if(status == PTHREAD_CANCELED){
        fprintf(stdout, "The child thread has been canceled.\n");
    }else{
        fprintf(stderr, "Unexpected thread status!\n");
    }
    return 0;
}
