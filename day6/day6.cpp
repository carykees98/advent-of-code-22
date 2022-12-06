#include "../aoc-utils/aocIncludes.h"

bool unique(std::string &data)
{
	for (size_t i = 0; i < data.size(); i++)
	{
		for (size_t j = i + 1; j < data.size(); j++)
		{
			if (data[i] == data[j])
			{
				return false;
			}
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	// Open File
	std::string fileName(__FILE_NAME__);
	fileName.replace(fileName.end() - 3, fileName.end(), "txt");
	std::ifstream infile(fileName);

	// Variable declarations
	int answer1 = 0, answer2 = 0;
	std::string line;

	// Solution
	for (size_t i = 0; i < 4; i++)
	{
		line.push_back(infile.get());
		answer1++;
	}

	while (!infile.eof())
	{
		line.push_back(infile.get());
		line.erase(line.begin());
		answer1++;

		if (unique(line))
		{
			break;
		}
	}

	infile.close();
	infile.open(fileName);
	line.clear();

	for (size_t i = 0; i < 14; i++)
	{
		line.push_back(infile.get());
		answer2++;
	}

	while (!infile.eof())
	{
		line.push_back(infile.get());
		line.erase(line.begin());
		answer2++;

		if (unique(line))
		{
			break;
		}
	}

	// Print Answer
	std::cout << "Answer 1: " << answer1 << std::endl
			  << "Answer 2: " << answer2 << std::endl;

	return 0;
}
