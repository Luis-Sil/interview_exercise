#include "write_context.h"
#include "utils.h"

#include <iostream>
#include <algorithm>
#include <vector>

std::list<WordPosition> readPositions(const std::string& file_path)
{
	// try to open the file
	std::ifstream file(file_path);
	if (!file.is_open()) {
		std::cerr << "Unable to open file." << std::endl;
		return std::list<WordPosition>();
	}

	// generate all positions from the file
	std::list<WordPosition> positions;
	std::string line;
	while (std::getline(file, line))
		positions.push_back(WordPosition(line));

	// close file
	file.close();

	return positions;
}

void writeContext(std::list<WordPosition>& positions, std::ifstream& file)
{
	// sort positions (if not sorted)
	positions.sort();

	// if the file is not in the open
	if (!file.is_open())
	{
		std::cerr << "File is not open.";
		return;
	}

	// fetch all words from the document
	std::vector<std::vector<std::string>> all_words;
	getWordsFromFile(file, all_words);

	// make all positions relative to the begin of its respective sentence
	auto current_sentence = all_words.begin();
	int current_length{};

	for (auto& pos : positions)
	{
		if (pos.getStartPosition() > static_cast<int>(current_sentence->size()) - 1)
		{
			current_length += static_cast<int>(current_sentence->size());
			std::advance(current_sentence, 1);
		}

		pos.setStartPosition(pos.getStartPosition() - current_length);
	}

	int begin{}, contextSpan{ 5 };
	auto pos_begin = positions.begin();
	const std::string begin_bold("<b>"), end_bold("</b>"), space(" "), delimit_context("...");
	char sentence_end{ '.' };
	bool end_of_positions{ false };

	// for each sentence
	for (auto& sentence : all_words)
	{
		for (auto pos = pos_begin; pos != positions.end(); ++pos)
		{
			// get next position as well
			auto next_pos = std::next(pos);

			// print context before
			for (int i = std::max(begin, pos->getStartPosition() - contextSpan); i < pos->getStartPosition(); i++)
			{
				std::cout << sentence[i] << space;
			}

			// print highlight
			int end_highlight{};

			if ((next_pos != positions.end()) && (next_pos->getStartPosition() > pos->getStartPosition()))
				end_highlight = std::min(pos->getStartPosition() + pos->getSpan(), next_pos->getStartPosition());
			else
				end_highlight = std::min(pos->getStartPosition() + pos->getSpan(), static_cast<int>(sentence.size()));

			// highlight position
			std::cout << begin_bold;
			for (int i = pos->getStartPosition(); i < end_highlight - 1; i++)
			{
				std::cout << sentence[i] << space;
			}

			// if it is the end of a sentence
			if (*sentence[end_highlight - 1].rbegin() == sentence_end)
			{
				auto last_word = sentence[end_highlight - 1];
				std::cout << std::string(last_word.begin(), std::prev(last_word.end())) << end_bold << sentence_end << space;
			}
			else
			{
				std::cout << sentence[end_highlight - 1] << end_bold << space;
			}

			// update begin
			begin = end_highlight;

			// print context after
			int end_context{};
			int next_context{};
			if ((next_pos != positions.end()) && (next_pos->getStartPosition() > pos->getStartPosition()))
			{
				end_context = std::min(begin + contextSpan, next_pos->getStartPosition());
				next_context = next_pos->getStartPosition();
			}
			else
			{
				end_context = std::min(begin + contextSpan, static_cast<int>(sentence.size()));
				next_context = static_cast<int>(sentence.size());
			}
			
			// print context
			for (int i = begin; i < end_context; i++)
				std::cout << sentence[i] << space;

			// add context limit if the context was spanned the whole way.
			if ((end_context == begin + contextSpan) && (next_context > end_context))
				std::cout << delimit_context << space;

			begin = end_context;

			// move to the next sentence
			if (begin >= static_cast<int>(sentence.size()))
			{
				pos_begin = next_pos; // update position_begin
				if (pos_begin == positions.end())
					end_of_positions = true;

				begin = 0; // reset begin
				break;
			}
		}
	}
}