#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100

int main()
{
    int blocks[MAX_BLOCKS];
    int num_blocks;
    int start_block;
    int num_files;
    int file_size;
    int i, j, k;
    
    printf("Enter the number of blocks: ");
    scanf("%d", &num_blocks);
    
    // initialize all blocks as free
    for (i = 0; i < num_blocks; i++) {
        blocks[i] = 0;
    }
    
    printf("Enter the starting block number: ");
    scanf("%d", &start_block);
    
    printf("Enter the number of files: ");
    scanf("%d", &num_files);
    
    for (i = 0; i < num_files; i++) {
        printf("Enter the size of file %d: ", i+1);
        scanf("%d", &file_size);
        
        // find a contiguous block of free space
        int free_blocks = 0;
        for (j = start_block-1; j < num_blocks; j++) {
            if (blocks[j] == 0) {
                free_blocks++;
                if (free_blocks == file_size) {
                    // allocate the blocks
                    for (k = j; k > j-file_size; k--) {
                        blocks[k] = i+1;
                    }
                    printf("File %d allocated to blocks %d-%d.\n", i+1, j-file_size+2, j+1);
                    break;
                }
            } else {
                free_blocks = 0;
            }
        }
        
        if (free_blocks < file_size) {
            printf("Cannot allocate file %d of size %d.\n", i+1, file_size);
        }
    }
    
    return 0;
}
