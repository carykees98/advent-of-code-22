#include <iostream>
#include <vector>
#include <fstream>

int main(int argc, char const *argv[])
{
	std::ifstream infile("./day2.txt");
	char elfPlay, myPlay;
	int answer1 = 0;
	int answer2 = 0;

	while (infile >> elfPlay >> myPlay)
	{
		if (elfPlay == 'A')
		{
			if (myPlay == 'Y')
				answer1 += (6 + 2);
			else if (myPlay == 'X')
				answer1 += (3 + 1);
			else if (myPlay == 'Z')
				answer1 += (0 + 3);

			if (myPlay == 'X')
				answer2 += 3 + 0;
			else if (myPlay == 'Y')
				answer2 += 1 + 3;
			else if (myPlay == 'Z')
				answer2 += 2 + 6;
		}
		else if (elfPlay == 'B')
		{
			if (myPlay == 'X')
				answer1 += (0 + 1);
			else if (myPlay == 'Y')
				answer1 += (3 + 2);
			else if (myPlay == 'Z')
				answer1 += (6 + 3);

			if (myPlay == 'X')
				answer2 += 1 + 0;
			else if (myPlay == 'Y')
				answer2 += 2 + 3;
			else if (myPlay == 'Z')
				answer2 += 3 + 6;
		}
		else if (elfPlay == 'C')
		{
			if (myPlay == 'Z')
				answer1 += (3 + 3);
			else if (myPlay == 'X')
				answer1 += (6 + 1);
			else if (myPlay == 'Y')
				answer1 += (0 + 2);

			if (myPlay == 'X')
				answer2 += 2 + 0;
			else if (myPlay == 'Y')
				answer2 += 3 + 3;
			else if (myPlay == 'Z')
				answer2 += 1 + 6;
		}
	}
	std::cout << "Answer 1: " << answer1 << std::endl;
	std::cout << "Answer 2: " << answer2 << std::endl;
	return 0;
}
