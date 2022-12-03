#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char const *argv[])
{
	std::ifstream infile("day3.txt");
	int answer1 = 0;
	int answer2 = 0;
	std::string line;
	std::string firstHalf, secondHalf, alreadyUsed;

	while (infile >> line)
	{
		firstHalf = line.substr(0, line.length() / 2);
		secondHalf = line.substr(line.length() / 2);

		for (char &character : firstHalf)
		{
			if ((secondHalf.find(character) != std::string::npos) && (alreadyUsed.find(character) == std::string::npos))
			{
				if (isupper(character))
				{
					answer1 += character - 38;
				}
				else if (islower(character))
				{
					answer1 += character - 96;
				}
				alreadyUsed.push_back(character);
			}
		}
		alreadyUsed.clear();
	}

	std::string line2, line3;
	infile.close();
	infile.open("day3.txt");

	while (infile >> line >> line2 >> line3)
	{
		for (char &character : line)
		{
			if ((line2.find(character) != std::string::npos) && (line3.find(character) != std::string::npos) && (alreadyUsed.find(character) == std::string::npos))
			{
				if (isupper(character))
				{
					answer2 += character - 38;
				}
				else if (islower(character))
				{
					answer2 += character - 96;
				}
				alreadyUsed.push_back(character);
			}
		}
		alreadyUsed.clear();
	}

	std::cout << "Answer 1: " << answer1 << std::endl;
	std::cout << "Answer 2: " << answer2 << std::endl;
	return 0;
}
