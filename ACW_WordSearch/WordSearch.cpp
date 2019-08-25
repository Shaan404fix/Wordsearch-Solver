#include "WordSearch.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

WordSearch::WordSearch(const char * const filename) {

}

WordSearch::~WordSearch() {

}

void WordSearch::ReadSimplePuzzle() {

	ifstream inRead;
	inRead.open(puzzleName);
	char letter;
	if (!inRead) {
		cout << "Error!, Unable to open " << dictionaryName << endl;
	}
	inRead >> gridsize;
	for (int i = 0; i < gridsize * gridsize; i++) {
		inRead >> letter;
		puzzleRead.push_back(letter);
	}
	inRead.close();

	grid = new int*[gridsize];
	for (gridi = 0; gridi < gridsize; gridi++) {
		grid[gridi] = new int[gridsize];
	}

	int fromRead = 0;

	for (int i = 0; i < gridsize; i++) {

		for (int j = 0; j < gridsize; j++) {

			grid[i][j] = puzzleRead[fromRead];
			fromRead++;

		}

	}


	char val;

	for (int i = 0; i < gridsize; i++) {

		for (int j = 0; j < gridsize; j++) {

			val = grid[i][j];
			cout << val;			

		}

		cout << endl;
	}

}

void WordSearch::ReadSimpleDictionary() {
	ifstream inRead;
	std:: string datain;
	inRead.open(dictionaryName);
	if (!inRead) {
		cout << "Error!, Unable to open " << dictionaryName << endl;
	}
	
	while (std::getline(inRead, datain))
	{		
		dictionaryRead.push_back(datain);		
	}
	inRead.close();

	int similarWordsSize = 0;
	for (int i = 0; i < dictionaryRead.size(); i++) {

		for (int j = 0; j < dictionaryRead.size(); j++) {

			if (i != j) {

				if (dictionaryRead[i].find(dictionaryRead[j])) {

					similarWordsTemp.push_back(dictionaryRead[j]);
					similarWordsTemp.push_back(dictionaryRead[i]);
					similarWordsSize++;
					
				}
			}
		}
	}

}

void WordSearch::ReadAdvancedPuzzle() {
}

void WordSearch::ReadAdvancedDictionary() {
}

void WordSearch::SolvePuzzleSimple() {
	
	string stringToTest;	
	int Wordlength;
	cellsVisited = 0;
	DictionaryVisited = 0;

	for (int dIndex = 0; dIndex < dictionaryRead.size(); dIndex++) 
	{
		stringToTest = dictionaryRead[dIndex];
		DictionaryVisited++;
		for (int i = 0; i < gridsize; i++) 
		{
			for (int j = 0; j < gridsize; j++) 
			{	
				cellsVisited++;
				if (grid[i][j] == stringToTest[0]) 
				{
					Wordlength = stringToTest.size();
					
					for (int direction = 0; direction < 8; direction++) 
					{
						int iMov = i , jMov = j ;
						int gridLetter;

						for (gridLetter = 0; gridLetter < Wordlength; gridLetter++) 
						{
							if (iMov < 0 || iMov >= gridsize || jMov < 0 || jMov >= gridsize) 
							{
								break;
							}
							cellsVisited++;							
							if (grid[iMov][jMov] != stringToTest[gridLetter]) 
							{
								break;
							}							

							if (gridLetter == Wordlength - 1)
							{
								found++;								
								cout << "Found " << stringToTest << " from position " << j << "," << i << " to " << jMov << "," << iMov << endl;

								foundList.push_back(stringToTest);
								foundList.push_back(to_string(j));
								foundList.push_back(to_string(i));
								
								break;
							}
							iMov += y[direction], jMov += x[direction];
						}

						if (gridLetter == Wordlength - 1)
						{							
							break;
						}
					}
				}
			}
		}
	}	
}

void WordSearch::SolvePuzzleAdvanced() {
}

void WordSearch::WriteResults(const double loadTime, const double solveTime) const {

	bool foundItem = false;
	vector<string> notFound;

	ofstream file;
	file.open("test.txt");
	file << "NUMBER_OF_WORDS_MATCHED " << found << endl;
	file << endl;
	file << "WORDS_MATCHED_IN_GRID" << endl;

	for (int i = 0; i < foundList.size(); i+=3) 
	{		
		file << foundList[i + 1] << " ";
		file << foundList[i + 2] << " ";
		file << foundList[i] << endl;
	}
	file << endl;
	file << "WORDS_UNMATCHED_IN_GRID" << endl;
	for (int i = 0; i < dictionaryRead.size(); i++)
	{
		foundItem = false;
		for (int c = 0; c < foundList.size(); c += 3)
		{
			if (dictionaryRead[i] == foundList[c])
			{
				foundItem = true;
				break;
			}
		}
		if (foundItem == false)
		{
			notFound.push_back(dictionaryRead[i]);
		}
	}
	for (int i = 0; i < notFound.size(); i++) 
	{
		file << notFound[i] << endl;
	}
	file << endl;
	file << "NUMBER_OF_GRID_CELLS_VISITED " << cellsVisited << endl;
	file << endl;
	file << "NUMBER_OF_DICTIONARY_ENTRIES_VISITED " << DictionaryVisited << endl;
	file << endl;
	file << "TIME_TO_POPULATE_GRID_STRUCTURE " << loadTime << endl;
	file << endl;
	file << "TIME_TO_SOLVE_PUZZLE " << solveTime << endl;
}