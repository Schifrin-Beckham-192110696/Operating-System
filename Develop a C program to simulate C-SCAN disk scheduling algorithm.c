#include <stdio.h>
#include <stdlib.h>
#define MAX_REQUESTS 100
#define MAX_CYLINDERS 1000

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int requests[MAX_REQUESTS];
    int head, num_requests;
    int total_distance = 0;
    int current_request;
    int direction = 1;  

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the number of disk requests: ");
    scanf("%d", &num_requests);

    printf("Enter the disk requests: ");
    for (int i = 0; i < num_requests; i++) {
        scanf("%d", &requests[i]);
    }

    qsort(requests, num_requests, sizeof(int), compare);

    int head_index = -1;
    for (int i = 0; i < num_requests; i++) {
        if (requests[i] == head) {
            head_index = i;
            break;
        }
    }

\    if (head_index == -1) {
        requests[num_requests++] = head;
        qsort(requests, num_requests, sizeof(int), compare);
        head_index = num_requests - 1;
    }
    current_request = head_index;

    printf("Servicing requests in the following order: ");
    while (current_request >= 0 && current_request < num_requests) {
        printf("%d ", requests[current_request]);
        total_distance += abs(requests[current_request] - head);
        head = requests[current_request];
        current_request += direction;
    }

    if(direction == 1 && head_index != num_requests-1 ) {
        current_request = 0;
        while (current_request < head_index) {
            printf("%d ", requests[current_request]);
            total_distance += abs(requests[current_request] - head);
            head = requests[current_request];
            current_request++;
        }
    }

    printf("\nTotal distance (in cylinders): %d\n", total_distance);
    return 0;
}
