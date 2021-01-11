#include "matrix.h"
// �� ���ϸ� ����ִ� �Լ� �ڵ带 �ۼ��Ͽ� github �����Կ� Ŀ�� Ǫ���մϴ�.
// ������, setup(), print() �ڵ�� �ǵ帮�� �ʽ��ϴ�.
// ���ϸ� ������� github �����Կ� Ŀ�� Ǫ���մϴ�.

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
// Q1. �Ҹ���(destructor) �ڵ带 �ۼ��մϴ� (free heap memory)
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
// Q2. ���� �ڵ带 �ۼ��մϴ�
void Matrix::add(Matrix& second, Matrix& result)
{


}
// Q3. ���� �ڵ带 �ۼ��մϴ�
void Matrix::subtract(Matrix& second, Matrix& result)
{


}
// Q4. ���ϱ� �ڵ带 �ۼ��մϴ�
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