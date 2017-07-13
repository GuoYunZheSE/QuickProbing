#include <iostream>
using namespace std;
int main()
{
	double** Matrix;
	Matrix = new double*[];
	double alpha;//The threshold of Matrix.
	int min_r;//The minmum number of Rows of the minning pattern.
	int min_t;//The minmum number of Column of the minning pattern.

	double*** upsilon;//The set of submatrices of Matrix.
	upsilon = new double**[];

	int *CR = new int[];//The set of Rows that has been mined for at least one times.
	int *CT = new int[];//The set of Columns that has been mined for at least one times.
	
}