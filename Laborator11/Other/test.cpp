#include "pch.h"
#include "functii.h"
#include "Sort.h"
#include <vector>
using namespace std;

/*TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
TEST(First, Test1) {
	EXPECT_EQ(1, 2);
	EXPECT_EQ(2, 3);
	EXPECT_EQ(3, 4);
	EXPECT_EQ(div2(5), 2);
	EXPECT_EQ(div2(6), 2);
}*/
TEST(VectorCresc, Test) {
	vector<int> v = { 1, 2, 3, 4, 5 };
	sortare_mea(v);
	vector<int> expect = { 1,2,3,4,5 };
	EXPECT_TRUE(v==expect);
	for (int i = 0;i < 5;i++) {
		EXPECT_EQ(v[i], expect[i]);
	}

}
TEST(VectorNul, Test) {
	vector<int> v2 = { 0,0,0,0,0 };
	sortare_mea(v2);
	vector<int> expect2 = { 0,0,0,0,0 };
	EXPECT_TRUE(v2 == expect2);
	for (auto i : v2) {
		EXPECT_EQ(v2[i], expect2[i]);
	}
}
TEST(Vector1, Test) {
	vector<int> v3 = { 1 };
	sortare_mea(v3);
	vector<int> expect3 = { 1 };
	EXPECT_TRUE(v3 == expect3);
	for (int i = 0;i < 1;i++) {
		cout << "Hello world!";
		EXPECT_EQ(v3[i], expect3[i]);
	}
}
TEST(Vector2, Test) {
	vector<int> v4 = { 2,2 };
	sortare_mea(v4);
	vector<int> expect4 = { 2,2 };
	EXPECT_TRUE(v4 == expect4);
	for (int i = 0;i < 2;i++) {
		EXPECT_EQ(v4[i], expect4[i]);
	}
}
TEST(VectorDesc, Test) {
	vector<int> v5 = { 5,4,3,2,1,0 };
	sortare_mea(v5);
	vector<int> expect5 = { 0,1,2,3,4,5 };
	EXPECT_TRUE(v5 == expect5);
	for (int i = 0;i < 6;i++) {
		cout << i << endl;
		EXPECT_EQ(v5[i], expect5[i]);
	}
}