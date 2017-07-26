#pragma once
#include "Pattern.h"
class RunTimeEnvironment
{
public:
	RunTimeEnvironment();
	~RunTimeEnvironment();
	vector<int> CR;//Row has been covered in at least on pattern
	vector<int> CT;//Column has been covered in at least on pattern
	bool CRChange;//To determine whether CR has been changed/Expanded
	bool CTChange;
	vector<Row> R;
	vector<Column> T;
	double alpha;
	int Rminimum;
	int Tminimum;
	vector<Submatrix> Upsilon;//Patterns that has been mined
	vector<Row> SelectRows(vector<Column>);
private:

};

RunTimeEnvironment::RunTimeEnvironment()
{
	CRChange = true;
	CTChange = true;
}

RunTimeEnvironment::~RunTimeEnvironment()
{
}