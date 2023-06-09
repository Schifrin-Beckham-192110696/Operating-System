#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 12
#define MAX_FRAMES 3

int page_faults = 0;

struct page {
    int value;
    int age;
};

int find_page_in_frames(int page, struct page frames[], int current_size) {
    for (int i = 0; i < current_size; i++) {
        if (frames[i].value == page) {
            return i;
        }
    }
    return -1;
}

int find_oldest_page(struct page frames[], int current_size) {
    int oldest_page = 0;
    for (int i = 1; i < current_size; i++) {
        if (frames[i].age > frames[oldest_page].age) {
            oldest_page = i;
        }
    }
    return oldest_page;
}

void add_page_to_frames(int page, struct page frames[], int *current_size) {
    if (*current_size < MAX_FRAMES) {
        frames[*current_size].value = page;
        frames[*current_size].age = 0;
        (*current_size)++;
    } else {
        int oldest_page = find_oldest_page(frames, MAX_FRAMES);
        frames[oldest_page].value = page;
        frames[oldest_page].age = 0;
    }
    page_faults++;
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    struct page frames[MAX_FRAMES];
    int current_size = 0;

    for (int i = 0; i < MAX_PAGES; i++) {
        int page = pages[i];
        int index = find_page_in_frames(page, frames, current_size);
        if (index == -1) {
            add_page_to_frames(page, frames, &current_size);
        } else {
            frames[index].age = 0;
        }
        for (int j = 0; j < current_size; j++) {
            frames[j].age++;
        }
    }

    printf("Number of page faults: %d\n", page_faults);
    return 0;
}
