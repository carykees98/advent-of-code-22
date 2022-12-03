#include "../aoc-utils/aocIncludes.h"

int main(int argc, char const *argv[])
{
	// Open File
	std::string fileName(__FILE_NAME__);
	fileName.replace(fileName.end() - 3, fileName.end(), "txt");
	std::ifstream infile(fileName);

	// Variable declarations
	int answer1, answer2;

	// Solution
	while (infile >>)
	{
	}

	// Print Answer
	std::cout << "Answer 1: " << answer1 << std::endl
			  << "Answer 2: " << answer2 << std::endl;

	return 0;
}
