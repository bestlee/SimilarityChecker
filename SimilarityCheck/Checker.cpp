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

	int CalcLengthPoint(int longStrLength, int shortStrLength)
	{
		if (longStrLength == shortStrLength) return MAX_LENGTH_SCORE;
		else if (longStrLength >= (shortStrLength * 2)) return 0;

		return (1 - ((longStrLength - shortStrLength) / (double)shortStrLength)) * MAX_LENGTH_SCORE;;
	}

	int checkLength(const std::string str, const std::string str2)
	{
		int lengthCheck = 0;
		std::string longStr = str;
		std::string shortStr = str2;

		if (str.length() < str2.length())
		{
			longStr = str2;
			shortStr = str;
		}

		int longStrLength = longStr.length();
		int shortStrLength = shortStr.length();

		return CalcLengthPoint(longStrLength, shortStrLength);
	}

	int checkAlpha(const std::string str, const std::string str2)
	{
		int alphacheck = 0;

		return alphacheck;
	}
};
