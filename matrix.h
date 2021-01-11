#pragma once
// 제공파일
// matrix.h 파일은 수정하지 않습니다.
#include <iostream>
#ifndef MATRIX_H
#define MATRIX_H
#include <cmath>
#include <cstdlib>
#include <iomanip> 
using namespace std;

// Matrix 클래스 정의
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