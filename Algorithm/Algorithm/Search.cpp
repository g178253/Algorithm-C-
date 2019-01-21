#include "pch.h"
#include "Search.h"

int Search::binary_search(const vector<int>& list, int item) const
{
	int low = 0,
		high = list.size(),
		mid = 0;

	while (true)
	{
		mid = (low + high) / 2;
		if (list[mid] == item)
			return mid;
		else if (list[mid] > item)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
