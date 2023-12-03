#include <stdio.h>

#define x 10
#define y 10

// Function to input a matrix
void inputMatrix(int rows, int cols, int matrix[x][y])
{
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int cols, int matrix[x][y])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to check matrix compatibility for addition
int mcoma(int rows1, int cols1, int rows2, int cols2)
{
    return (rows1 == rows2 && cols1 == cols2);
}

// Function to check matrix compatibility for multiplication
int mcomm(int cols1, int rows2)
{
    return cols1 == rows2;
}

// Function to add two matrices
void addMatrices(int rows, int cols, int matrix1[x][y], int matrix2[x][y], int result[x][y])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int rows1, int cols1, int matrix1[x][y], int rows2, int cols2, int matrix2[x][y], int result[x][y])
{
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main()
{
    int rowsA, colsA, rowsB, colsB;

    // Input the dimensions of the first matrix
    printf("Enter the number of rows for MatrixA: ");
    scanf("%d", &rowsA);
    printf("Enter the number of columns for MatrixA: ");
    scanf("%d", &colsA);

    // Input the first matrix
    int matrixA[x][y];
    inputMatrix(rowsA, colsA, matrixA);

    // Input the dimensions of the second matrix
    printf("Enter the number of rows for MatrixB: ");
    scanf("%d", &rowsB);
    printf("Enter the number of columns for MatrixB: ");
    scanf("%d", &colsB);

    // Input the second matrix
    int matrixB[x][y];
    inputMatrix(rowsB, colsB, matrixB);

    // Check compatibility for addition and multiplication
    if (!mcoma(rowsA, colsA, rowsB, colsB))
    {
        printf("Matrices are not Addable.\n");
        return 1;
    }

    if (!mcomm(colsA, rowsB))
    {
        printf("Matrices are not Multiplaible.\n");
        return 1;
    }

    // Perform addition
    int rAdd[x][y];
    addMatrices(rowsA, colsA, matrixA, matrixB, rAdd);

    // Perform multiplication
    int rMul[x][y];
    multiplyMatrices(rowsA, colsA, matrixA, rowsB, colsB, matrixB, rMul);

    // Print the results
    printf("\nAddition:\n");
    printMatrix(rowsA, colsA, rAdd);

    printf("\nMultiplication:\n");
    printMatrix(rowsA, colsB, rMul);

    return 0;
}
