#pragma once
class Entry
{
public:
	Entry();
	Entry(int, int, int);
	~Entry();
	int RowNumber;
	int ColumnNumber;
	int Value;
	bool Valid;
	friend bool operator==(const Entry& E1, const Entry& E2);
private:

};

Entry::Entry()
{
	Valid = false;
}

Entry::Entry(int m_RN, int m_CN, int m_Value)
{
	RowNumber = m_RN;
	ColumnNumber = m_CN;
	Value = m_Value;
	Valid = true;
}

Entry::~Entry()
{
}