#pragma once
#include <vector>
#include "Entry.h"
using namespace std;
class Column
{
public:
	Column();
	~Column();
	int ColumnNumber;
	int dTt;
	vector<Entry>entries;

	void ReadData(const Entry& m_Entry);
	bool Column_dTt_Compare(const Column& C1, const Column& C2);
private:

};

Column::Column()
{
	entries.reserve(10000);//Set the default size to 10000, so the times of vector resize will be reduced
}

Column::~Column()
{
}

inline void Column::ReadData(const Entry & m_entry)
{
	this->entries.insert(entries.begin() + m_entry.ColumnNumber, m_entry);
}

inline bool Column::Column_dTt_Compare(const Column & C1, const Column & C2)
{
	return C1.dTt < C2.dTt;
}
