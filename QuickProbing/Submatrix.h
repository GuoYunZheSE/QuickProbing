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
	double density;
	bool isEligible(double alpha,int rmin,int tmin);
private:

};

Submatrix::Submatrix()
{

}

Submatrix::~Submatrix()
{
}

bool Submatrix::isEligible(double alpha, int rmin, int tmin)
{
	int totalValidNumber = 0;
	for (vector<Row>::iterator iter = this->P.begin(); iter != this->P.end(); iter++)
	{
		totalValidNumber = totalValidNumber + (*iter).ValidNumber;
	}
	this->density = double(totalValidNumber) / double(this->P.size()*this->Q.size());
	if (this->density >= alpha&&this->P.size() >= rmin&&this->Q.size() >= tmin)
	{
		return true;
	}
	else
	{
		return false;
	}
}
