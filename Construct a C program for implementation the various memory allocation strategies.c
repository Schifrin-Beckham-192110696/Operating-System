#include <stdio.h>
#include <stdlib.h>

int main()
{
   
    int a;
    a = 5;


    int b = 6;


    int *c = malloc(sizeof(int));
    if (c == NULL) {
        perror("malloc failed");
        exit(1);
    }
    *c = 7;


    int *d = calloc(1, sizeof(int));
    if (d == NULL) {
        perror("calloc failed");
        exit(1);
    }
    *d = 8;

    // Print values
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("*c = %d\n", *c);
    printf("*d = %d\n", *d);


    free(c);
    free(d);

    return 0;
}
