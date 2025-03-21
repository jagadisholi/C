#include<stdio.h>
#include <string.h>

#define MAX_STUDENTS 1000
  // char filename[] ="student.txt";
struct Student {
    char rollNumber[20];
    char name[50];
    char address[100];
    char contact[20];
    char clas[20];
    char Fname[50]; // Fname=father name 
    char Mname[50]; // Mname= mother name 
};
void addStudent(struct Student students[], int *numStudents) {
    struct Student newStudent;
    printf("Enter Roll Number: ");
    scanf("%s", newStudent.rollNumber);
    
    printf("Enter the class of student:");
    scanf("%s",newStudent.clas);
    
    printf("Enter Name: ");
    scanf(" %[^\n]", newStudent.name);
    
    printf("Enter Father Name:");
    scanf("\n%s", newStudent.Fname);
    
    printf("Enter Mother name:/n");
    scanf("\n%s", newStudent.Mname);
    
    printf("Enter Address: ");
    scanf(" \n%[^\n]", newStudent.address);
    
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
            printf("Enter the updated Class:");
            scanf("%s",students[i].clas);
            
			printf("Enter Updated Address: ");
            scanf(" %[^\n]", students[i].address);
            
            printf("Enter Updated Contact Number: ");
            scanf("%s", students[i].contact);
            
            printf("Student information updated successfully!\n");
            return;
        }
    }
    
    printf("Student with Roll Number %d not found!\n", rollNumber);
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
            printf("Class:%s\n",students[i].clas);
            printf("Name: %s\n", students[i].name);
            printf("Father name:%s\n",students[i].Fname);
            printf("Mother name: %s\n",students[i].Mname);
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
        printf("Class: %s\n",students[i].clas);
        printf("Name: %s\n", students[i].name);
    	printf("Father name:%s\n",students[i].Fname);
    	printf("Mother name: %s\n",students[i].Mname);
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
 //   FILE *fptr;
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