#include <stdexcept>
#include <string>

#define  MAX_LENGTH_SCORE (60)
class Checker
{
public:
	int CheckSimirality(const std::string str, const std::string str2)
	{
		int result = 0;

		ArgValidCheck(str, str2);

		result += checkLength(str, str2);
		result += checkAlpha(str, str2);
		return result;
	}
private:
	void ArgValidCheck(const std::string str, const std::string str2)
	{
		if (str == "" || str2 == "")
		{
			throw std::invalid_argument("값을 넣어야함");
		}

		for (char c : str)
		{
			if (c < 'A' || c > 'Z')
			{
				throw std::invalid_argument("Only upper Alphabet");
			}
		}
		for (char c : str2)
		{
			if (c < 'A' || c > 'Z')
			{
				throw std::invalid_argument("Only upper Alphabet");
			}
		}
	}

	int checkLength(const std::string str, const std::string str2)
	{
		int longStrLength = getLongLength(str, str2);
		int shortStrLength = getShortLength(str, str2);

		return CalcLengthPoint(longStrLength, shortStrLength);
	}

	bool isSameLength(int longStrLength, int shortStrLength)
	{
		return longStrLength == shortStrLength;
	}

	bool isNegativeValue(int longStrLength, int shortStrLength)
	{
		return longStrLength >= (shortStrLength * 2);
	}

	int CalcLengthPoint(int longStrLength, int shortStrLength)
	{
		if (isSameLength(longStrLength, shortStrLength)) return MAX_LENGTH_SCORE;
		else if (isNegativeValue(longStrLength, shortStrLength)) return 0;

		return (MAX_LENGTH_SCORE - (MAX_LENGTH_SCORE*(longStrLength - shortStrLength) / shortStrLength));
	}

	int getLongLength(const std::string str, const std::string str2)
	{
		if (str.length() < str2.length())
		{
			return str2.length();
		}
		return str.length();
	}

	int getShortLength(const std::string str, const std::string str2)
	{
		if (str.length() > str2.length())
		{
			return str2.length();
		}

		return str.length();
	}


	int checkAlpha(const std::string str, const std::string str2)
	{
		int alphacheck = 0;

		return alphacheck;
	}
};
