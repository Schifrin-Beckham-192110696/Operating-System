#include <stdio.h>
#define MAX_REQUESTS 100

int main() {
    int requests[MAX_REQUESTS];
    int head, num_requests;
    int total_distance = 0;

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the number of disk requests: ");
    scanf("%d", &num_requests);

    printf("Enter the disk requests (in request order): ");
    for (int i = 0; i < num_requests; i++) {
        scanf("%d", &requests[i]);
    }

    for (int i = 0; i < num_requests; i++) {
        total_distance += abs(requests[i] - head);
        head = requests[i];
    }

    printf("Total distance (in cylinders): %d\n", total_distance);

    return 0;
}
