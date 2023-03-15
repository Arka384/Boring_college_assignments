#include <stdio.h>
#include <malloc.h>

int** readMatrix(int** mat, int r, int c);
void display(int** mat, int r, int c);
int** add(int** mat_1, int **mat_2, int r, int c);
int** multiply(int** mat_1, int **mat_2, int r, int c);

int main()
{
    int **mat_1, **mat_2, **result;
    int r,c;
    int choice;
    //the function pointers for addition and multiplication functions
    int** (*add_fn_ptr)(int**, int**, int, int) = &add;
    int** (*multiply_fn_ptr)(int**, int**, int, int) = &multiply;
    //creating an array of function pointers
    int** (*mat_opr_fun_ptr[])(int**, int**, int, int) = {add, multiply};


    //taking matrix inputs
    printf("Enter the row and column of first matrix:\n");
    scanf("%d%d", &r, &c);
    printf("Eter the first matrix elements:\n");
    mat_1 = readMatrix(mat_1, r, c);
    display(mat_1, r, c);
    printf("\n");
    printf("Eter the second matrix elements:\n");
    mat_2 = readMatrix(mat_2, r, c);
    display(mat_2, r, c);

    //operations using function pointers
    printf("\nPerforming matrix addition: \n");
    //result = add(mat_1, mat_2, r, c);         //normal way of function call
    result = (*add_fn_ptr)(mat_1, mat_2, r, c); //using function pointer
    display(result, r, c);
    printf("\nPerforming matrix multiplication: \n");
    //result = multiply(mat_1, mat_2, r, c);            //normal way of function call
    result = (*multiply_fn_ptr)(mat_1, mat_2, r, c);    //using function pointer
    display(result, r, c);

    //if we want to use the array of function pointers then we can do
    //something like this
    printf("\nEnter 0->addition, 1->multiplication: ");
    scanf("%d", &choice);
    result = (*mat_opr_fun_ptr[choice])(mat_1, mat_2, r, c);    //calling a specific index
    display(result, r, c);

    return 0;      
}

int** add(int** mat_1, int **mat_2, int r, int c)
{
    int** res;
    res = (int**)malloc(sizeof(int*)*r);
    for(int i=0;i<r;i++)
        res[i] = (int*)malloc(sizeof(int)*c);
    
    //perform addition
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            *(*(res+i)+j) = *(*(mat_1+i)+j) + *(*(mat_2+i)+j);

    return res;
}

int** multiply(int** mat_1, int **mat_2, int r, int c)
{
    int** res;
    res = (int**)malloc(sizeof(int*)*r);
    for(int i=0;i<r;i++)
        res[i] = (int*)malloc(sizeof(int)*c);
    
    //perform multiplication
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            *(*(res+i)+j) = 0;
            for(int k=0;k<c;k++)
                *(*(res+i)+j) += *(*(mat_1+i)+j) * *(*(mat_2+i)+j);
        }
    }
    return res;
}

int** readMatrix(int** mat, int r, int c)
{
    mat = (int**)malloc(sizeof(int*)*r);
    for(int i=0;i<r;i++)
        mat[i] = (int*)malloc(sizeof(int)*c);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d", &*(*(mat+i)+j));
    return mat;
}

void display(int** mat, int r, int c)
{
    printf("matrix elements are:\n");
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++)
            printf("%d ", *(*(mat+i)+j));
        printf("\n");
    }
}