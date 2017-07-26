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
	double density;
	int dRr;
	void ReadData(const Entry& m_entry);
private:

};

Row::Row():entries()
{
	entries.reserve(10000);//Set the default size to 10000, so the times of vector resize will be reduced
}

inline void Row::ReadData(const Entry& m_entry)
{
	this->entries.insert(entries.begin()+m_entry.ColumnNumber, m_entry);
}

Row::~Row()
{
}