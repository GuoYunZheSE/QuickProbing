#pragma once
#include "Pattern.h"
class RunTimeEnvironment
{
public:
	RunTimeEnvironment();
	~RunTimeEnvironment();
	vector<Row> CR;//Row has been covered in at least on pattern
	vector<Column> CT;//Column has been covered in at least on pattern
	bool CRChange;//To determine whether CR has been changed/Expanded
	bool CTChange;
	vector<Row> R;
	vector<Column> T;
	int Rsize;
	int Tsize;
	double alpha;
	int Rminimum;
	int Tminimum;
	vector<Submatrix> Upsilon;//Patterns that has been mined

	void CR_Update(vector<Row>&);
	void CT_Update(vector<Column>&);
	vector<Row> SelectRows(vector<Row>&);
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