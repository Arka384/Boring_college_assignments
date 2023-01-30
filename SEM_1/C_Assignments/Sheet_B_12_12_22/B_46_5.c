#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
0.333 0.666 -0.666
-0.666 0.666 0.333
0.666 0.333 0.666
///////////////////
0.428 0.286 0.857
-0.857 0.428 0.286
0.286 0.857 -0.428
*/
float **readMatrix(int , int );
void display(float **, int , int , int );
float **transposeMatrix(float **, int , int );
float **multiplyMatrix(float **, int , int , float **, int , int );
int checkOrthogonal(float **, int , int );


int main()
{
    int n, m, p, i, j;
    float **matrix, **matT, **matXMatT;

    printf("\nEnter dimensions of matrix: ");
    scanf("%d%d", &n, &m);

    matrix = readMatrix(n, m);
    printf("\nThe given matrix is:\n");
    display(matrix, n, m, 0);
    
    matT = transposeMatrix(matrix, n, m);
    printf("\nThe transpose matrix is:\n");
    display(matT, m, n, 0);

    matXMatT = multiplyMatrix(matrix, n, m, matT, m, n);
    printf("\n M x MT matrix is:\n");
    display(matXMatT, n, n, 1);
    
    if(checkOrthogonal(matXMatT, n, n))
    	printf("\nThe given matrix is orthogonal matrix");
    else
    	printf("\nThe given matrix is NOT orthogonal matrix");
    	
	return 0;
}

float **multiplyMatrix(float **matA, int r1, int c1, float **matB, int r2, int c2) {
    if(r1 != c2)
        return NULL;

    int i, j, k;
    float **res;
    res = (float** )malloc(sizeof(float* ) * r1);
    for(i=0;i<r1;i++)
        res[i] = (float* )malloc(sizeof(float ) * c2);

    for (i = 0; i < r1; ++i) {
        for (j = 0; j < c2; ++j) {
            *(*(res + i) + j) = 0.0;
            for (k = 0; k < c1; ++k) {
                *(*(res + i) + j) += *(*(matA + i) + k) * *(*(matB + k) + j);
            }
        }
    }
    return res;
}

float **transposeMatrix(float **matrix, int n, int m) {
    float **matrixT;
    int i, j;
    matrixT = (float** )malloc(sizeof(float* ) * n);
    for(i=0;i<m;i++)
        matrixT[i] = (float* )malloc(sizeof(float ) * m);

    for(i=0;i<n;i++) {
        for(j=0;j<m;j++){
            *(*(matrixT + j) + i) = *(*(matrix + i) + j);
        }
    }
    return matrixT;
}

int checkOrthogonal(float **matrix, int n, int m) {
	int i,j,c=0;
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			if(i == j)
				if(roundf(*(*(matrix + i) + j)) == 1)
					c++;
		}
	}
	return (c == n)? 1 : 0;
}

float **readMatrix(int n, int m) {
    float **matrix;
    int i, j;
    matrix = (float** )malloc(sizeof(float* ) * m);
    for(i=0;i<n;i++)
        matrix[i] = (float* )malloc(sizeof(float ) * n);

    printf("\nEnter matrix elements: \n");
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++)
            scanf("%f", &*(*(matrix + i) + j));
    }
    
    return matrix;
}

void display(float **matrix, int n, int m, int flag) {
    int i, j;
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++){
            if(flag)
                printf("%.3f\t", fabs(roundf(*(*(matrix + i) + j))));
            else
                printf("%.3f\t", *(*(matrix + i) + j));
        }
        printf("\n");   
    }
}
