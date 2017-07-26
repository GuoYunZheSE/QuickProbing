#pragma once
#include "Submatrix.h"
#include <unordered_set>
class Pattern
{
public:
	Pattern();
	~Pattern();
	Submatrix m_Submatrix;//SOPSM already covered
	vector<Column> Tau;//Columns waiting for expansion
	vector<Column> TauQ;//Column Order
	vector<Row> SupportRow;//The set of rows that support one order tauQ.
	unordered_set<int> Hash;
	vector<int> List;
	Column PickCol(vector<Column>, vector<Row>);
	vector<Row> FindSuppSet(vector<Row>,Column);
private:

};

Pattern::Pattern()
{
}

Pattern::~Pattern()
{
}