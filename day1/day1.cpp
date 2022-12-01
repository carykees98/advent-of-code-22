#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
	std::ifstream infile("day1.txt");
	std::string tempCalorieCount;
	std::vector<int> elves;
	int answer = 0;
	int currentElfCals = 0;

	while (infile >> tempCalorieCount)
	{
		infile.get();
		if (infile.peek() == '\n')
		{
			currentElfCals += std::stoi(tempCalorieCount);
			elves.push_back(currentElfCals);
			currentElfCals = 0;
		}
		else
			currentElfCals += std::stoi(tempCalorieCount);
	}

	answer += *(std::max_element(elves.begin(), elves.end()));

	elves.erase(std::max_element(elves.begin(), elves.end()));

	answer += *(std::max_element(elves.begin(), elves.end()));

	elves.erase(std::max_element(elves.begin(), elves.end()));

	answer += *(std::max_element(elves.begin(), elves.end()));

	std::cout << answer << std::endl;

	return 0;
}
