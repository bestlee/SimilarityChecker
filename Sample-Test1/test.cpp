#include "pch.h"
#include "../SimilarityCheck/Checker.cpp"

TEST(TC_Length, InvalidArgument)
{
	EXPECT_THROW(Checker().CheckSimirality("","ABC"), std::invalid_argument);
	EXPECT_THROW(Checker().CheckSimirality("ABC",""), std::invalid_argument);
	EXPECT_THROW(Checker().CheckSimirality("123", "ABC"), std::invalid_argument);
	EXPECT_THROW(Checker().CheckSimirality("ABC", "123"), std::invalid_argument);
	EXPECT_THROW(Checker().CheckSimirality("abc", "ABC"), std::invalid_argument);
}

TEST(TC_Length, PerfectMatch)
{
	EXPECT_EQ(MAX_LENGTH_SCORE, Checker().CheckSimirality("ABC", "ABC"));
	EXPECT_EQ(MAX_LENGTH_SCORE, Checker().CheckSimirality("ABCDE", "ABCDE"));
	EXPECT_EQ(MAX_LENGTH_SCORE, Checker().CheckSimirality("ABCDEF", "ABCDEF"));
}

TEST(TC_Length,lengthMisMatch)
{
	EXPECT_EQ(0, Checker().CheckSimirality("A", "BB"));
	EXPECT_EQ(MAX_LENGTH_SCORE, Checker().CheckSimirality("ASD", "DSA"));
	EXPECT_EQ(20, Checker().CheckSimirality("AAABB", "BAA"));
	EXPECT_EQ(30, Checker().CheckSimirality("AA", "AAA"));
}