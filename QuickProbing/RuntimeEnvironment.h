#pragma once
#include "Pattern.h"
class RunTimeEnvironment
{
public:
	RunTimeEnvironment();
	~RunTimeEnvironment();
	void VR_Updata();
	void VT_Updata();
	vector<Row> CR;//Row has been covered in at least on pattern
	vector<Column> CT;//Column has been covered in at least on pattern
	int VR;
	int VT;
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

void RunTimeEnvironment::VR_Updata()
{
	int maxmum = this->CR[0].dRr;
	for (vector<Row>::iterator biggest = this->CR.begin(); biggest != this->CR.end(); biggest++)
	{
		if ((*biggest).dRr >= maxmum)
		{
			maxmum = (*biggest).dRr;
		}
	}
	this->VR = maxmum;
}

void RunTimeEnvironment::VT_Updata()
{
	int maxmum = this->CT[0].dTt;
	for (vector<Column>::iterator biggest = this->CT.begin(); biggest != this->CT.end(); biggest++)
	{
		if ((*biggest).dTt >= maxmum)
		{
			maxmum = (*biggest).dTt;
		}
	}
	this->VT = maxmum;
}