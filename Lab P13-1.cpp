#include<iostream>
#include<iomanip>
#include<cctype>
#include<string>
#include<fstream>

using namespace std;

//functions
void pressEnterToContinue(void);

int main() {
	unsigned long int numLetters = 0;
	unsigned long int letter[26];
	char ch;
	double frequency;
	int letterIndex;
	ifstream inputStream;
	string filename;

	//initialize letter array
	for (int i = 0; i < 26; i++) {
		letter[i] = 0;
	}

	//open and validate file
	cout << "Enter filename: ";
	getline(cin, filename);
	inputStream.open(filename);
	if (!inputStream.is_open()) {
		cout << "Sorry - file cannot be opened. ";
		return 1;
	}

	//read from file
	while (true) {
		inputStream.get(ch);
		if (inputStream.eof()) {
			break;
		}
		//calculate array index
		if (isalpha(ch)) {
			numLetters++;
			ch = toupper(ch);
			letterIndex = (int)ch - (int)'A';
			letter[letterIndex]++;
		}
	}

	//close file
	inputStream.close();

	//display
	cout << "\nTotal number of letters: " << numLetters << endl;
	cout << "Frequency:\n";

	cout << fixed << setprecision(3);

	for (letterIndex = 0; letterIndex < 26; letterIndex++) {
		ch = (char)((int)'A' + letterIndex);
		frequency = 100.0 * (double)letter[letterIndex] / (double)numLetters;
		cout << "'" << ch << "': " << frequency << endl;
	}
	pressEnterToContinue();
	return 0;


}


//functions
void pressEnterToContinue(void) {
	char c;
	cout << "Press Enter to Continue...";
	cin.ignore(1024, '\n');

	do { cin.get(c); } while (c != '\n' && c != EOF);
	return;
}