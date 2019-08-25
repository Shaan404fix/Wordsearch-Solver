#include <iostream>
#include <fstream>
using namespace std;


#include "WordSearch.h"
#include "ACW_Wrapper.h"

int main(int, char **) {

	ACW_Wrapper wrapper("log.txt");
	
	// Test simple algorithm
	{
		WordSearch ws("output_simple.txt");

		wrapper.startTimer();
		ws.ReadSimplePuzzle();
		ws.ReadSimpleDictionary();
		const double loadTime = wrapper.stopTimer();

		wrapper.startTimer();
		ws.SolvePuzzleSimple();
		const double solveTime = wrapper.stopTimer();

		ws.WriteResults(loadTime, solveTime);
	}
	
	// Test advanced algorithm
	{
		WordSearch ws("output_advanced.txt");

		wrapper.startTimer();
		ws.ReadAdvancedPuzzle();
		ws.ReadAdvancedDictionary();
		const double loadTime = wrapper.stopTimer();

		wrapper.startTimer();
		ws.SolvePuzzleAdvanced();
		const double solveTime = wrapper.stopTimer();

		ws.WriteResults(loadTime, solveTime);
	}
	system("PAUSE");
	return 0;
}