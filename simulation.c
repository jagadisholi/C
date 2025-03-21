#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10

typedef struct {
    int id;
    int arrivalTime;
    int processingTime;
    int completionTime;
} Task;

void simulateTasks(Task tasks[], int numTasks) {
    int currentTime = 0;
    for (int i = 0; i < numTasks; ++i) {
        if (tasks[i].arrivalTime > currentTime) {
            // Idle until the task arrives
            currentTime = tasks[i].arrivalTime;
        }
        tasks[i].completionTime = currentTime + tasks[i].processingTime;
        currentTime += tasks[i].processingTime;
    }
}

void printTaskDetails(Task tasks[], int numTasks) {
    printf("Task ID | Arrival Time | Processing Time | Completion Time\n");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < numTasks; ++i) {
        printf("%7d | %12d | %15d | %15d\n", tasks[i].id, tasks[i].arrivalTime, tasks[i].processingTime, tasks[i].completionTime);
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int numTasks;

    printf("Enter the number of tasks (max %d): ", MAX_TASKS);
    scanf("%d", &numTasks);

    if (numTasks > MAX_TASKS) {
        printf("Number of tasks exceeds maximum limit.\n");
        return 1;
    }

    for (int i = 0; i < numTasks; ++i) {
        tasks[i].id = i + 1;
        printf("Enter arrival time and processing time for task %d: ", i + 1);
        scanf("%d %d", &tasks[i].arrivalTime, &tasks[i].processingTime);
    }

    simulateTasks(tasks, numTasks);
    printTaskDetails(tasks, numTasks);

    return 0;
}
