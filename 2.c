// WAP to take input of namel, rollno, and marks in 5 sub of each having 100 marks 
#include<stdio.h>
#include<conio.h>
int main()
 {
 	char name[40];
 	int rollno;
 	float msub1, msub2, msub3, msub4, msub5,score, msum;
 	printf("Enter the name of student:");
 	scanf("%[^\n]",&name);
 	printf("\n roll number of student:");
 	scanf("%d",&rollno);
 	printf("\n Enter the marks of 5 subjects\n");
 	scanf("%f %f %f %f %f",&msub1, &msub2, &msub3, &msub4, &msub5);
 	msum=msub1+msub2+msub3+msub4+msub5;
 	score=msum/500*100;
 	printf("\n name of student %s",name);
 	printf("\n rollno :%d",rollno);
 	printf("\nthe percentage  is %f",score,'%');
 	getch();
 	return 0;
 }
