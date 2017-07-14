#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int R, T;
	vector<vector<double>> Matrix(R, vector<double>(T));//The Dataset Matrix
	double alpha;//The threshold of Matrix.
	int min_r;//The minmum number of Rows of the minning pattern.
	int min_t;//The minmum number of Column of the minning pattern.

	vector<vector<vector<double>>> upsilon;//The set of submatrix

	vector<int> CR(0);//The set of Rows that has been mined for at least one times.
	vector<int> CT(0);//The set of Columns that has been mined for at least one times.
	vector<int> tau(0);//The set of Columns available for expansion.

	bool CR_Change = true;
	bool CT_Change = true;
	while (CR_Change&&CT_Change)//IF CR and CT don't converge
	{
		vector<int> Q(0);//The set of a SOPSM's Columns.
		T = Matrix[0].size;
		for (int i = 0; i < T; i++)//tau=T.
		{
			tau[i] = i;
		}
		 
	}
}