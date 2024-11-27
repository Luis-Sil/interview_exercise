#pragma once
#include <fstream>
#include <string>
#include <vector>

/**
 * @brief Reads all words from a file and stores them in a vector.
 *
 * This function reads all words from a given file and stores them in a vector.
 *
 * @param file An input file stream that is connected to the file from which the words will be read.
 * @param words A reference to a vector of strings where the words will be stored.
 *
 * @note The function checks if the file is open before attempting to read from it.
 * If the file is not open, an error message is printed to the standard error stream and the function returns immediately.
 * If the file is open, the function reads all lines from the file.
 * For each line, it uses a string stream to split the line into words (separated by whitespace) and adds each word to the vector.
 */
void getWordsFromFile(std::ifstream& file, std::vector<std::vector<std::string>>& words);