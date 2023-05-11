#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_func(void* arg)
{
    int i;
    for (i = 0; i < 10; i++) {
        printf("Thread function running...\n");
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t thread;

    int status = pthread_create(&thread, NULL, thread_func, NULL);
    if (status != 0) {
        perror("pthread_create failed");
        exit(1);
    }

    pthread_join(thread, NULL);

    return 0;
}
