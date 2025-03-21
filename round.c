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

    printf("Process\tArrival\tBurst\tWaiting\tTurnaround\n");

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

                    // Print the process details
                    printf("%d\t%d\t%d\t%d\t%d\n",
                        processes[i].id,
                        processes[i].arrival,
                        processes[i].burst,
                        processes[i].waiting,
                        processes[i].turnaround);
                }
            }
        }

        // If no process was executed in this round, increment time
        if (!doneSomething) {
            time++;
        }
    }
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

    return 0;
}
