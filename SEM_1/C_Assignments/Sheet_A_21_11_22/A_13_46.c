#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createMatrix(float **, int );
void multiplyMatrix(float **, int , int , float **, int , int , float **);
void display(float **, int , int );

int main()
{
    int n, p, i, j;
    float **matrix, **r, **mPowerP, **final;
    srand(time(0));

    printf("\nEnter n: ");
    scanf("%d", &n);
    printf("\nEnter p: ");
    scanf("%d", &p);

    //this is the matrix which will be randomly filled with data
    matrix = (float** )malloc(sizeof(float* ) * n);
    for(i=0;i<n;i++)
        matrix[i] = (float* )malloc(sizeof(float ) * n);
    
    //this mPowerP holds the result of m^p operation
    mPowerP = (float** )malloc(sizeof(float* ) * n);
    for(i=0;i<n;i++)
        mPowerP[i] = (float* )malloc(sizeof(float ) * n);
    for(i=0;i<n;i++)    //initializing it to 0
        for(j=0;j<n;j++)
            *(*(mPowerP + i) + j) = 0.f;

    //r is the n-dimensional column vector. r is (1 X n)
    r = (float** )malloc(sizeof(float* ) * n);
    for(i=0;i<n;i++)
        r[i] = (float* )malloc(sizeof(float ) * 1);
    
    //final is the matrix which stores the ultimate result
    //which is - r * (m^p)
    final = (float** )malloc(sizeof(float* ) * n);
    for(i=0;i<n;i++)
        final[i] = (float* )malloc(sizeof(float ) * 1);
    
    //initializing r and final. Each element of r is 1/n
    for(i=0;i<n;i++) {
        for(j=0;j<1;j++){
            *(*(r + i) + j) = (float)1/n;
            *(*(final + i) + j) = 0;
        }
    }

    createMatrix(matrix, n);
    printf("\nThe random matrix(M) is:\n");
    display(matrix, n, n);
    
    for(i=1;i<=p;i++)
        multiplyMatrix(matrix, n, n, matrix, n, n, mPowerP);
    printf("\n\nThe matrix(M)^P is:\n");
    display(mPowerP, n, n);

    printf("\n\nThe column vector(R) is:\n");
    display(r, n, 1);

    printf("\n\nThe matrix (R)x((M)^P) is:\n");
    multiplyMatrix(matrix, n, n, r, n, 1, final);
    display(final, n, 1);

}

void multiplyMatrix(float **matA, int r1, int c1, float **matB, int r2, int c2, float **res) {
    int i, j, k;
    for (i = 0; i < r1; ++i) {
        for (j = 0; j < c2; ++j) {
            for (k = 0; k < c1; ++k) {
                *(*(res + i) + j) += *(*(matA + i) + k) * *(*(matB + k) + j);
            }
        }
    }
}

void createMatrix(float **matrix, int n) {
    int i, j;
    for(i=0;i<n;i++) {
        float sum = 0;
        for(j=0;j<n-1;j++) {
            float val = ((float) rand() / (float)(RAND_MAX));
            int nVal = rand()%20;
            int sign = (rand()%2 == 0) ? -1 : 1;
            val = sign*(val + nVal);
            sum += val;
            *(*(matrix + i) + j) = val;
        }
        *(*(matrix + i) + (n-1)) = 1 - sum;
    }

}

void display(float **matrix, int n, int m) {
    int i, j;
    for(i=0;i<n;i++) {
        printf("\n");
        for(j=0;j<m;j++)
            printf("%.3f\t", *(*(matrix + i) + j));
    }
}