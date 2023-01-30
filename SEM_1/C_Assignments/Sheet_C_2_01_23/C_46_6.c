#include <stdio.h>
#include <ctype.h>
#include <malloc.h>

int** getMatrix(int **, int *, int *);
int** findRowSum(int **, int , int );
void displayMatrix(int **, int , int );

int main()
{
    int rowCount = 0, colCount = 0;
    int **matrix, **rowSum;
    
    matrix = getMatrix(matrix, &rowCount, &colCount);
    printf("\nThe dimensions of the matrix is: %d X %d", rowCount, colCount);
    //displayMatrix(matrix, rowCount, colCount);
    printf("\nThe row sum of the matrix is:");
    rowSum = findRowSum(matrix, rowCount, colCount);
    displayMatrix(rowSum, rowCount , 2);

    return 0;
}

int** findRowSum(int **matrix, int row, int col)
{
    int **rowSum;
    int i,j;
    rowSum = (int** )malloc(sizeof(int* ) * row);
    for(i=0;i<row;i++)
        rowSum[i] = (int* )malloc(sizeof(int ) * 2);

    for(i=0;i<row;i++){
        *(*(rowSum + i) + 0) = i;
        int sum = 0;
        for(j=0;j<col;j++)
            sum += *(*(matrix + i) + j);
        *(*(rowSum + i) + 1) = sum;
    }

    return rowSum;
}

int** getMatrix(int **matrix, int *rowCount, int *colCount)
{
    char c;
    int i,j;
    FILE *in = fopen("C_46_6_input.txt", "r");
    while(1) {
        fflush(stdin);
        c = fgetc(in);
        if(c == EOF)
            break;
        else if(c == '\n') {
            *rowCount = *rowCount + 1;
            *colCount = 0;
        }
        else
            *colCount = *colCount + 1;
    }
    fclose(in);
    *rowCount = *rowCount + 1;

    matrix = (int** )malloc(sizeof(int* ) * (*rowCount));
    for(i=0;i<*rowCount;i++)
        matrix[i] = (int *)malloc(sizeof(int ) * (*colCount));


    in = fopen("C_46_6_input.txt", "r");
    i = 0;
    j = -1;
    while(1) {
        fflush(stdin);
        c = fgetc(in);
        if(c == EOF)
            break;
        else if(c == '\n') {
            i++;
            j=-1;
        }
        else {
            j++;
            *(*(matrix + i) + j) = c-48;
        }
    }
    fclose(in);
    return matrix;
}

void displayMatrix(int **matrix, int row, int col)
{
    printf("\n");
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++)
            printf("%d ", *(*(matrix + i) + j));
        printf("\n");
    }
}