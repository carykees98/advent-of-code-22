#include "../aoc-utils/aocIncludes.h"
#include <array>

int main(int argc, char const *argv[])
{
	// Open File
	std::string fileName(__FILE_NAME__);
	fileName.replace(fileName.end() - 3, fileName.end(), "txt");
	std::ifstream infile(fileName);

	bool tallestUp = true, tallestDown = true, tallestRight = true, tallestLeft = true;

	// Variable declarations
	const int x = 99, y = 99;
	std::array<std::array<int, y>, x> lines;
	int answer1 = 2 * x + 2 * (y - 2);
	long long answer2 = 0;
	long long scenicScore = 1;

	// Solution
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			lines[i][j] = infile.get() - '0';
		}
		infile.get();
	}

	for (int i = 1; i < x - 1; i++)
	{
		for (int j = 1; j < y - 1; j++)
		{
			for (int k = 0; k < j; k++)
			{
				if (lines[i][j] <= lines[i][k])
				{
					tallestUp = false;
					break;
				}
			}
			for (int k = (j + 1); k < y; k++)
			{
				if (lines[i][j] <= lines[i][k])
				{
					tallestDown = false;
					break;
				}
			}
			for (int k = 0; k < i; k++)
			{
				if (lines[i][j] <= lines[k][j])
				{
					tallestLeft = false;
					break;
				}
			}
			for (int k = (i + 1); k < x; k++)
			{
				if (lines[i][j] <= lines[k][j])
				{
					tallestRight = false;
					break;
				}
			}
			if (tallestUp || tallestDown || tallestRight || tallestLeft)
			{
				answer1++;
			}
			tallestUp = tallestDown = tallestRight = tallestLeft = true;
		}
	}

	int k;
	int up = 0, down = 0, left = 0, right = 0;

	for (size_t i = 1; i < (x - 1); i++)
	{
		for (size_t j = 1; j < (y - 1); j++)
		{
			k = i;
			do
			{
				k--;
				left++;
			} while (lines[k][j] < lines[i][j] && k != 0);
			k = i;
			do
			{
				k++;
				right++;
			} while (lines[k][j] < lines[i][j] && k != (x - 1));
			k = j;
			do
			{
				k--;
				up++;
			} while (lines[i][k] < lines[i][j] && k != 0);
			k = j;
			do
			{
				k++;
				down++;
			} while (lines[i][k] < lines[i][j] && k != (y - 1));

			scenicScore = up * down * left * right;
			if (scenicScore > answer2)
			{
				answer2 = scenicScore;
			}
			scenicScore = 1;
			up = down = left = right = 0;
		}
	}

	// Print Answer
	std::cout << "Answer 1: " << answer1 << std::endl
			  << "Answer 2: " << answer2 << std::endl;

	return 0;
}
