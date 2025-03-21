#include <stdio.h>

#define MAX_PROCESSES 100

// Structure to represent a process
typedef struct {
    int id;          // Process ID
    int arrival;     // Arrival time
    int burst;       // Burst time
    int remaining;   // Remaining time
    int waiting;     // Waiting time
    int turnaround;  // Turnaround time
} Process;

// Function to calculate waiting time and turnaround time
void calculateRR(Process processes[], int n, int quantum) {
    int time = 0;       // Current time
    int completed = 0;  // Number of completed processes
    int i;

    // Initialize remaining time for each process
    for (i = 0; i < n; i++) {
        processes[i].remaining = processes[i].burst;
    }

    while (completed < n) {
        int doneSomething = 0;

        for (i = 0; i < n; i++) {
            if (processes[i].remaining > 0) {
                doneSomething = 1;

                // Calculate the time slice for this process
                int timeSlice = (processes[i].remaining < quantum) ? processes[i].remaining : quantum;

                // Simulate process execution
                processes[i].remaining -= timeSlice;
                time += timeSlice;

                // Check if process is completed
                if (processes[i].remaining == 0) {
                    completed++;
                    processes[i].turnaround = time - processes[i].arrival;
                    processes[i].waiting = processes[i].turnaround - processes[i].burst;
                }
            }
        }

        // If no process was executed in this round, increment time
        if (!doneSomething) {
            time++;
        }
    }
}

// Function to find waiting time for all processes
void findWaitingTime(Process proc[], int n) {}

// Function to find turnaround time for all processes
void findTurnaroundTime(Process proc[], int n) {}

// Function to find average time
void findAvgTime(Process proc[], int n) {
    findWaitingTime(proc, n);
    findTurnaroundTime(proc, n);

    printf("Processes   Arrival Time   Burst Time   Waiting Time   Turnaround Time\n");
    int total_waiting = 0, total_turnaround = 0;
    for (int i = 0; i < n; i++) {
        total_waiting += proc[i].waiting;
        total_turnaround += proc[i].turnaround;
        printf("   %d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].arrival, proc[i].burst, proc[i].waiting, proc[i].turnaround);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_waiting / n);
    printf("\nAverage Turnaround Time = %.2f", (float)total_turnaround / n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        processes[i].id = i + 1;
        scanf("%d %d", &processes[i].arrival, &processes[i].burst);
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    calculateRR(processes, n, quantum);
    findAvgTime(processes, n);

    return 0;
}
