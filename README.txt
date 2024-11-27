Problem Review:

----------------------------------------------------------------------------------
The task at hand involves implementing a function in C++ that accepts two inputs:
----------------------------------------------------------------------------------
- A text document.

- A document containing a set of word positions.

-------------------------------------------------
The function aims to achieve two main objectives:
-------------------------------------------------
- Highlight the words, defined by their positions, in HTML using <b> and </b> tags. The span of words to be highlighted can also be specified.

- Provide a context of up to 5 words on either side of the highlighted word.

-------------------------
Key requirements include:
------------------------

- The context of a word must be confined to the same sentence, where a sentence is defined as a group of words bounded by the ‘.’ character. 
This implies that not only the word at the given position but also the subsequent span of words would be highlighted.

- The context should be symmetric with respect to the highlighted word (including the span).

-------------------------------------------------------------------------------------------
Certain assumptions were made to address aspects not explicitly stated in the requirements:
-------------------------------------------------------------------------------------------

- The span of the highlight was presumed to extend forward, implying that the highlighted words would start at the given position and end at the position plus the span.

- If two consecutive words are to be highlighted, each word will be highlighted separately.

- If the context of a highlighted word overlaps with the context of the following highlighted words, these contexts are merged and no ‘…’ is added to indicate omitted text.

----------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------
Instructions for Using the “write_context” Application:
-------------------------------------------------------

- Store your data files (positions and document) in the data folder.

- Run the application from the bin directory. When launching the application, provide the relative paths to your data files (which are located in the data folder) as input arguments. Please note that these arguments are mandatory; the application will return an error if they are not provided.
The application will print the output to the console.

Please ensure that the data files are correctly placed and the paths are accurately provided to avoid any errors.