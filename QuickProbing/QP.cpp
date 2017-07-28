#include "RuntimeEnvironment.h"
#include <fstream>
#include <iostream>
#include <string>
int main()
{
	
	RunTimeEnvironment RTE;
	cout << "Please enter input file name:";
	string name;
	cin >> name;
	ifstream ist(name.c_str());
	if (!ist)
	{
		cerr << "Can't open input file";
	}

	int m_Row;
	int m_Column;
	int m_Value;
	while (ist >> m_Row >> m_Column >> m_Value)//Read a combination of statistics for data set.
	{
		Entry temp_Entry(m_Row, m_Column, m_Value);//For each combination, we construct a entry
		RTE.R[m_Row].ReadData(temp_Entry);//Insert entry to the row with the same row number
		RTE.T[m_Column].ReadData(temp_Entry);//Insert entry to the Column with the same column number
	}



	while(RTE.CRChange || RTE.CTChange)
	{
		RTE.CRChange = false;
		RTE.CTChange = false;
		Pattern temp_Pattern;
		temp_Pattern.Tau = RTE.T;
		while (temp_Pattern.Tau.size!=0)
		{
			Column t = temp_Pattern.PickCol(temp_Pattern.Tau, temp_Pattern.SupportRow);//t=PickCol(Tau,P(tauQ))
			if (t.ColumnNumber != -1)//one column is picked
			{
				temp_Pattern.Tau.erase(temp_Pattern.Tau.begin() + t.ColumnNumber);//Tau=Tau-{t}
				vector<Column> temp_Q = temp_Pattern.m_Submatrix.Q;
				temp_Q.push_back(t);//Q'=Q+{t}

				vector<Column> temp_TauQ = temp_Pattern.TauQ;
				temp_TauQ.push_back(t);//Q'=Q+{t}

				vector<Row> temp_PtauQ = temp_Pattern.FindSuppSet(temp_Pattern.SupportRow, t);
				vector<Row> P2 = RTE.SelectRows(temp_PtauQ);
			}
			else//no collumn is picked
			{
				if (temp_Pattern.m_Submatrix.isEligible(RTE.alpha, RTE.Rminimum, RTE.Tminimum))//If PQ is eligible
				{
					RTE.Upsilon.push_back(temp_Pattern.m_Submatrix);
					RTE.CT_Update(temp_Pattern.m_Submatrix.Q);
					RTE.CR_Update(temp_Pattern.m_Submatrix.P);
					continue;
				}
			}
		}
	}
}