#include "matrix.h"
// 제공파일
// matrix_run.cpp 파일은 수정하지 않습니다.
int main()
{
	// mx1
	cout << "행렬1" << endl;
	Matrix matrix1(3, 4);
	matrix1.setup();
	matrix1.print();

	// mx2
	cout << "행렬2" << endl;
	Matrix matrix2(3, 4);
	matrix2.setup();
	matrix2.print();

	// mx3
	cout << "행렬3" << endl;
	Matrix matrix3(4, 2);
	matrix3.setup();
	matrix3.print();

	// +
	cout << "행렬1 + 행렬2" << endl;
	Matrix addResult(3, 4);
	matrix1.add(matrix2, addResult);
	addResult.print();

	// -
	cout << "행렬1 - 행렬2" << endl;
	Matrix subResult(3, 4);
	matrix1.subtract(matrix2, subResult);
	subResult.print();

	// *
	cout << "행렬1 * 행렬2" << endl;
	Matrix mulResult(3, 2);
	matrix1.multiply(matrix3, mulResult);
	mulResult.print();

	return 0;
}