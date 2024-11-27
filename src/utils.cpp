#include "utils.h"

#include <iostream>
#include <sstream>

void getWordsFromFile(std::ifstream& file, std::vector<std::vector<std::string>>& words)
{
	// check if the file is open
	if (!file.is_open())
	{
		std::cerr << "File is not openned.";
		return;
	}

	// read all words
	char end_of_sentence{ '.' };
	std::string line;
	std::vector<std::string> sentence;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string word;
		while (ss >> word)
		{
			sentence.push_back(word);

			if (*word.rbegin() == end_of_sentence)
			{
				words.push_back(sentence);
				sentence.clear();
			}
		}
	}
}