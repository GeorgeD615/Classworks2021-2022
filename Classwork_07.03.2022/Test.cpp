#include "gtest/gtest.h"
#include "Arr.h"

TEST(ArrayT, BadInitSize) {
	ASSERT_THROW((Arr<int>(-1)), BadSize);
}

TEST(ArrayT, Size) {
	Arr<int> a;
	a.AddElement(3);
	EXPECT_EQ(1, a.GetSIZE());
	a.AddElement(4);
	ASSERT_NE(3, a.GetSIZE());

	a.AddElement(5);
	EXPECT_EQ(3, a.GetSIZE());
	ASSERT_GT(a.GetSIZE(), 2);
	ASSERT_GE(a.GetSIZE(), 3);
	ASSERT_TRUE(a.GetSIZE()== 3);
}

TEST(ArrayT, GetElement) {
	Arr<int> a;
	a.AddElement(3);
	EXPECT_EQ(3, a.GetElement(0));
	EXPECT_EQ(3, a[0]);
	ASSERT_THROW(a[-1], BadSize);
}
