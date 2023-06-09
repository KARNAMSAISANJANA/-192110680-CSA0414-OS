#include <stdio.h>
#define MAX_BLOCKS 10
#define MAX_MEMORY 100
int memory[MAX_MEMORY];
int blocks[MAX_BLOCKS];
int block_size[MAX_BLOCKS];
void worst_fit() {
    int i, j, k, max, block_num;
    for(i = 0; i < MAX_BLOCKS; i++) {
        if(blocks[i] == 0) {
            max = -1;
            block_num = -1;
            for(j = 0; j < MAX_BLOCKS; j++) {
                if(block_size[j] > max && blocks[j] == 0) {
                    max = block_size[j];
                    block_num = j;
                }
            }
            if(block_num != -1) {
                blocks[block_num] = 1;
                printf("Allocated block %d of size %d\n", block_num, block_size[block_num]);
                break;
            }
            else {
                printf("No block of size %d available\n", i);
                break;
            }
        }
    }
}
int main() {
    int i;
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
    for(i = 0; i < MAX_MEMORY; i++) {
        memory[i] = 0;
    }
    for(i = 0; i < MAX_BLOCKS; i++) {
        blocks[i] = 0;
    }
    worst_fit();
    return 0;
}
