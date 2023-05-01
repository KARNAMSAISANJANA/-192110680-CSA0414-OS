#include<stdio.h>
#include<stdlib.h>

struct process{
    int pid;
    int burst; 
    int priority;
    int remaining; 
};

int main(){
    int n, i, time=0, smallest, complete=0;
    float waiting_time=0, turnaround_time=0;
    struct process p[50];
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i=0;i<n;i++){
        printf("\nEnter the burst time and priority for process %d: ", i+1);
        scanf("%d %d", &p[i].burst, &p[i].priority);
        p[i].pid = i+1;
        p[i].remaining = p[i].burst;
    }

    printf("\n\nProcess ID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time");

    while(complete != n){
        smallest = -1;
        for(i=0;i<n;i++){
            if(p[i].remaining > 0){
                if(smallest == -1){
                    smallest = i;
                }
                else if(p[i].priority < p[smallest].priority){
                    smallest = i;
                }
            }
        }

        p[smallest].remaining--;

        if(p[smallest].remaining == 0){
            complete++;

            waiting_time += time - p[smallest].burst;
            turnaround_time += time;

            printf("\n%d\t\t%d\t\t%d\t\t%.2f\t\t%.2f", p[smallest].pid, p[smallest].burst, p[smallest].priority, (float)(time - p[smallest].burst), (float)time);
        }
        time++;
    }

    printf("\n\nAverage Waiting Time: %.2f", waiting_time/n);
    printf("\nAverage Turnaround Time: %.2f", turnaround_time/n);

    return 0;
}

