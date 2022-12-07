#include "../aoc-utils/aocIncludes.h"
#include <map>

int main(int argc, char const *argv[])
{
	// Open File
	std::string fileName(__FILE_NAME__);
	fileName.replace(fileName.end() - 3, fileName.end(), "txt");
	std::ifstream infile(fileName);

	// Variable declarations
	std::map<std::string, long long> directories;
	std::vector<std::string> previousDirectories;
	std::vector<long long> possibleAnswer2Values;
	std::string currentDirectory = "/";
	long long answer1 = 0, answer2 = 0;
	std::string line;

	// Solution
	std::getline(infile, line);

	while (infile >> line)
	{
		if (line == "$")
		{
			infile >> line;
			if (line == "ls")
			{
				continue;
			}
			else if (line == "cd")
			{
				infile >> line;
				if (line == "..")
				{
					directories[previousDirectories[previousDirectories.size() - 1]] += directories[currentDirectory];
					currentDirectory = previousDirectories[previousDirectories.size() - 1];
					previousDirectories.pop_back();
				}
				else
				{
					previousDirectories.push_back(currentDirectory);
					currentDirectory += line;
				}
			}
		}
		else if (line == "dir")
		{
			infile >> line;
			line = currentDirectory + line;
			directories.emplace(line, 0);
		}
		else
		{
			directories[currentDirectory] += std::stoi(line);
			infile >> line;
		}
	}

	for (size_t i = 0; i < 2; i++)
	// At the end of the file, the current directory is still 2 deep, so this acts like 2 "$ cd .." calls
	{
		directories[previousDirectories[previousDirectories.size() - 1]] += directories[currentDirectory];
		currentDirectory = previousDirectories[previousDirectories.size() - 1];
		previousDirectories.pop_back();
	}

	for (auto [first, second] : directories)
	{
		if (second <= 100000)
		{
			answer1 += second;
		}

		if (30000000 - (70000000 - directories["/"]) <= second)
		{
			possibleAnswer2Values.push_back(second);
		}
	}

	answer2 = *std::min_element(possibleAnswer2Values.begin(), possibleAnswer2Values.end());

	// Print Answer
	std::cout << "Answer 1: " << answer1 << std::endl
			  << "Answer 2: " << answer2 << std::endl;

	return 0;
}
