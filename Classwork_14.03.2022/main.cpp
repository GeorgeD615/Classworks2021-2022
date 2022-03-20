#include <iostream>
#include "Arr.h"
#include "gtest/gtest.h"

TEST(ArrrayT, MarkerUSE)
{
	Arr<int> a;
	a.AddElement(3);
	a.AddElement(4);
	a.AddElement(5);

	a.rewind();
	for (size_t k = 0; k < a.GetSIZE(); ++k) {
		EXPECT_EQ(k+3, a.GetCurValue());
		a.Move2Next();
	}

	a.rewind();
	size_t k = 3;
	while (a.canMove2Next()) {
		EXPECT_EQ(k, a.GetCurValue());
		a.Move2Next();
		++k;
	}


	
}

