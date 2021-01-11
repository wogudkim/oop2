#include "matrix.h"
// ��������
// matrix_run.cpp ������ �������� �ʽ��ϴ�.
int main()
{
	// mx1
	cout << "���1" << endl;
	Matrix matrix1(3, 4);
	matrix1.setup();
	matrix1.print();

	// mx2
	cout << "���2" << endl;
	Matrix matrix2(3, 4);
	matrix2.setup();
	matrix2.print();

	// mx3
	cout << "���3" << endl;
	Matrix matrix3(4, 2);
	matrix3.setup();
	matrix3.print();

	// +
	cout << "���1 + ���2" << endl;
	Matrix addResult(3, 4);
	matrix1.add(matrix2, addResult);
	addResult.print();

	// -
	cout << "���1 - ���2" << endl;
	Matrix subResult(3, 4);
	matrix1.subtract(matrix2, subResult);
	subResult.print();

	// *
	cout << "���1 * ���2" << endl;
	Matrix mulResult(3, 2);
	matrix1.multiply(matrix3, mulResult);
	mulResult.print();

	return 0;
}