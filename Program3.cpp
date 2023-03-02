/////////////////////////////////////////////////////////////////////////////////////////////////////
//Name: Eddie G. Pineda																			   //
//Date: 10/22/2022																				   //
//Program Statement: Write a program that parses through a text file and prints out the frequency  //
//                   of each letter of the English alphabet in it.                                 //
//                      *Use an integer array of size 128.                                         //
//                      *Use the ASCII values of letters to index into the array.                  //
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <fstream> //Library used to read the text file
using namespace std;

int main() {
	int alphabetArr[128]; //integer array of size 128
	string fileName; //Stores the name of the file the user wants to open
	char currChar; //Stores the current character
	cout << "Please enter the name of the file in the format 'FileName.txt': " << flush;
	cin >> fileName; //Stores the input of the user for the name of the file

	ifstream inFile; //Input file stream inFile
	inFile.open(fileName); //Opens the text file to read from it

	for (int i = 0; i < 128; i++) { //For loop parses through the array to clear every counter
		alphabetArr[i] = 0; //Clears the current i value in the array
	}

	while (inFile >> currChar) { //While loop parses through every character in the text file
		alphabetArr[int(currChar)]++; //Adds one to the counter of the current character
	}

	cout << "Frequencies of each letter of the English alphabet present in the file :" << endl;
	for (int i = 65; i < 91; i++) { //Parses through every letter in the alphabet once
		cout << char(i) << ": " << alphabetArr[i] << "\t" << char(i + 32) << ": " << alphabetArr[i + 32] << "\t" << "Total: " << alphabetArr[i + 32] + alphabetArr[i] << endl;
	}

	inFile.close(); //Closes the file
	return 0;
}