#include <stdio.h>
#include <malloc.h>
#include <math.h>

int **readMatrix(int , int );
void display(int **, int , int );
int **sortMatrix(int **, int , int );
int **joinMatrices(int **, int , int , int **, int , int , int *n3, int *m3);

int main()
{
    int **mat1, **mat2, **mat3;
    int n1, m1, n2, m2, n3, m3;

    printf("Enter the order of first matrix: ");
    scanf("%d%d", &n1,&m1);
    mat1 = readMatrix(n1,m1);
    
    printf("Enter the order of second matrix: ");
    scanf("%d%d", &n2,&m2);
    mat2 = readMatrix(n2,m2);
	
    mat1 = sortMatrix(mat1, n1, m1);
    printf("\nFirst matrix after sorting becomes: ");
    display(mat1, n1, m1);
    mat2 = sortMatrix(mat2, n2, m2);
    printf("\nSecond matrix after sorting becomes: ");
    display(mat2, n2, m2);

	mat3 = joinMatrices(mat1, n1, m1, mat2, n2, m2, &n3, &m3);
	printf("\nAfter joining the matrix becomes: ");
	display(mat3, n3, m3);
	
	return 0;
}

int **joinMatrices(int **mat1, int n1, int m1, int **mat2, int n2, int m2, int *n3, int *m3) {
	int i,j,k=0;
	int totalSize = n1*m1 + n2*m2;
	
	int *arr1 = (int *)malloc(sizeof(int )*(n1*m1));
	for(i=0;i<n1;i++)
		for(j=0;j<m1;j++) {
			*(arr1 + k) = *(*(mat1 + i) + j);
			k++;
		}	
	k=0;
	int *arr2 = (int *)malloc(sizeof(int )*(n2*m2));	
	for(i=0;i<n2;i++)
		for(j=0;j<m2;j++) {
			*(arr2 + k) = *(*(mat2 + i) + j);
			k++;
		}

	//////////joining two sorted arrays/////////////
	i=0,j=0,k=0;
	int *arr3 = (int *)malloc(sizeof(int )*totalSize);
	while((i < (n1*m1)) && (j < (n2*m2))) {
		if(*(arr1 + i) < *(arr2 + j)) {
			*(arr3 + k) = *(arr1 + i);
			i++;
		}	
		else {
			*(arr3 + k) = *(arr2 + j);
			j++;
		}
		k++;
	}
	while(i < (n1*m1)) {
		*(arr3 + k) = *(arr1 + i);
		i++;
		k++;
	}
	while(j < (n2*m2)) {
		*(arr3 + k) = *(arr2 + j);
		j++;
		k++;
	}
	    
    int x = sqrt(totalSize);
    int y = totalSize/x;
    int **res;
    res = (int** )malloc(sizeof(int* ) * x);
    for(i=0;i<x;i++)
        res[i] = (int* )malloc(sizeof(int ) * y);
        
    for(i=0,k=0;i<x;i++)
		for(j=0;j<y;j++) {
			*(*(res + i) + j) = *(arr3 + k);
			k++;
		}
    
    *n3 = x;
    *m3 = y;
    return res;
}


int **sortMatrix(int **mat, int n, int m) {
    int *tempArr = (int *)malloc(sizeof(int )*(n*m));
    int i,j,k=0;
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            *(tempArr + k) = *(*(mat + i) + j);
            k++;
        }
    }

    //performing bubble sort
    for(i=0;i<(n*m);i++) {
        for(j=i;j<(n*m);j++) {
            if(*(tempArr + j) < *(tempArr + i)) {
                //swap
                int temp = *(tempArr + i);
                *(tempArr + i) = *(tempArr + j);
                *(tempArr + j) = temp;
            }
        }
    }

    //for(i=0;i<n*m;i++)
    //    printf("%d ", *(tempArr + i));

    //put them back in the matrix
    for(i=0,k=0;i<n;i++) {
        for(j=0;j<m;j++) {
            *(*(mat + i) + j) = *(tempArr + k);
            k++;
        }
    }    

    
    return mat;
}

int **readMatrix(int n, int m) {
    int **matrix;
    int i, j;
    matrix = (int** )malloc(sizeof(int* ) * m);
    for(i=0;i<n;i++)
        matrix[i] = (int* )malloc(sizeof(int ) * n);

    printf("\nEnter matrix elements: \n");
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++)
            scanf("%d", &*(*(matrix + i) + j));
    }
    
    return matrix;
}

void display(int **matrix, int n, int m) {
    int i, j;
    for(i=0;i<n;i++) {
        printf("\n");
        for(j=0;j<m;j++)
            printf("%d\t", *(*(matrix + i) + j));
    }
    printf("\n");
}
