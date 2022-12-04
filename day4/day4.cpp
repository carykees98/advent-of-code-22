#include "../aoc-utils/aocIncludes.h"

int main(int argc, char const *argv[])
{
	// Open File
	std::string fileName(__FILE_NAME__);
	fileName.replace(fileName.end() - 3, fileName.end(), "txt");
	std::ifstream infile(fileName);

	// Variable declarations
	int answer1 = 0, answer2 = 0;
	std::string line, firstPair, secondPair;
	int pair1Bounds[2], pair2Bounds[2];
	int commaLocation = 0;

	// Solution
	while (infile >> line)
	{
		commaLocation = line.find(',');
		firstPair = line.substr(0, commaLocation);
		secondPair = line.substr(commaLocation + 1, line.length());

		pair1Bounds[0] = std::stoi(firstPair.substr(0, firstPair.find('-')));
		pair1Bounds[1] = std::stoi(firstPair.substr(firstPair.find('-') + 1));

		pair2Bounds[0] = std::stoi(secondPair.substr(0, secondPair.find('-')));
		pair2Bounds[1] = std::stoi(secondPair.substr(secondPair.find('-') + 1));

		if (pair1Bounds[0] <= pair2Bounds[0] && pair2Bounds[1] <= pair1Bounds[1])
		{
			answer1++;
		}
		else if (pair2Bounds[0] <= pair1Bounds[0] && pair1Bounds[1] <= pair2Bounds[1])
		{
			answer1++;
		}
	}

	infile.close();
	infile.open(fileName);

	while (infile >> line)
	{
		commaLocation = line.find(',');
		firstPair = line.substr(0, commaLocation);
		secondPair = line.substr(commaLocation + 1, line.length());

		pair1Bounds[0] = std::stoi(firstPair.substr(0, firstPair.find('-')));
		pair1Bounds[1] = std::stoi(firstPair.substr(firstPair.find('-') + 1));

		pair2Bounds[0] = std::stoi(secondPair.substr(0, secondPair.find('-')));
		pair2Bounds[1] = std::stoi(secondPair.substr(secondPair.find('-') + 1));

		if ((pair1Bounds[0] <= pair2Bounds[0] && pair1Bounds[1] >= pair2Bounds[0]) || (pair1Bounds[0] <= pair2Bounds[1] && pair1Bounds[1] >= pair2Bounds[1]))
		{
			answer2++;
		}
		else if ((pair2Bounds[0] <= pair1Bounds[0] && pair2Bounds[1] >= pair1Bounds[0]) || (pair2Bounds[0] <= pair1Bounds[1] && pair2Bounds[1] >= pair1Bounds[1]))
		{
			answer2++;
		}
	}

	// Print Answer
	std::cout << "Answer 1: " << answer1 << std::endl
			  << "Answer 2: " << answer2 << std::endl;

	return 0;
}
