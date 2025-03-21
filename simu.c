#include <stdio.h>

struct Process {
    int pid;     // Process ID
    int arrival; // Arrival time
    int burst;   // Burst time
    int waiting; // Waiting time
    int turnaround; // Turnaround time
};

void sortByArrival(struct Process proc[], int n) {
    struct Process temp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(proc[j].arrival > proc[j+1].arrival) {
                temp = proc[j];
                proc[j] = proc[j+1];
                proc[j+1] = temp;
            }
        }
    }
}

void findWaitingTime(struct Process proc[], int n) {
    int service_time[n];
    service_time[0] = proc[0].arrival;
    proc[0].waiting = 0;

    for (int i = 1; i < n; i++) {
        service_time[i] = service_time[i - 1] + proc[i - 1].burst;
        proc[i].waiting = service_time[i] - proc[i].arrival;
        
        if (proc[i].waiting < 0)
            proc[i].waiting = 0;
    }
}

void findTurnaroundTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaround = proc[i].burst + proc[i].waiting;
    }
}

void findAvgTime(struct Process proc[], int n) {
    findWaitingTime(proc, n);
    findTurnaroundTime(proc, n);

    printf("Processes   Arrival Time   Burst Time   Waiting Time   Turnaround Time\n");
    int total_waiting = 0, total_turnaround = 0;
    for (int i = 0; i < n; i++) {
        total_waiting += proc[i].waiting;
        total_turnaround += proc[i].turnaround;
        printf("   %d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].arrival, proc[i].burst, proc[i].waiting, proc[i].turnaround);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_waiting / n);
    printf("\nAverage Turnaround Time = %.2f", (float)total_turnaround / n);
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &proc[i].arrival, &proc[i].burst);
    }

    sortByArrival(proc, n);
    findAvgTime(proc, n);
    return 0;
}
