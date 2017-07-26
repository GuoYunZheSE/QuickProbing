#pragma once
#include "Row.h"
#include "Column.h"
class Submatrix
{
public:
	Submatrix();
	~Submatrix();
	vector<Row> P;
	vector<Column> Q;
private:

};

Submatrix::Submatrix()
{
}

Submatrix::~Submatrix()
{
}