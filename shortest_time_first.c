//Shortest Remaining Time First (SRTF) scheduling program
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
            }
        } else {
            // No process is ready to execute
            totalTime++;
        }

        // Increment current time
        currentTime++;
    }
}

// Function to find waiting time for all processes
void findWaitingTime(Process proc[], int n) {
    // Waiting time is already calculated in calculateSRTF
    // No additional computation needed
}

// Function to find turnaround time for all processes
void findTurnaroundTime(Process proc[], int n) {
    // Turnaround time is already calculated in calculateSRTF
    // No additional computation needed
}

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
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        processes[i].id = i + 1;
        scanf("%d %d", &processes[i].arrival, &processes[i].burst);
    }

    calculateSRTF(processes, n);
    findAvgTime(processes, n);
    return 0;
}
