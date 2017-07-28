#include "Row.h"

bool operator==(const Row & R1, const Row & R2)
{
	if (R1.RowNumber == R2.RowNumber&&R1.entries.size() == R2.entries.size()&&R1.density == R2.density)
	{
		return true;
	}
	else
	{
		return false;
	}
	/*后期考考虑改进程序使得通过引用地址的相同来判断
	if (&R1 == &R2)
	{
		return true;
	}
	else
	{
		return false;
	}
	*/
}

bool operator<(const Row & R1, const Row & R2)
{
	if (R1.RowNumber < R2.RowNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator>(const Row & R1, const Row & R2)
{
	if (R1.RowNumber > R2.RowNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
}
double Row::getDensity(int T)
{
	return this->ValidNumber / T;
}
