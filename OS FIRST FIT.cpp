#include <stdio.h>

#define MAX_BLOCKS 10
#define MAX_MEMORY 100

int memory[MAX_MEMORY];
int blocks[MAX_BLOCKS];
int block_size[MAX_BLOCKS];

void first_fit(int size) {
    int i, j, k, block_num;

    block_num = -1;
    for(i = 0; i < MAX_BLOCKS; i++) {
        if(block_size[i] >= size && blocks[i] == 0) {
            block_num = i;
            break;
        }
    }
    if(block_num != -1) {
        blocks[block_num] = 1;
        printf("Allocated block %d of size %d\n", block_num, block_size[block_num]);
    }
    else {
        printf("No block of size %d available\n", size);
    }
}

int main() {
    int i;

    //initializing block sizes
    block_size[0] = 25;
    block_size[1] = 35;
    block_size[2] = 50;
    block_size[3] = 40;
    block_size[4] = 60;
    block_size[5] = 30;
    block_size[6] = 45;
    block_size[7] = 55;
    block_size[8] = 20;
    block_size[9] = 10;

    //initializing memory to 0 (not allocated)
    for(i = 0; i < MAX_MEMORY; i++) {
        memory[i] = 0;
    }

    //initializing blocks to 0 (not allocated)
    for(i = 0; i < MAX_BLOCKS; i++) {
        blocks[i] = 0;
    }

    first_fit(45);

    return 0;
}
