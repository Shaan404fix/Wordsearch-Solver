#pragma once
#include <string>
#include <list>
#include <vector>
using namespace std;

class WordSearch {
	const char* puzzleName = "wordsearch_grid.txt";
	const char* dictionaryName = "dictionary.txt";
	
	string outputFileName;
	vector<string> dictionaryRead;
	vector<string> wordsFound;
	vector<char> puzzleRead;
	int gridsize;
	int** grid;
	int gridi;
	vector<string> similarWordsTemp;
	int** similarWords;
	int similarWordsi;
	int found = 0;
	vector<string> foundList;
	int y[8] = { -1, -1, 0, 1, 1, 1, 0, -1 }, x[8] = { 0, 1, 1, 1, 0, -1, - 1, -1 };
	int cellsVisited = 0;
	int DictionaryVisited = 0;

public:
	explicit WordSearch(const char * const filename);
	~WordSearch();
	
	void ReadSimplePuzzle();
	void ReadSimpleDictionary();
	void ReadAdvancedPuzzle();
	void ReadAdvancedDictionary();
	void SolvePuzzleSimple();
	void SolvePuzzleAdvanced();
	void WriteResults(const	double loadTime, const double solveTime) const;

};

