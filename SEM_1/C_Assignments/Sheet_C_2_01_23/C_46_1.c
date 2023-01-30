#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[30];
	int roll;
	int marks[5];
}student;

int findTotalMarks(student s) {
	int i=0, sum = 0;
	for(i=0;i<5;i++)
		sum += s.marks[i];
	return sum;
}

float findAvgMarks(student s) {
	return (float)findTotalMarks(s)/5.f;
}

void sortStudentsOnMarks(student *s, int size) {
	int i,j;
	for(i=0;i<size;i++) {
		for(j=i;j<size-1;j++) {
			if(findTotalMarks(*(s+j)) < findTotalMarks(*(s+j+1))) {
				student t = *(s+j);
				*(s+j) = *(s+j+1);
				*(s+j+1) = t;
			}
		}
	}
}

void displayAllStudents(student *s, int n) {
	int i,j;
	for(i=0;i<n;i++) {
		printf("\nName: ");
		fputs(s[i].name, stdout);
		printf("\nroll =  %d", s[i].roll);
		printf("\nMarks: ");
		for(j=0;j<5;j++)
			printf("%d, ", s[i].marks[j]);
		printf("\n");
	}
}

void displayTotlaAndAvgMarks(student *s, int n) {
	int i;
	printf("\nThe total mark and average mark of each student is:");
	printf("\n====================================================\n");
	for(i=0;i<n;i++) {
		printf("\nRoll: %d", s[i].roll);
		printf("\nTotal marks: %d", findTotalMarks(s[i]));
		printf("\nAvg marks: %.2f\n", findAvgMarks(s[i]));
	}
}

int main()
{
	student stud[10];
	int n, i = 0, j = 0, nameSize = 30;
	
	printf("Enter number of student records: ");
	scanf("%d", &n);
	printf("\nEnter student records:");
	for(i=0;i<n;i++) {
		printf("\nEnter details of student %d", i+1);
		printf("\nEnter name: ");
		fflush(stdin);
		//scanf("%s", &stud[i].name);
		gets(stud[i].name);
		printf("Enter roll: ");
		scanf("%d", &stud[i].roll);
		printf("Enter marks of 5 subjects: ");
		for(j=0;j<5;j++)
			scanf("%d", &stud[i].marks[j]);
	}
	
	displayTotlaAndAvgMarks(stud, n);

	sortStudentsOnMarks(stud, n);
	
	printf("\nAfter sorting students based on their total marks:");
	printf("\n====================================================\n");
	displayAllStudents(stud, n);
	
	return 0;
}
