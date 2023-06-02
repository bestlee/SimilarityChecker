#include "pch.h"
#include "../SimilarityCheck/Checker.cpp"

class SimilatityFixture : public testing::Test
{
public:
	Checker checkSimilar;
};
TEST_F(SimilatityFixture, InvalidArgument)
{
	EXPECT_THROW(checkSimilar.CheckSimirality("","ABC"), std::invalid_argument);
	EXPECT_THROW(checkSimilar.CheckSimirality("ABC",""), std::invalid_argument);
	EXPECT_THROW(checkSimilar.CheckSimirality("123", "ABC"), std::invalid_argument);
	EXPECT_THROW(checkSimilar.CheckSimirality("ABC", "123"), std::invalid_argument);
	EXPECT_THROW(checkSimilar.CheckSimirality("abc", "ABC"), std::invalid_argument);
}

TEST_F(SimilatityFixture, PerfectMatch)
{
	EXPECT_EQ(MAX_LENGTH_SCORE, checkSimilar.CheckSimirality("ABC", "ABC"));
	EXPECT_EQ(MAX_LENGTH_SCORE, checkSimilar.CheckSimirality("ABCDE", "ABCDE"));
	EXPECT_EQ(MAX_LENGTH_SCORE, checkSimilar.CheckSimirality("ABCDEF", "ABCDEF"));
}

TEST_F(SimilatityFixture,lengthMisMatch)
{
	EXPECT_EQ(0, checkSimilar.CheckSimirality("A", "BB"));
	EXPECT_EQ(MAX_LENGTH_SCORE, checkSimilar.CheckSimirality("ASD", "DSA"));
	EXPECT_EQ(20, checkSimilar.CheckSimirality("AAABB", "BAA"));
	EXPECT_EQ(30, checkSimilar.CheckSimirality("AA", "AAA"));
}