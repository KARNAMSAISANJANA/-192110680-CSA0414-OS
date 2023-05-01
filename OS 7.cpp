#include<stdio.h>
#include<stdlib.h>
struct process{
    int pid; 
    int burst; 
    int waiting; 
    int turnaround; 
};

int main(){
    int n, i, j, temp;
    float avg_waiting=0, avg_turnaround=0;
    struct process p[50];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i=0;i<n;i++){
        printf("\nEnter the burst time for process %d: ", i+1);
        scanf("%d", &p[i].burst);
        p[i].pid = i+1;
    }

    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j].burst > p[j+1].burst){
                temp = p[j].burst;
                p[j].burst = p[j+1].burst;
                p[j+1].burst = temp;

                temp = p[j].pid;
                p[j].pid = p[j+1].pid;
                p[j+1].pid = temp;
            }
        }
    }
    p[0].waiting = 0;
    for(i=1;i<n;i++){
        p[i].waiting = p[i-1].waiting + p[i-1].burst;
    }
    for(i=0;i<n;i++){
        p[i].turnaround = p[i].waiting + p[i].burst;
    }

    printf("\n\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time");

    for(i=0;i<n;i++){
        printf("\n%d\t\t%d\t\t%d\t\t%d", p[i].pid, p[i].burst, p[i].waiting, p[i].turnaround);
        avg_waiting += p[i].waiting;
        avg_turnaround += p[i].turnaround;
    }

    avg_waiting /= n;
    avg_turnaround /= n;

    printf("\n\nAverage Waiting Time: %.2f", avg_waiting);
    printf("\nAverage Turnaround Time: %.2f", avg_turnaround);

    return 0;
}

