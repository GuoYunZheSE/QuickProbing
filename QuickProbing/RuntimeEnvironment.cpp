#include "RuntimeEnvironment.h"
void RunTimeEnvironment::CR_Update(vector<Row>& R)
{
	sort(R.begin(), R.end(), Row::Row_RN_Compare);
	sort(this->CR.begin(),this->CR.end(), Row::Row_RN_Compare);
	vector<Row> Temp;
	set_union(this->CR.begin(), this->CR.end(), R.begin(), R.end(),Temp.begin());
	this->CR = Temp;
}

void RunTimeEnvironment::CT_Update(vector<Column>& C)
{
	sort(C.begin(), C.end(), Column::Column_CN_Compare);
	sort(this->CT.begin(), this->CT.end(), Column::Column_CN_Compare);
	vector<Column> Temp;
	set_union(this->CT.begin(), this->CT.end(), C.begin(), C.end(), Temp.begin());
	this->CT = Temp;
}

vector<Row> RunTimeEnvironment::SelectRows(vector<Row>& PtauQ)
{
	vector<Row> P;
	for (vector<Row>::iterator iter = PtauQ.begin(); iter != PtauQ.end(); iter++)
	{
		if ((*iter).getDensity(this->Tsize) < this->alpha)
		{
			PtauQ.erase(iter);
		}
	}
	if (PtauQ.size() < this->Rminimum)
	{
		return vector<Row>(0);
	}
	else
	{
		sort(PtauQ.begin(), PtauQ.end(), Row::Row_dRr_Compare);
		for (vector<Row>::iterator iter = PtauQ.begin(); iter != PtauQ.end(); iter++)
		{
			if ((*iter).dRr<=PtauQ[this->Rminimum-1].dRr)//for each r in P'(¦Ó_Q ) and d^R (r)¡Üd^R (r_min-1)  do
			{
				P.push_back(*(iter)); // Add r to P;
			}
		}
		return P;
	}
}
