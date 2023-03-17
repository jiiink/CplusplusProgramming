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
bool showMatrix(int(*)[COLS], int);
bool showMatrixB(int(*arr)[BCOLS], int rows);
bool showMatrixC(int(*arr)[CCOLS], int rows);
bool addMatrix(int(*)[COLS], int, int(*)[COLS], int, int(*)[COLS], int);
bool getMatrixA(int(*arr)[COLS], int rows);
bool getMatrixB(int(*arr)[BCOLS], int rows);
bool multiplyMatrix(int(*)[COLS], int, int(*)[BCOLS], int, int(*)[CCOLS], int);
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

    //printf("%d\n", *(*(a + 0) + 2) * *(*(b + 2) + 0));
    
    multiplyMatrix(a, ROWS, b, BROWS, c, CROWS);
    
    printf("c\n");
    showMatrixC(c, CROWS);
    /**/
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
        for (int j = 0; j < BCOLS; j++)
        {
            *(*(arr + i) + j) = rand() % 10;
        }
    }
    return true;
}

bool showMatrix(int(*arr)[COLS], int rows) {
    

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
    

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
    printf("\n");

    return true;
}

bool showMatrixC(int(*arr)[CCOLS], int rows) {
    

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < CCOLS; j++) {
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
    //if (ac != br)return false;
    //printf("____________\n");
    //showMatrixB(arr2, row2);
    for (int x = 0; x < row3; x++) { //initialized arr3 because without this, the result of arr3 is soooooo weird. why????
        for (int y = 0; y < CCOLS; y++) {
            *(*(arr3 + x) + y) = 0;
        }
    }
    showMatrixC(arr3, row3);

    for (int x = 0; x < row3; x++) {
        for (int y = 0; y < CCOLS; y++) {
            //행렬 곱셈 구현
            
            for (int i = 0; i < COLS; i++) {
                //if (y == 3) { printf("%d \n", *(*(arr2 + i) + y)); }
                //arr3[x][y] += arr1[x][i] * arr2[i][y];
                *(*(arr3 + x) + y) += *(*(arr1 + x) + i) * *(*(arr2 + i) + y);
                //printf("%d ", *(*(arr3 + x) + y));
            }
            
            //printf("%d ", *(*(arr3 + x) + y));
        }
    }
    //printf("%d\n", *(*(arr1 + 0) + COLS-1));
    //printf("%d, %d\n", *(*(arr3 + 1) + 4), *(*(arr3 + 2) + 4)); well, this time, the last item of each rows is weird.
    return true;
}