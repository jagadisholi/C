#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 1000
#define FILENAME "students.txt"

struct Student {
    int rollNumber[20];
    char name[50];
    char address[100];
    int contact[20];
    char clas[40];
};
 // funntion of add student
void addStudent(struct Student students[], int *numStudents) {
    struct Student newStudent;
    printf("Enter Roll Number: ");
    scanf("%d", newStudent.rollNumber);
	printf("Enter the class of Student:");
	scanf("%s", newStudent.clas);    
    printf("Enter Name: ");
    scanf(" %[^\n]", newStudent.name);
    printf("Enter Address: ");
    scanf(" %[^\n]", newStudent.address);
    printf("Enter Contact Number: ");
    scanf("%d", newStudent.contact);
    students[*numStudents] = newStudent;
    (*numStudents++);
    printf("Student added successfully!\n");
}
// function for keep record in file

void writeStudentsToFile(struct Student students[], int numStudents) {
    FILE *file = fopen("student.txt", "a");
    if (file == NULL) {
        printf("This is empty file\n");
        return;
	}
     //for (int i = 0; i < numStudents; i++) {
     //fprintf(file, "%d,%d,%s,%s,%d\n", students[i].rollNumber,student[i].class,students[i].name, students[i].address, students[i].contact);
    
    fclose(file);
}


void readStudentsFromFile(struct Student students[], int *numStudents) {
    FILE *file = fopen("Student.txt", "r");
    
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    *numStudents = 0;
    while (fscanf(file, "%d,%[^,],%[^,],%[^,],%d\n", students[*numStudents].rollNumber, students[*numStudents].clas,students[*numStudents].name, students[*numStudents].address, students[*numStudents].contact) != EOF) 
	      {
        (*numStudents++);
    }
    
    fclose(file);
}

void updateStudent(struct Student students[], int numStudents) {
    int rollNumber[20];
    int i;
    printf("Enter Roll Number of the student to update: ");
    scanf("%d", rollNumber);
    for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].rollNumber, rollNumber) == 0) {
        	printf("Enter the updated class:");
        	scanf("%s",students[i].clas);
            printf("Enter Updated Address: ");
            scanf(" %[^\n]", students[i].address);
            
            printf("Enter Updated Contact Number: ");
            scanf("%d", students[i].contact);
            
            printf("Student information updated successfully!\n");
            writeStudentsToFile(students, numStudents);
            return;
        }
    }
    
    printf("Student with Roll Number %s not found!\n", rollNumber);
}
// function of students to search 
void searchStudent(struct Student students[], int numStudents) {
    int rollNumber[20];
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

//function to display students 
void displayAllStudents(struct Student students[], int numStudents) {
    int i;
    
    printf("Student Records:\n");
    
    for (i = 0; i < numStudents; i++) {
        printf("Roll Number: %s\n", students[i].rollNumber);
        printf("Name: %s\n", students[i].name);
        printf("Address: %s\n", students[i].address);
        printf("Contact Number: %s\n", students[i].contact);
        //printf("class of student:%s\n",students[i].class);
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
    
    readStudentsFromFile(students, &numStudents);
    
    do {
        printf("\n--- Student Record Management System ---\n");
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
                writeStudentsToFile(students, numStudents);
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
