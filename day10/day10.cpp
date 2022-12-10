#include "../aoc-utils/aocIncludes.h"

int main(int argc, char const *argv[])
{
	// Open File
	std::string fileName(__FILE_NAME__);
	fileName.replace(fileName.end() - 3, fileName.end(), "txt");
	std::ifstream infile(fileName);

	// Variable Declarations
	int answer1 = 0, answer2 = 0;
	std::string line;
	std::vector<std::string> lines;
	int regis = 1;
	std::string command;
	int cycleNum = 1;
	int startingCycle = 0;
	int toAdd = 0;
	std::vector<char> screen(240);

	// Solution
	while (std::getline(infile, line))
	{
		lines.push_back(line);
	}

	for (size_t i = 0; i < lines.size(); i++)
	{
		startingCycle = cycleNum;
	iknowitsbad:
		command = lines[i].substr(0, 4);
		if (command == "addx")
		{
			toAdd = std::stoi(lines[i].substr(5));
		}

		if (cycleNum == 20)
		{
			answer1 += (regis * 20);
		}
		else if (cycleNum == 60)
		{
			answer1 += (regis * 60);
		}
		else if (cycleNum == 100)
		{
			answer1 += (regis * 100);
		}
		else if (cycleNum == 140)
		{
			answer1 += (regis * 140);
		}
		else if (cycleNum == 180)
		{
			answer1 += (regis * 180);
		}
		else if (cycleNum == 220)
		{
			answer1 += (regis * 220);
		}

		if (cycleNum <= 240)
		{
			int index = (cycleNum % 40) - 1;
			if (index == -1)
				index = 40;

			if (regis - index == -1 || regis - index == 0 || regis - index == 1)
				screen[cycleNum - 1] = '&';
			else
				screen[cycleNum - 1] = ' ';
		}

		cycleNum++;
		if (cycleNum - startingCycle == 1 && command == "addx")
		{
			goto iknowitsbad;
		}
		else
		{
			regis += toAdd;
			toAdd = 0;
		}
	}
	// Print Answer
	std::cout << "Answer 1: " << answer1 << std::endl
			  << "Answer 2: " << std::endl;
	for (size_t i = 1; i < 241; i++)
	{
		std::cout << screen[i - 1];
		if (i % 40 == 0)
		{
			std::cout << std::endl;
		}
	}

	return 0;
}
