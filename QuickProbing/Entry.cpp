#include "Entry.h"

bool operator==(const Entry & E1, const Entry& E2)
{
	if (E1.ColumnNumber == E2.ColumnNumber&&E1.RowNumber == E2.RowNumber&&E1.Value == E2.Value)
	{
		return true;
	}
	else
	{
		return false;
	}
}
