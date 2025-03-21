#include <stdio.h>
#include <limits.h>

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

// Function to find the process with the shortest remaining time
int findShortestRemaining(Process processes[], int n, int time) {
    int minTime = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < n; i++) {
        if (processes[i].arrival <= time && processes[i].remaining > 0 && processes[i].remaining < minTime) {
            minTime = processes[i].remaining;
            minIndex = i;
        }
    }

    return minIndex;
}

void calculateSRTF(Process processes[], int n) {
    int totalTime = 0;   // Total time elapsed
    int completed = 0;   // Number of completed processes
    int currentTime = 0;
    int index;

    // Initializing remaining times
    for (int i = 0; i < n; i++) {
        processes[i].remaining = processes[i].burst;
    }

    // Array to track if a process has been completed
    int isCompleted[100];
    for (int i = 0; i < n; i++) {
        isCompleted[i] = 0;
    }

    printf("Process\tArrival\tBurst\tWaiting\tTurnaround\n");

    while (completed < n) {
        // Find process with the shortest remaining time
        index = findShortestRemaining(processes, n, currentTime);

        if (index != -1) {
            // Execute the process for 1 unit of time
            processes[index].remaining--;
            totalTime++;

            // If the process is completed
            if (processes[index].remaining == 0) {
                isCompleted[index] = 1;
                completed++;

                // Calculate waiting time and turnaround time
                processes[index].turnaround = totalTime - processes[index].arrival;
                processes[index].waiting = processes[index].turnaround - processes[index].burst;

                // Print the process details
                printf("%d\t%d\t%d\t%d\t%d\n",
                    processes[index].id,
                    processes[index].arrival,
                    processes[index].burst,
                    processes[index].waiting,
                    processes[index].turnaround);
            }
        } else {
            // No process is ready to execute
            totalTime++;
        }

        // Increment current time
        currentTime++;
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        processes[i].id = i + 1;
        scanf("%d %d", &processes[i].arrival, &processes[i].burst);
    }

    calculateSRTF(processes, n);

    return 0;
}
