#include <stdio.h>

struct process {
    int pid; 
    int arrival; 
    int burst; 
    int remaining; 
    int waiting; 
    int turnaround; 
};

int main() {
    int n, quantum, i, j, time = 0, count = 0, total_waiting = 0, total_turnaround = 0;
    struct process p[50];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the quantum size: ");
    scanf("%d", &quantum);

    for (i = 0; i < n; i++) {
        printf("\nEnter the arrival time for process %d: ", i + 1);
        scanf("%d", &p[i].arrival);

        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &p[i].burst);

        p[i].remaining = p[i].burst;
        p[i].pid = i + 1;
    }

    while (count != n) {
        for (i = 0; i < n; i++) {
            if (p[i].remaining > 0) {
                if (p[i].remaining > quantum) {
                    time += quantum;
                    p[i].remaining -= quantum;
                } else {
                    time += p[i].remaining;
                    p[i].waiting = time - p[i].burst - p[i].arrival;
                    p[i].remaining = 0;
                    count++;
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        p[i].turnaround = p[i].burst + p[i].waiting;
        total_waiting += p[i].waiting;
        total_turnaround += p[i].turnaround;
    }

    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time");

    for (i = 0; i < n; i++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", p[i].pid, p[i].arrival, p[i].burst, p[i].waiting, p[i].turnaround);
    }

    printf("\n\nAverage Waiting Time: %.2f", (float)total_waiting / n);
    printf("\nAverage Turnaround Time: %.2f", (float)total_turnaround / n);

    return 0;
}

