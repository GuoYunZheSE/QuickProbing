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
		RTE.T[m_Column].ReadData(temp_Entry);//Insert entry to the row with the same column number
	}
	for (int i = 0; RTE.CRChange || RTE.CTChange; i++)
	{
		Pattern temp_Pattern;
		temp_Pattern.Tau = RTE.T;
		while (temp_Pattern.Tau.size!=0)
		{

		}
	}
}