#include <stdio.h>
#include <math.h>
#include <malloc.h>

int getArray(int *, int *, int , char );
void fillMatrices(int **, int *, int );
void addMatrices(int **, int **, int **, int );
void subMatrices(int **, int **, int **, int );
void input(int *, int );
void displayArray(int *, int );
void displayMatrix(int **, int );

int main()
{
    int inputArray[50], evenArr[50] = {0}, oddArr[50] = {0};
    int **evenMat, **oddMat, **resMat;
    int i, n, evenSize, oddSize, matOrder;

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    input(inputArray, n);

    evenSize = getArray(inputArray, evenArr, n, 'e');
    oddSize = getArray(inputArray, oddArr, n, 'o');

    printf("\nEven array:");
    displayArray(evenArr, evenSize);
    printf("\nOdd array:");
    displayArray(oddArr, oddSize);

    matOrder = (evenSize < oddSize)? evenSize : oddSize;
    while(matOrder > 0) {
        double temp = sqrt(matOrder);
        int tempTrunc = (int)temp;
        if(temp == tempTrunc)
            break;
        matOrder--;
    }
    if(matOrder <= 0) {
        printf("\nNot Possible");
        return 0;
    }
    

    matOrder = sqrt(matOrder);
    evenMat = (int** )malloc(sizeof(int* ) * matOrder);
    for(i=0;i<matOrder;i++)
        evenMat[i] = (int* )malloc(sizeof(int ) * matOrder);
    oddMat = (int** )malloc(sizeof(int* ) * matOrder);
    for(i=0;i<matOrder;i++)
        oddMat[i] = (int* )malloc(sizeof(int ) * matOrder);
    resMat = (int** )malloc(sizeof(int* ) * matOrder);
    for(i=0;i<matOrder;i++)
        resMat[i] = (int* )malloc(sizeof(int ) * matOrder);


    fillMatrices(evenMat, evenArr, matOrder);
    fillMatrices(oddMat, oddArr, matOrder);
    printf("\nEven matrix:");
    displayMatrix(evenMat, matOrder);
    printf("\nOdd matrix:");
    displayMatrix(oddMat, matOrder);

    printf("\nThe addition matrix is:");
    addMatrices(evenMat, oddMat, resMat, matOrder);
    displayMatrix(resMat, matOrder);

}

void addMatrices(int **matA, int **matB, int **matRes, int matOrder)
{
    int i,j,k=0;
    for(i=0;i<matOrder;i++){
        for(j=0;j<matOrder;j++){
            *(*(matRes+i)+j) = *(*(matA+i)+j) + *(*(matB+i)+j);
        }
    }
}

void subMatrices(int **matA, int **matB, int **matRes, int matOrder)
{
    int i,j,k=0;
    for(i=0;i<matOrder;i++){
        for(j=0;j<matOrder;j++){
            *(*(matRes+i)+j) = *(*(matA+i)+j) - *(*(matB+i)+j);
        }
    }
}

void fillMatrices(int **mat, int *arr, int matOrder)
{
    int i,j,k=0;
    for(i=0;i<matOrder;i++){
        for(j=0;j<matOrder;j++){
            *(*(mat+i)+j) = *(arr+k);
            k++;
        }
    }
}

int getArray(int *inputArr, int *array, int n, char c)
{
    int i=0,k=0;
    if(c == 'e') {
        for(i=0;i<n;i++){
            if(*(inputArr+i) % 2 == 0){
                *(array+k) = *(inputArr+i);
                k++;
            }
        }
    }
    else if(c == 'o') {
        for(i=0;i<n;i++){
            if(*(inputArr+i) % 2 != 0){
                *(array+k) = *(inputArr+i);
                k++;
            }
        }
    }
    return k;
}

void input(int *arr, int n)
{
    int i;
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
}

void displayMatrix(int **mat, int order)
{
    int i,j;
    printf("\n");
    for(i=0;i<order;i++){
        for(j=0;j<order;j++){
            printf("%d\t", *(*(mat+i)+j));
        }
        printf("\n");
    }
}

void displayArray(int *array, int n)
{
    int i=0;
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d, ", *(array+i));
}