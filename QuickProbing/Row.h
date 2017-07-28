#pragma once
#include <vector>
#include "Entry.h"
using namespace std;
class Row
{
public:
	Row();
	~Row();
	int RowNumber;
	vector<Entry> entries;
	int ValidNumber;
	int dRr;
	double density;

	bool Row_dRr_Compare(const Row& R1, const Row& R2);
	bool Row_RN_Compare(const Row& R1, const Row& R2);
	void ReadData(const Entry& m_entry);
	double getDensity(int T); 

	friend bool operator==(const Row& R1, const Row& R2);
	friend bool operator<(const Row& R1, const Row& R2);
	friend bool operator>(const Row& R1, const Row& R2);
private:

};

Row::Row():entries()
{
	this->ValidNumber = 0;
	dRr = 0;
	entries.reserve(10000);//Set the default size to 10000, so the times of vector resize will be reduced
}

inline void Row::ReadData(const Entry& m_entry)
{
	this->ValidNumber++;
	this->RowNumber = m_entry.RowNumber;
	this->entries.insert(entries.begin()+m_entry.ColumnNumber, m_entry);
}

Row::~Row()
{
}

inline bool Row::Row_dRr_Compare(const Row & R1, const Row & R2)
{
	return R1.dRr < R2.dRr;
}

inline bool Row::Row_RN_Compare(const Row & R1, const Row & R2)
{
	return R1.RowNumber < R2.RowNumber;
}
