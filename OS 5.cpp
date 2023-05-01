#include <stdio.h>
struct process {
    int id;        
    int burst;      
    int priority; 
    int wait;      
    int turn;       
};

int main() {
    int n;  
    int i, j;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    printf("Enter the burst times and priorities of processes:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &p[i].burst, &p[i].priority);
        p[i].id = i + 1;
        p[i].wait = 0;
        p[i].turn = 0;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].priority < p[j].priority) {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[0].turn = p[0].burst;
    for (i = 1; i < n; i++) {
        p[i].wait = p[i - 1].wait + p[i - 1].burst;
        p[i].turn = p[i].wait + p[i].burst;
    }

    printf("\nProcess\tBurst time\tPriority\tWaiting time\tTurnaround time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].burst, p[i].priority, p[i].wait, p[i].turn);
    }

    float avg_wait = 0, avg_turn = 0;
    for (i = 0; i < n; i++) {
        avg_wait += p[i].wait;
        avg_turn += p[i].turn;
    }
    avg_wait /= n;
    avg_turn /= n;
    printf("\nAverage waiting time: %.2f\n", avg_wait);
    printf("Average turnaround time: %.2f\n", avg_turn);

    return 0;
}

