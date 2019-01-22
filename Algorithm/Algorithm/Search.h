#pragma once

using namespace std;

class Search
{
public:
	int binary_search(const vector<int>& list, int item) const;
	bool bfs_search(const map<string, string> graph, const string& match);
};

