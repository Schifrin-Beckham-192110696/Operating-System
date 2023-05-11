#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *print_hello(void *arg) {
    printf("Hello from thread!\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, print_hello, NULL);
    printf("Hello from main thread!\n");

    pthread_t thread2 = pthread_self();
    int res = pthread_equal(thread, thread2);
    if (res) {
        printf("Thread and Thread2 are equal\n");
    } else {
        printf("Thread and Thread2 are not equal\n");
    }

    pthread_join(thread, NULL);
    printf("Thread has finished.\n");
    return 0;
}
