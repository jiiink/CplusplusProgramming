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
bool addMatrix(int[][COLS], int, int[][COLS], int, int[][COLS], int);
bool getMatrix(int(*arr)[COLS], int rows);
bool multiplyMatrix(int[][COLS], int, int[][BCOLS], int, int[][CCOLS], int);
void main()
{
    srand(time(NULL));
    int a[ROWS][COLS]; int a1[ROWS][COLS]; int a2[ROWS][COLS];
    int b[BROWS][BCOLS];
    int c[CROWS][CCOLS];

    getMatrix(a, ROWS);
    showMatrix(a, ROWS);
    getMatrix(a1, ROWS);
    showMatrix(a1, ROWS);
   
    addMatrix(a, ROWS, a1, ROWS, a2, ROWS);
    showMatrix(a2, CROWS);
    getMatrix(b, BROWS);
    showMatrix(b, BROWS);
    multiplyMatrix(a, ROWS, b, BROWS, c, CROWS);
    showMatrix(c, CROWS);
    system("pause");
}
//int getMatrix(int(*arr)[], int rows, int cols)
bool getMatrix(int(*arr)[COLS], int rows)
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
