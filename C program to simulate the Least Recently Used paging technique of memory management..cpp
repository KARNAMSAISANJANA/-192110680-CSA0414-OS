#include <stdio.h>

#define MAX_PAGES 10

int pages[MAX_PAGES];
int page_faults = 0;

void page_reference(int page) {
    int i, flag = 0;
    for (i = 0; i < MAX_PAGES; i++) {
        if (pages[i] == page) {
            int j;
            for (j = i; j > 0; j--) {
                pages[j] = pages[j-1];
            }
            pages[0] = page;
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        page_faults++;
        for (i = MAX_PAGES-1; i > 0; i--) {
            pages[i] = pages[i-1];
        }
        pages[0] = page;
    }
}

int main() {
    int i;
    int reference_string[] = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 1, 2, 3, 6};
    int n = sizeof(reference_string) / sizeof(reference_string[0]);
    for (i = 0; i < MAX_PAGES; i++) {
        pages[i] = -1;
    }
    for (i = 0; i < n; i++) {
        page_reference(reference_string[i]);
    }
    printf("Number of page faults: %d\n", page_faults);
    return 0;
}
