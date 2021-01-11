#pragma once
// ��������
// matrix.h ������ �������� �ʽ��ϴ�.
#include <iostream>
#ifndef MATRIX_H
#define MATRIX_H
#include <cmath>
#include <cstdlib>
#include <iomanip> 
using namespace std;

// Matrix Ŭ���� ����
class Matrix
{
private:
    int rowSize;
    int colSize;
    int** ptr;
public:
    Matrix(int rowSize, int colSize);
    ~Matrix();
    void setup();
    void add(Matrix& second, Matrix& result);
    void subtract(Matrix& second, Matrix& result);
    void multiply(Matrix& second, Matrix& result);
    void print();
};
#endif