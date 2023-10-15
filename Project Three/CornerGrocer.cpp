/* 
* Corner Grocer: 
* This program reads in a file of items, and creates a map of the frequency of each item.
* The user can then select from a menu to display the frequency of a specific item,
* display the frequency of all items, or display the frequency of all items as a histogram.
* The program also saves a backup file of the map contents.
*
* Author: Danforth Morrigan
* Date: 2023-10-14
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

class CornerGrocer {
public:
	// Public functions
	CornerGrocer();
	void displayItem();
	void displayFrequency();
	void displayHistogram();
	int displayMenu();
private:
	// Declare file constants for futureproofing
	const string INPUT_FILE = "CS210_Project_Three_Input_File.txt";
	const string OUTPUT_FILE = "frequency.dat";
	// Internal variables
	string item;
	map<string, int> frequencyMap;
	// Internal functions
	void readRawData();
	void saveAnalyzedData();
};

CornerGrocer::CornerGrocer() {
	// Constructor calls functions to read in data and save analyzed data
	readRawData();
	saveAnalyzedData();
}

void CornerGrocer::displayItem() {
	// Prompt user for item, if item exists, display frequency - else display error and return to menu
	string userInput;
	cout << "Enter item: ";
	cin >> userInput;
	if (frequencyMap.find(userInput) != frequencyMap.end()) {
		cout << userInput << " appears " << frequencyMap[userInput] << " times." << endl;
	}
	else {
		cout << "Item not found." << endl;
	}
}

void CornerGrocer::displayFrequency() {
	// Display entire frequency map
	for (auto& item : frequencyMap) {
		cout << item.first << " " << item.second << endl;
	}
}

void CornerGrocer::displayHistogram() {
	// Display frequency of all items as histogram
	for (auto& item : frequencyMap) {
		cout << item.first << " ";
		for (int i = 0; i < item.second; i++) {
			cout << "*";
		}
		// Alternative method could be to use setw() and setfill() to format output
		// cout << setw(item.second) << setfill('*') << " ";
		cout << endl;
	}
}

int CornerGrocer::displayMenu() {
	// Display menu allowing user to select from options
	// Validate input to only accept integers
	// Return integer representing selection
	string userInput;
	int selection = 0;
	cout << "*** Corner Grocer ***" << endl;
	cout << "1. Search for frequency of item" << endl;
	cout << "2. Display frequency of all items" << endl;
	cout << "3. Display frequency of all items as histogram" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter selection: ";
	cin >> userInput;
	try {
		// Requires C++11 or later
		// stoi() throws exception if string cannot be converted to integer
		selection = stoi(userInput);
	}
	catch (...) {
		// Catches all exceptions, because any exception means invalid input
		cout << "Invalid selection." << endl;
	}
	return selection;
}

void CornerGrocer::readRawData() {
	// Open input file, read in data, and populate frequency map
	ifstream input;
	input.open(INPUT_FILE);
	if (!input.is_open()) {
		cout << "Error opening input." << endl;
		return;
	}
	while (!input.eof()) {
		input >> item;
		frequencyMap[item]++;
	}
	input.close();
}

void CornerGrocer::saveAnalyzedData() {
	// Save backup file of map contents
	ofstream output;
	output.open(OUTPUT_FILE);
	if (!output.is_open()) {
		cout << "Error opening output." << endl;
		return;
	}
	for (auto& item : frequencyMap) {
		output << item.first << " " << item.second << endl;
	}
	output.close();
}

int main() {
	// Create CornerGrocer object
	CornerGrocer cornerGrocer = CornerGrocer();
	// Start loop that runs until user selects exit
	int menuOption = 0;
	while (menuOption == 0) {
		menuOption = cornerGrocer.displayMenu();
		switch (menuOption) {
		case 1:
			cornerGrocer.displayItem();
			menuOption = 0;
			break;
		case 2:
			cornerGrocer.displayFrequency();
			menuOption = 0;
			break;
		case 3:
			cornerGrocer.displayHistogram();
			menuOption = 0;
			break;
		case 4:
			cout << "Exiting..." << endl;
			system("pause");
			return 0;
		default:
			menuOption = 0;
		}
		// Pause and clear screen before next loop
		system("pause");
		system("cls||clear");
	}
	return 0;
}