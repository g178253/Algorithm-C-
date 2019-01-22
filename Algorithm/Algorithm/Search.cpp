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

bool Search::bfs_search(const map<string, vector<string>> graph, const string& start, const string& match)
{
	queue<string> search;
	vector<string> searched;

	auto iter = graph.find(start);
	if (iter == graph.end())
		throw invalid_argument{ "参数无效：未找到与 start 匹配的元素" };

	for (auto &p : iter->second)
	{
		search.push(p);
	}
	
	string value;
	while (!search.empty())
	{
		value = search.front();
		search.pop();

		for (auto& p : searched)
		{
			if (p == value) continue; // 已查询过，不再查询。
		}

		if (value == match) // 匹配成功，返回。
		{
			return true;
		}
		else
		{
			iter = graph.find(value);
			if (iter != graph.end())
			{
				for (auto &p : iter->second)
				{
					search.push(p);	// 将它的邻居添加到待查队列。
				}
			}
			searched.push_back(value);
		}
	}

	return false;
}
