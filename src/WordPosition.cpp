#include "WordPosition.h"
#include <fstream>
#include <sstream>

WordPosition::WordPosition(const std::string& position)
{
	// put the string to a stream
	std::stringstream istream(position);
	char delimeter;

	// position is assumed to be a string with the following format: "n <any char> m"
	// where n and m must be streamable to integers. It does not matter if there are white
	// space between the numbers and delimiter.
	istream >> start_position;
	istream >> delimeter; //any char
	istream >> span;
}

int WordPosition::getStartPosition() const
{
	return start_position;
}

int WordPosition::getSpan() const
{
	return span;
}

void WordPosition::setStartPosition(int _start_position)
{
	start_position = _start_position;
}

bool WordPosition::operator<(const WordPosition& rhs) const
{
	return start_position < rhs.start_position;
}

