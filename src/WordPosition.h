#pragma once
#include <string>

/**
 * @class WordPosition
 * @brief A class to represent the position of a highlighted word in a text.
 *
 * This class stores the start position and span (length) of the highlighted word in a text.
 * It provides getters for these properties and overloads the less than operator for comparison.
 */
class WordPosition
{
private:
	// The start position of the word in the text.
	int start_position;
	// The span (length) of the word.
	int span;

public:
	/**
	 * @brief Constructs a new WordPosition object.
	 *
	 * @param str A string from which the WordPosition object will be constructed.
	 */
	WordPosition(const std::string&);

	/**
	 * @brief Gets the start position of the word.
	 *
	 * @return The start position of the word.
	 */
	int getStartPosition() const;

	/**
	 * @brief Gets the span (length) of the word.
	 *
	 * @return The span (length) of the word.
	 */
	int getSpan() const;

	/**
	* @brief Sets the start position of the word.
	*
	* @param int An integer containing the new start position.
	*/
	void setStartPosition(int);

	/**
	 * @brief Overloads the less than operator for comparison of WordPosition objects.
	 *
	 * @param rhs The WordPosition object on the right-hand side of the operator.
	 * @return true if the current object is less than rhs, false otherwise.
	 */
	bool operator<(const WordPosition& rhs) const;

};