#include "pch.h"
#include "../Algorithm/Search.h"
#include "../Algorithm/Sort.h"

TEST(SearchTest, binary_search) {
	using namespace std;

	vector<int> list{ 1,3,5,7,9 };
	Search s;
	auto i = s.binary_search(list, 9);
	EXPECT_EQ(4, i);
}

TEST(SortTest, quick_sort) {
	using namespace std;

	vector<int> list{ 3,2,6,1,8,0,9 };
	Sort s;
	auto len = list.size();
	s.quick_sort(list, 0, len-1);

	for (auto i = 0; i+1 != len; ++i)
		EXPECT_TRUE(list[i] <= list[i+1]);
}