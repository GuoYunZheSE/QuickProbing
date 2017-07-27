#pragma once
#include "Submatrix.h"
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <set>
class Pattern
{
public:
	Pattern();
	~Pattern();
	Submatrix m_Submatrix;//SOPSM already covered
	vector<Column> Tau;//Columns waiting for expansion
	vector<Column> TauQ;//Column Order
	vector<Row> SupportRow;//The set of rows that support one order tauQ.
	vector<Row> BaseRow;
	unordered_map<int, int> m_Hash;
	unordered_set<int> m_List;

	bool isSubSet(const vector<Row>&, const vector<Row>&);
	Column PickCol(vector<Column>&, vector<Row>&);
	vector<Row> FindSuppSet(vector<Row>&,Column&);

	friend bool operator==(const vector<Row>&, const vector<Row>&);
private:

};

Pattern::Pattern()
{
}

Pattern::~Pattern()
{
}




