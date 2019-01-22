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
		throw invalid_argument{ "������Ч��δ�ҵ��� start ƥ���Ԫ��" };

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
			if (p == value) continue; // �Ѳ�ѯ�������ٲ�ѯ��
		}

		if (value == match) // ƥ��ɹ������ء�
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
					search.push(p);	// �������ھ���ӵ�������С�
				}
			}
			searched.push_back(value);
		}
	}

	return false;
}
