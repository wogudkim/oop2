#include "matrix.h"
// 이 파일만 비어있는 함수 코드를 작성하여 github 과제함에 커밋 푸시합니다.
// 생성자, setup(), print() 코드는 건드리지 않습니다.
// 파일명도 변경없이 github 과제함에 커밋 푸시합니다.

// constructor
Matrix::Matrix(int r, int c)
    : rowSize(r), colSize(c)
{
    ptr = new int* [rowSize];
    for (int i = 0; i < rowSize; i++)
    {
        ptr[i] = new int[colSize];
    }
}
// Q1. 소멸자(destructor) 코드를 작성합니다 (free heap memory)
Matrix::~Matrix()
{

}

// matrix initialization
void Matrix::setup()
{
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            ptr[i][j] = rand() % 5 + 1; // 1 ~ 5
        }
    }
}
// Q2. 덧셈 코드를 작성합니다
void Matrix::add(Matrix& second, Matrix& result)
{


}
// Q3. 뺄셈 코드를 작성합니다
void Matrix::subtract(Matrix& second, Matrix& result)
{


}
// Q4. 곱하기 코드를 작성합니다
void Matrix::multiply(Matrix& second, Matrix& result)
{


}
// print
void Matrix::print()
{
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            cout << setw(5) << ptr[i][j];
        }
        cout << endl;
    }
    cout << endl;
}