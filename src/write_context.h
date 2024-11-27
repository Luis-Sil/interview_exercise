#pragma once
#include <string>
#include <fstream>
#include <list>

#include "WordPosition.h"

/**
 * @brief Reads word positions from a file and stores them in a list.
 *
 * This function reads lines from a given file, constructs WordPosition objects from these lines,
 * and stores them in a list. A line is defined as a sequence of characters separated by newline characters.
 *
 * @param file_path A string representing the path to the file from which the word positions will be read.
 * @return A list of WordPosition objects constructed from the lines in the file.
 *
 * @note The function tries to open the file before attempting to read from it.
 * If the file cannot be opened, an error message is printed to the standard error stream and the function returns an empty list.
 * If the file can be opened, the function reads all lines from the file.
 * For each line, it constructs a WordPosition object and adds it to the list.
 * After all lines have been read, the function closes the file and returns the list.
 */
std::list<WordPosition> readPositions(const std::string& file_path);

/**
 * @brief Writes the context of words in a file.
 *
 * This function takes a list of word positions and a file, and writes the context of each word in the file.
 * The context of a word is defined as the span of words before and after the word in its sentence.
 * The word itself is highlighted.
 *
 * @param positions A list of WordPosition objects. Each WordPosition object represents the position of a word in the file.
 * @param file An input file stream object representing the file to read from.
 *
 * @note The function assumes that the WordPosition objects in the list 'positions' are sorted.
 * If they are not sorted, the function sorts them.
 *
 * @warning If the file is not open, the function prints an error message and returns.
 */
void writeContext(std::list<WordPosition>& positions, std::ifstream& file);