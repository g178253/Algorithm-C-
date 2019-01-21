#include "pch.h"
#include "Sort.h"

using namespace std;

void Sort::quick_sort(vector<int>& list, int lo, int hi)
{
	if (lo > hi) return;

	auto start = lo;
	auto end = hi;
	auto pivot = list[start];
	while (lo != hi)
	{
		while (lo < hi && list[hi] >= pivot) --hi;
		while (lo < hi && list[lo] <= pivot) ++lo;
		if (lo < hi)
		{
			auto tmp = list[lo];
			list[lo] = list[hi];
			list[hi] = tmp;
		}
	}
	list[start] = list[lo];
	list[lo] = pivot;

	quick_sort(list, start, lo - 1);
	quick_sort(list, lo + 1, end);
}
