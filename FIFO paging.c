#include <stdio.h>

#define MAX_PAGES 100

int main() {
    int pages[MAX_PAGES];
    int page_count = 0;
    int page_faults = 0;
    int page_frame_count = 0;
    int page_frames[MAX_PAGES];
    int page_frame_head = 0;
    
    printf("Enter the number of page frames: ");
    scanf("%d", &page_frame_count);
    
    printf("Enter the page reference string, separated by spaces: ");
    while (page_count < MAX_PAGES && scanf("%d", &pages[page_count]) != EOF) {
        int page_number = pages[page_count];
        int page_found = 0;
        
        // Check if the page is already in a page frame
        for (int i = 0; i < page_frame_count; i++) {
            if (page_frames[i] == page_number) {
                page_found = 1;
                break;
            }
        }
        
        // If the page is not in a page frame, replace the oldest page with the new page
        if (!page_found) {
            page_frames[page_frame_head] = page_number;
            page_frame_head = (page_frame_head + 1) % page_frame_count;
            page_faults++;
        }
        
        // Print out the current page frames and whether or not a page fault occurred
        printf("%d:\t", page_number);
        for (int i = 0; i < page_frame_count; i++) {
            if (i < page_count % page_frame_count) {
                printf("%d ", page_frames[i]);
            } else {
                printf("- ");
            }
        }
        printf("\t%s\n", page_found ? "" : "Page fault");
        
        page_count++;
    }
    
    printf("Total page faults: %d\n", page_faults);

}
