#include "pch.h"
#include "../Algorithm/Search.h"

TEST(SearchTest, binary_search) {
	using namespace std;

	vector<int> list{ 1,3,5,7,9 };
	Search s;
	auto i = s.binary_search(list, 9);
	EXPECT_EQ(4, i);
}