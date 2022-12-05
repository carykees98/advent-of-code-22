#include "../aoc-utils/aocIncludes.h"
#include <limits>

int main(int argc, char const *argv[])
{
	// Open File
	std::string fileName(__FILE_NAME__);
	fileName.replace(fileName.end() - 3, fileName.end(), "txt");
	std::ifstream infile(fileName);

	// Variable declarations
	std::string answer1, answer2;
	std::vector<std::string> crates;
	std::string nullify;
	int howMany, from, to;

	crates.resize(9);

	crates[0] = "ZJNWPS";
	crates[1] = "GST";
	crates[2] = "VQRLH";
	crates[3] = "VSTD";
	crates[4] = "QZTDBMJ";
	crates[5] = "MWTJDCZL";
	crates[6] = "LPMWGTJ";
	crates[7] = "NGMTBFQH";
	crates[8] = "RDGCPBQW";

	// Solution
	for (size_t i = 0; i < 10; i++)
	{
		infile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	while (infile >> nullify >> howMany >> nullify >> from >> nullify >> to)
	{
		to--;
		from--;

		for (size_t i = 0; i < howMany; i++)
		{
			crates[to].push_back(crates[from][crates[from].size() - 1]);
			crates[from].pop_back();
		}
	}

	for (size_t i = 0; i < 9; i++)
	{
		answer1 += crates[i][crates[i].size() - 1];
	}

	crates[0] = "ZJNWPS";
	crates[1] = "GST";
	crates[2] = "VQRLH";
	crates[3] = "VSTD";
	crates[4] = "QZTDBMJ";
	crates[5] = "MWTJDCZL";
	crates[6] = "LPMWGTJ";
	crates[7] = "NGMTBFQH";
	crates[8] = "RDGCPBQW";

	infile.close();
	infile.open(fileName);

	for (size_t i = 0; i < 10; i++)
	{
		infile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	while (infile >> nullify >> howMany >> nullify >> from >> nullify >> to)
	{
		to--;
		from--;

		int crateSize = crates[from].size();

		crates[to] += crates[from].substr(crateSize - howMany, crateSize);

		for (size_t i = 0; i < howMany; i++)
		{
			crates[from].pop_back();
		}
	}

	for (size_t i = 0; i < 9; i++)
	{
		answer2 += crates[i][crates[i].size() - 1];
	}

	// Print Answer
	std::cout << "Answer 1: " << answer1 << std::endl
			  << "Answer 2: " << answer2 << std::endl;

	return 0;
}
