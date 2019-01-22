#include "pch.h"
#include "Search.h"
#include <iostream>

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

bool Search::bfs_search(const map<string, string> graph, const string& match)
{
	queue<string> search;
	vector<string> searched;

	for (auto &p : graph)
	{
		if (p.second == "you")
		{
			search.push(p.first);
		}
	}
	
	string key, value;
	auto isSearched{ false };
	while (!search.empty())
	{
		value = search.front();
		search.pop();
		isSearched = false;

		for (auto& i : searched)
		{
			if (i == value)
			{
				isSearched = true;
				break;
			}
		}

		if (!isSearched)
		{
			isSearched = true;

			if (value == match)
			{
				return true;
			}
			else
			{
				for (auto &p : graph)
				{
					if (p.second == value)
						search.push(p.first);
				}
				searched.push_back(value);
			}
		}
	}

	return false;
}
