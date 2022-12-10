#include "../aoc-utils/aocIncludes.h"

void updateLocationsAsNeeded(std::pair<int, int> &currentLink, std::pair<int, int> &previousLink)
{
	if (abs(previousLink.first - currentLink.first) > 1 || abs(previousLink.second - currentLink.second) > 1)
	{
		if (previousLink.first == currentLink.first || previousLink.second == currentLink.second)
		{
			if (previousLink.first - currentLink.first == 2)
			{
				currentLink.first++;
			}
			else if (currentLink.first - previousLink.first == 2)
			{
				currentLink.first--;
			}
			else if (previousLink.second - currentLink.second == 2)
			{
				currentLink.second++;
			}
			else if (currentLink.second - previousLink.second == 2)
			{
				currentLink.second--;
			}
		}
		else
		{
			if (previousLink.first > currentLink.first && previousLink.second > currentLink.second)
			{
				currentLink.first++;
				currentLink.second++;
			}
			else if (previousLink.first > currentLink.first && previousLink.second < currentLink.second)
			{
				currentLink.first++;
				currentLink.second--;
			}
			else if (previousLink.first < currentLink.first && previousLink.second < currentLink.second)
			{
				currentLink.first--;
				currentLink.second--;
			}
			else if (previousLink.first < currentLink.first && previousLink.second > currentLink.second)
			{
				currentLink.first--;
				currentLink.second++;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	// Open File
	std::string fileName(__FILE_NAME__);
	fileName.replace(fileName.end() - 3, fileName.end(), "txt");
	std::ifstream infile(fileName);

	// Variable Declarations
	int headX = 0, headY = 0, tailX = 0, tailY = 0;
	std::vector<std::pair<int, int>> tailLocations;
	tailLocations.emplace_back(tailX, tailY);
	std::vector<std::pair<int, int>> pastHeadLocations(10, std::pair<int, int>(0, 0));
	int answer1 = 0, answer2 = 0;
	char direction;
	int magnitude;

	// Solution
	while (infile >> direction >> magnitude)
	{
		switch (direction)
		{
		case 'U':
			for (size_t i = 0; i < magnitude; i++)
			{
				headY++;
				if (headY - tailY == 2)
				{
					tailY++;
					if (headX != tailX)
					{
						tailX = headX;
					}
					if (std::find(tailLocations.begin(), tailLocations.end(), std::pair<int, int>(tailX, tailY)) == tailLocations.end())
					{
						tailLocations.emplace_back(tailX, tailY);
					}
				}
			}
			break;
		case 'D':
			for (size_t i = 0; i < magnitude; i++)
			{
				headY--;
				if (tailY - headY == 2)
				{
					tailY--;
					if (headX != tailX)
					{
						tailX = headX;
					}
					if (std::find(tailLocations.begin(), tailLocations.end(), std::pair<int, int>(tailX, tailY)) == tailLocations.end())
					{
						tailLocations.emplace_back(tailX, tailY);
					}
				}
			}
			break;
		case 'R':
			for (size_t i = 0; i < magnitude; i++)
			{
				headX++;
				if (headX - tailX == 2)
				{
					tailX++;
					if (headY != tailY)
					{
						tailY = headY;
					}
					if (std::find(tailLocations.begin(), tailLocations.end(), std::pair<int, int>(tailX, tailY)) == tailLocations.end())
					{
						tailLocations.emplace_back(tailX, tailY);
					}
				}
			}
			break;
		case 'L':
			for (size_t i = 0; i < magnitude; i++)
			{
				headX--;
				if (tailX - headX == 2)
				{
					tailX--;
					if (headY != tailY)
					{
						tailY = headY;
					}
					if (std::find(tailLocations.begin(), tailLocations.end(), std::pair<int, int>(tailX, tailY)) == tailLocations.end())
					{
						tailLocations.emplace_back(tailX, tailY);
					}
				}
			}
			break;
		}
	}

	answer1 = tailLocations.size();

	infile.close();
	infile.open(fileName);

	tailLocations.clear();
	tailLocations.emplace_back(tailX, tailY);

	while (infile >> direction >> magnitude)
	{
		for (size_t i = 0; i < magnitude; i++)
		{
			switch (direction)
			{
			case 'R':
				pastHeadLocations[0].first++;
				break;
			case 'L':
				pastHeadLocations[0].first--;
				break;
			case 'U':
				pastHeadLocations[0].second++;
				break;
			case 'D':
				pastHeadLocations[0].second--;
				break;
			}

			for (size_t j = 1; j < pastHeadLocations.size(); j++)
			{
				updateLocationsAsNeeded(pastHeadLocations[j], pastHeadLocations[j - 1]);
			}

			if (std::find(tailLocations.begin(), tailLocations.end(), pastHeadLocations[9]) == tailLocations.end())
			{
				std::cout << pastHeadLocations[9].first << " " << pastHeadLocations[9].second << std::endl;
				tailLocations.push_back(pastHeadLocations[9]);
			}
		}
	}

	answer2 = tailLocations.size();

	// Print Answer
	std::cout << "Answer 1: " << answer1 << std::endl
			  << "Answer 2: " << answer2 << std::endl;

	return 0;
}
