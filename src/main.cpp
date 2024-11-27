#include <filesystem>
#include <iostream>
#include "write_context.h"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Must provide positions.txt and document.tx" << std::endl;
		return 0;
	}

	// get file names: argv[0] is the program name
	std::string position_file(argv[1]), document_file(argv[2]);

	std::filesystem::path current_path = std::filesystem::current_path();
	auto doc_file_path = current_path / document_file;
	auto positions_file_path = current_path / position_file;

	// get positions
	auto positions = readPositions(positions_file_path.string());

	// open doc
	std::ifstream file(doc_file_path.string());
	std::cout << std::endl;
	writeContext(positions, file);
	std::cout << std::endl;
	
	return 0;
}