#include <stdio.h>
#include <malloc.h>

int** input(int**, int );
void displayArr(int**, int );
int peopleLeft(int**, int );
int executePeople(int** , int , int , int );

int main()
{
    int **people;
    int start, skip, n, dir;
    printf("\nEnter number of people: ");
    scanf("%d", &n);
    printf("\nEnter starting number: ");
    scanf("%d", &start);
    printf("\nEnter number of people to skip: ");
    scanf("%d", &skip);;

    if(start > n || start < 1) {
        printf("\nInvalid start index given\n");
        return 0;
    }

    people = input(people, n);
    // displayArr(people, n);

    int luckey_person = executePeople(people, n, start-1, skip);
    printf("Luckey person is: %d\n", luckey_person);

    return 0;
}

int executePeople(int** people, int n, int startIndex, int skip) 
{
    int i = startIndex;
    int luckey_person = -1;
    int count = 0;

    while(peopleLeft(people, n) > 1) {
        while(people[1][i] != 0)
            i = (i + 1) % n;

        int skipped = 0;
        while(skipped < skip) {
            if(people[1][i] == 0)
                skipped++;
            i = (i + 1) % n;
        }
        while(people[1][i] != 0)
            i = (i + 1) % n;
        people[1][i] = 1;
        count++;
        printf("\nAfter %d iteration\n", count);     
        displayArr(people, n);
        printf("\n");
    }

    for(i=0;i<n;i++) {
        if(people[1][i] == 0) {
            luckey_person = i+1;
            return luckey_person;
        }
    }
    return luckey_person;
}

int peopleLeft(int** people, int n)
{
    int count = 0;
    for(int i=0;i<n;i++) {
        if(people[1][i] == 0)
            count++;
    }
    return count;
}

void displayArr(int** mat, int n)
{
    for(int i=0;i<2;i++) {
        for(int j=0;j<n;j++)
            printf("%d, ", mat[i][j]);
        printf("\n");
    }
}

int** input(int** mat, int n)
{
    int **arr = (int**)calloc(sizeof(int*), 2);
    for(int i=0;i<2;i++)
        arr[i] = (int*)calloc(sizeof(int), n);
    for(int i=0;i<n;i++)
        arr[0][i] = i+1;
    return arr;
}