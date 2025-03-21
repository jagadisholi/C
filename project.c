#include<stdio.h>
#include<conio.h>
#include<string.h>

#define MAX_STUDENTS 100

struct Student {
    char rollNumber[20];
    char name[50];
    char address[100];
    char contact[20];
};

void addStudent(struct Student students[], int *numStudents) {
    struct Student newStudent;
    printf("Enter Roll Number: ");
    scanf("%s", newStudent.rollNumber);
    
    printf("Enter Name: ");
    scanf(" %[^\n]", newStudent.name);
    
    printf("Enter Address: ");
    scanf(" %[^\n]", newStudent.address);
    
    printf("Enter Contact Number: ");
    scanf("%s", newStudent.contact);
    
    students[*numStudents] = newStudent;
    (*numStudents)++;
    
    printf("Student added successfully!\n");
}

void updateStudent(struct Student students[], int numStudents) {
    char rollNumber[20];
    int i;
    
    printf("Enter Roll Number of the student to update: ");
    scanf("%s", rollNumber);
    
    for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].rollNumber, rollNumber) == 0) {
            printf("Enter Updated Address: ");
            scanf(" %[^\n]", students[i].address);
            
            printf("Enter Updated Contact Number: ");
            scanf("%s", students[i].contact);
            
            printf("Student information updated successfully!\n");
            return;
        }
    }
    
    printf("Student with Roll Number %s not found!\n", rollNumber);
}

void searchStudent(struct Student students[], int numStudents) {
    char rollNumber[20];
    int i;
    
    printf("Enter Roll Number of the student to search: ");
    scanf("%s", rollNumber);
    
    for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].rollNumber, rollNumber) == 0) {
            printf("Student Found!\n");
            printf("Roll Number: %s\n", students[i].rollNumber);
            printf("Name: %s\n", students[i].name);
            printf("Address: %s\n", students[i].address);
            printf("Contact Number: %s\n", students[i].contact);
            return;
        }
    }
    
    printf("Student with Roll Number %s not found!\n", rollNumber);
}

void displayAllStudents(struct Student students[], int numStudents) {
    int i;
    
    printf("Student Records:\n");
    
    for (i = 0; i < numStudents; i++) {
        printf("Roll Number: %s\n", students[i].rollNumber);
        printf("Name: %s\n", students[i].name);
        printf("Address: %s\n", students[i].address);
        printf("Contact Number: %s\n", students[i].contact);
        printf("----------------------\n");
    }
    
    if (numStudents == 0) {
        printf("No students found!\n");
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;
    char choice;
    
    do {
        printf("\n..... welcome to student record management system....\n");
        printf("1. Add Student\n");
        printf("2. Update Student\n");
        printf("3. Search Student\n");
        printf("4. Display All Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1':
                addStudent(students, &numStudents);
                break;
            case '2':
                updateStudent(students, numStudents);
                break;
            case '3':
                searchStudent(students, numStudents);
                break;
            case '4':
                displayAllStudents(students, numStudents);
                break;
            case '5':
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    } while (choice != '5');

    return 0;
}

            

