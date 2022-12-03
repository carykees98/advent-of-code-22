#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

int main(int argc, char const *argv[])
{
	int dayNumber;
	std::cout << "Which day are you on?" << std::endl
			  << ">>> ";
	std::cin >> dayNumber;

	std::string day = "day" + std::to_string(dayNumber);

	// Create new folder
	fs::create_directory(day);

	// Copy template
	fs::copy_file(fs::relative("./aoc-utils/template.cpp"), fs::relative("./" + day + "/" + day + ".cpp"));

	// Make text file
	std::ofstream txtFile("./" + day + "/" + day + ".txt");

	return 0;
}
