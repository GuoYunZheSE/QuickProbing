#include "Pattern.h"

bool operator==(const vector<Row>& Vector1, const vector<Row>& Vector2)
{
	if (&Vector1 == &Vector2)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/************************PickCol****************************/
Column Pattern::PickCol(vector<Column> &m_Tau, vector<Row> &m_SupportRow)
{
	vector<Row> temp;
	vector<Column> C;
	sort(m_SupportRow.begin(), m_SupportRow.end(), Row::Row_dRr_Compare);//Sort by dRr
	sort(this->BaseRow.begin(), this->BaseRow.end(), Row::Row_dRr_Compare);
	set_difference(m_SupportRow.begin(), m_SupportRow.end(), this->BaseRow.begin(), this->BaseRow.end(), temp.begin());//PtauQ-B and the first element of temp will be r with minimum dRt

	this->BaseRow.push_back(temp[0]);

	for (vector<Column>::iterator iter = Tau.begin(); iter != Tau.end(); iter++)
	{
		if (isSubSet(this->BaseRow, FindSuppSet(this->SupportRow, *iter)))//if B ⊆ P(τ_(Q∪{ t })) then
		{
			C.push_back(*iter);//C:=C+t;
		}
	}

	//Pick t with smallest d^T (t) in C;
	sort(C.begin(), C.end(), Column::Column_dTt_Compare);
	return C[0];
}


/************************FindSuppSet****************************/
vector<Row> Pattern::FindSuppSet(vector<Row>& m_PtauQ, Column& tkp1)
{
	for (vector<Entry>::iterator iter = tkp1.entries.begin(); iter != tkp1.entries.end(); iter++)//for each entry in column Tk+1
	{
		if ((*iter).Valid)
		{
			if (this->m_List.find((*iter).RowNumber) != this->m_List.end())//if r in H-
			{
				continue;
			}
			else
			{
				unordered_map<int, int>::iterator map_iter = this->m_Hash.find((*iter).RowNumber);
				if (map_iter != this->m_Hash.end())// if r in Hash
				{
					if ((*map_iter).second <= (*iter).Value)//if the value stored in h+ is smaller than the value in tk+1 in the same row
					{
						this->m_Hash.erase(map_iter);//Erase old value
						this->m_Hash.insert((*iter).RowNumber, (*iter).Value);// H+(r):=M(r,tk+1);
						continue;
					}
				}
				else//if r doesn't in h- and h+, we insert r to H+ as key and M(r,tk+1) as value;
				{
					this->m_Hash.insert((*iter).RowNumber, (*iter).Value);
				}
			}
		}
		else//M(R,Tk+1) is not valid
		{
			continue;
		}
	}
	return vector<Row>();
}

bool Pattern::isSubSet(const vector<Row>& Vector1, const vector<Row>& Vector2)
{
	int i = 0;
	int j = 0;
	int m = Vector1.size();
	int n = Vector2.size();
	if (m>n) {
		return false;
	}
	sort(Vector1.begin(), Vector1.end(),Row::Row_RN_Compare);//order by Rownumber
	sort(Vector2.begin(), Vector2.end(),Row::Row_RN_Compare);
	while (i<n&&j<m) {
		if (Vector1[j]<Vector2[i]) {
			j++;
		}
		else if(Vector1[j] == Vector2[i]) {
			j++;
			i++;
		}
		else if(Vector1[j]>Vector2[i]) {
			return true;
		}
	}
	if (i<n) {
		return true;
	}
	else {
		return false;
	}
}