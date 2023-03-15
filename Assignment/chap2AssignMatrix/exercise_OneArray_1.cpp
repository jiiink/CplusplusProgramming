//2차원 배열에 대한 행렬 더하기
//C++ 1차 과제로 배포 
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#define ROWS 3
#define COLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 3
#define CCOLS 5
//int getMatrix(int[][COLS], int);//난수 생성하여 처리 - pointer만 사용하여 구현
bool showMatrix(int[][COLS], int);
bool showMatrixB(int(*arr)[BCOLS], int rows);
bool addMatrix(int[][COLS], int, int[][COLS], int, int[][COLS], int);
bool getMatrixA(int(*arr)[COLS], int rows);
bool getMatrixB(int(*arr)[BCOLS], int rows);
bool multiplyMatrix(int[][COLS], int, int[][BCOLS], int, int[][CCOLS], int);
void main()
{
    srand(time(NULL));
    int a[ROWS][COLS]; int a1[ROWS][COLS]; int a2[ROWS][COLS];
    int b[BROWS][BCOLS];
    int c[CROWS][CCOLS];

    getMatrixA(a, ROWS);
    printf("a\n");
    showMatrix(a, ROWS);
    getMatrixA(a1, ROWS);
    printf("a1\n");
    showMatrix(a1, ROWS);
   
    addMatrix(a, ROWS, a1, ROWS, a2, ROWS);
    printf("a2\n");
    showMatrix(a2, CROWS);
    getMatrixB(b, BROWS);
    printf("b\n");
    showMatrixB(b, BROWS);
    multiplyMatrix(a, ROWS, b, BROWS, c, CROWS);
    showMatrix(c, CROWS);
    
    system("pause");
}
//int getMatrix(int(*arr)[], int rows, int cols)
bool getMatrixA(int(*arr)[COLS], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            *(*(arr + i) + j) = rand() % 10;
        }
    }
    return true;
}

bool getMatrixB(int(*arr)[BCOLS], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            *(*(arr + i) + j) = rand() % 10;
        }
    }
    return true;
}

bool showMatrix(int(*arr)[COLS], int rows) {
    printf("\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
    printf("\n");

    return true;
}

bool showMatrixB(int(*arr)[BCOLS], int rows) {
    printf("\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
    printf("\n");

    return true;
}

bool addMatrix(int(*arr1)[COLS], int row1, int(*arr2)[COLS], int row2, int(*arr3)[COLS], int row3) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < COLS; j++) {
            *(*(arr3 + i) + j) = *(*(arr1 + i) + j) + *(*(arr2 + i) + j);
        }
    }
    return true;
}

bool multiplyMatrix(int(*arr1)[COLS], int row1, int(*arr2)[BCOLS], int row2, int(*arr3)[CCOLS], int row3) {
    int value;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < COLS; j++) {
            value += *(*(arr1 + i) + j) + *(*(arr2 + j) + i);
        }
    }
}